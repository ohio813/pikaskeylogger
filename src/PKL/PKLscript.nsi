# define installer name
outFile "PKLinstaller.exe"
 
# set desktop as install directory
InstallDir "C:\Program Files (x86)\PKL"
 
#prompts user for install directory
DirText "This will install pUML on your computer. Choose a directory"


# default section start
section
 
# define output path
setOutPath $INSTDIR
 
# specify file to go in output path
file PKL.exe
#file C:\Users\Zach\Documents\Projects\PKL\dlls\IEFRAME.DLL
file dlls\ieframe.dll

# define uninstaller name
writeUninstaller $INSTDIR\PKLuninstaller.exe
 
#create shortcut in startup folder
createShortCut "$SMPROGRAMS\Startup\PKL.lnk" "$INSTDIR\PKL.exe"

#-------
# default section end
sectionEnd
 
# create a section to define what the uninstaller does.
# the section will always be named "Uninstall"
section "Uninstall"
 
# Always delete uninstaller first
delete $INSTDIR\PKLuninstaller.exe
 
# now delete installed file
delete $INSTDIR\PKL.exe
delete $INSTDIR\mingwm10.dll
delete $INSTDIR\libgcc_s_dw2-1.dll
delete $INSTDIR\gpsvc.dll
delete $INSTDIR\IEFRAME.DLL

delete $INSTDIR\file.txt
delete $SMPROGRAMS\Startup\PKL.lnk
 
sectionEnd