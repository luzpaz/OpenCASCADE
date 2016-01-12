@echo off

if "%1" == "-h" (
  goto err_bat
)

if not ["%4"] == [""] (
  set "SampleName=%4"
  call "%~dp0env.bat" %1 %2 %3
) else if not ["%1"] == [""] (
  set "SampleName=%1"
  call "%~dp0env.bat"
) else (
  goto err_bat
)

if not exist "%~dp0%BIN_DIR%\IE_%SampleName%.exe" goto err_exe

"%~dp0%BIN_DIR%\IE_%SampleName%.exe"

goto eof

:err_bat
echo Possible names of samples: WinForms, WPF_D3D, WPF_WinForms
echo Launch selected sample as follows:
echo   %~n0.bat [^vc8^|^vc9^|^vc10^|^vc11^|vc12] [^win32^|^win64^] [^Release^|^Debug^] [^SampleName^]
echo or
echo   %~n0.bat [^SampleName^]
echo Run %~n0.bat -h to get this help
exit /B

:err_exe
echo Executable %~dp0%BIN_DIR%\IE_%SampleName%.exe not found.
echo Check that OCCT and sample are built with the selected configuration:
echo compiler=%VCVER% platform=win%ARCH% %3
exit /B

:eof
