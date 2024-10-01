@echo off
echo Installing Print Manager...

REM Check for Java installation
java -version >nul 2>&1
if %errorlevel% neq 0 (
    echo Java is not installed. Please install Java and try again.
    exit /b 1
)

REM Create program directory
if not exist "%ProgramFiles%\PrintManager" mkdir "%ProgramFiles%\PrintManager"

REM Compile the project
call ant compile

REM Copy files
xcopy /E /I /Y classes "%ProgramFiles%\PrintManager\classes"
xcopy /E /I /Y lib "%ProgramFiles%\PrintManager\lib"
copy build.xml "%ProgramFiles%\PrintManager"

REM Create shortcut
powershell -Command "$WshShell = New-Object -comObject WScript.Shell; $Shortcut = $WshShell.CreateShortcut('%UserProfile%\Desktop\Print Manager.lnk'); $Shortcut.TargetPath = 'javaw.exe'; $Shortcut.Arguments = '-cp ""%ProgramFiles%\PrintManager\classes;%ProgramFiles%\PrintManager\lib\*"" Main'; $Shortcut.WorkingDirectory = '%ProgramFiles%\PrintManager'; $Shortcut.Save()"

echo Installation complete. A shortcut has been created on your desktop.
pause