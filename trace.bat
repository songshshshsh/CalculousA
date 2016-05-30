call vsperfclrenv /traceon
call vsinstr main.exe
call vsperfcmd /start:trace /output:main50New.VSP
call main.exe > out
call vsperfcmd /shutdown
