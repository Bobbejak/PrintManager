import javax.swing.*;
import java.awt.*;
import java.io.*;

public class PrintInterceptor {
    private static final String WMI_QUERY = 
        "SELECT * FROM __InstanceCreationEvent WITHIN 1 " +
        "WHERE TargetInstance ISA 'Win32_PrintJob'";

    public static void main(String[] args) {
        SwingUtilities.invokeLater(() -> {
            JFrame frame = new JFrame("Print Interceptor");
            frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
            frame.setSize(300, 100);
            frame.setLayout(new FlowLayout());
            frame.add(new JLabel("Print Interceptor is running"));
            frame.setVisible(true);
        });

        try {
            Process process = Runtime.getRuntime().exec(new String[] {
                "powershell.exe",
                "-Command",
                "Register-WmiEvent -Query \"" + WMI_QUERY + "\" -Action {" +
                "   $job = $Event.SourceEventArgs.NewEvent.TargetInstance;" +
                "   $job.Pause();" +
                "   Write-Host $job.JobId,$job.Name" +
                "}"
            });

            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split(",", 2);
                if (parts.length == 2) {
                    String jobId = parts[0];
                    String printerName = parts[1];
                    handlePrintJob(jobId, printerName);
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static void handlePrintJob(String jobId, String printerName) {
        boolean isAuthenticated = showAuthenticationDialog();
        if (isAuthenticated) {
            resumePrintJob(jobId, printerName);
        } else {
            cancelPrintJob(jobId, printerName);
        }
    }

    private static void resumePrintJob(String jobId, String printerName) {
        executeCommand("powershell.exe", "-Command", 
            "(Get-WmiObject Win32_PrintJob | Where-Object {$_.JobId -eq " + jobId + " -and $_.Name -eq '" + printerName + "'}).Resume()");
        System.out.println("Resuming print job " + jobId + " on printer " + printerName);
    }

    private static void cancelPrintJob(String jobId, String printerName) {
        executeCommand("powershell.exe", "-Command", 
            "(Get-WmiObject Win32_PrintJob | Where-Object {$_.JobId -eq " + jobId + " -and $_.Name -eq '" + printerName + "'}).Delete()");
        System.out.println("Cancelling print job " + jobId + " on printer " + printerName);
    }

    private static boolean showAuthenticationDialog() {
        return JOptionPane.showConfirmDialog(null, "Authenticate to allow print job?", "Authentication", JOptionPane.YES_NO_OPTION) == JOptionPane.YES_OPTION;
    }

    private static void executeCommand(String... command) {
        try {
            ProcessBuilder processBuilder = new ProcessBuilder(command);
            Process process = processBuilder.start();
            process.waitFor();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}