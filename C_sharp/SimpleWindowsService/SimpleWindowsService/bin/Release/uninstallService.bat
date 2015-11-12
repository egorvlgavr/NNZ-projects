@ECHO OFF
 
echo Installing WindowsService...
echo ---------------------------------------------------
C:\WINDOWS\Microsoft.NET\Framework\v4.0.30319\InstallUtil /u "%~dp0SimpleWindowsService.exe"
echo ---------------------------------------------------
echo Done.
services.msc
pause