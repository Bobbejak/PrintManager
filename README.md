# PrintInterceptor

PrintInterceptor is a Java application designed to intercept and manage print jobs in a Windows environment. It allows for user authentication before proceeding with print jobs, providing a layer of control and security for shared printing resources.

## Features

- Monitors all print queues on the system
- Intercepts and pauses new print jobs
- Requires user authentication to proceed with printing
- Ability to resume or cancel print jobs based on authentication result
- Simple GUI to indicate the program is running and view logs

## Requirements

- Windows operating system
- Java Development Kit (JDK) 8 or higher
- Administrator privileges (for managing print jobs)

## Installation

1. Ensure you have Java installed on your system.
2. Download the latest release of PrintInterceptor from the releases page.
3. Run the `install.bat` file as an administrator. This will:
   - Create a program directory in Program Files
   - Copy the necessary files
   - Create a desktop shortcut

## Usage

1. Double-click the "Print Interceptor" shortcut on your desktop to start the application.
2. The application will run in the background, monitoring all print queues.
3. When a new print job is detected, a login prompt will appear.
4. Enter your username and password to authenticate.
5. If authentication is successful, the print job will proceed. Otherwise, it will be cancelled.

## Configuration

You can modify the `print_interceptor.properties` file in the installation directory to change settings such as:

- Default username and password
- Monitoring interval
- Maximum number of concurrent jobs
- Log level

## Troubleshooting

If you encounter any issues:

1. Check the application logs in the `print_interceptor.log` file in the installation directory.
2. Ensure you're running the application with administrator privileges.
3. Verify that your Java installation is up to date.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## License

This project is licensed under the MIT License.