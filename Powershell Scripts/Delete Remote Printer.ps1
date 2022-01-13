#Functions are Delclare in the Beginning because powershell is not a compiled language

#Deletes a printer on the remote computer
Function delPrinter 
{
    $remoteComputer = Read-Host "`nEnter Remote Computer"
    $remotePrinters = Get-printer -ComputerName $remoteComputer
    for ($i=0; $i -le ($remotePrinters.count - 1); $i++){
        Write-Host "($i). $($remotePrinters.name[$i]) - $($remotePrinters.PortName[$i])"
    }
    $choice = Read-Host "`nEnter printer number"
    $Printer = Get-Printer -ComputerName $remoteComputer -Name $remotePrinters.name[$choice]
    Remove-Printer -InputObject $Printer
    Get-printer -ComputerName $remoteComputer
    pause
}

#Retrieves Printers Installed on remote computer and respective ports
Function listPrinter
{
    $remoteComputer = Read-Host "`nEnter Remote Computer"
    Get-printer -ComputerName $remoteComputer
    pause
}

#Lists the Serial Number on a remote computer
Function listSerial
{
    $remoteComputer = Read-Host "`nEnter Remote Computer"
    Get-WmiObject win32_bios -computername $remoteComputer
    pause
}

#Displays the Main Menu & clears the window
Function mainMenu
{
    Clear-Host #Clears the Window to reduce Clutter. Add a # in front of Clear-Host to Disable
    Write-Host "****    Welcome to PowerSuite    ****"
    Write-Host "1. Add Computers to Active Directory"
    Write-Host "2. Delete printers on remote computer"
    Write-Host "3. List printers on remote computer"
    Write-Host "4. Get Serial from remote PC"
    Write-Host "5. Install printer on remote computer"
}

#Pause function allows data to be displayed
Function pause 
{
    Read-Host "Press Enter key to Continue"
}

#Main Menu System 
Do {
    mainMenu
    $getChoice = Read-Host "`nEnter Selection"
    switch($getChoice){
        1 {"";break}
        2 {delPrinter; break}
        3 {listPrinter; break}
        4 {listSerial; break}
    }
} While ($getChoice -ne 9)
