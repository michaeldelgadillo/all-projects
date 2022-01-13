# Prompts user to Select a file to be processed
Function Get-FileName($initialDirectory)
{
    [System.Reflection.Assembly]::LoadWithPartialName("System.windows.forms") | Out-Null
    
    $OpenFileDialog = New-Object System.Windows.Forms.OpenFileDialog
    $OpenFileDialog.initialDirectory = $initialDirectory
    $OpenFileDialog.ShowDialog() | Out-Null
    $OpenFileDialog.filename
}

# Saves file name into a variable
$xlsx = Get-FileName

# Specify the path to the Excel file and the WorkSheet Name
$FilePath = $xlsx
$SheetName = "Sheet1"

# Create an Object Excel.Application using Com interface
$objExcel = New-Object -ComObject Excel.Application

# Disable the 'visible' property so the document won't open in excel
$objExcel.Visible = $false

# Open the Excel file and save it in $WorkBook
$WorkBook = $objExcel.Workbooks.Open($FilePath)

# Load the WorkSheet 'Sheet1'
$WorkSheet = $WorkBook.sheets.item($SheetName)

# Count the number of Rows
$rowMax = ($worksheet.UsedRange.Rows).count
"Number of rows:" + $rowMax

# Declare the starting position of each column
for ($i=2; $i -le $rowMax; $i++)
{

    $a = $worksheet.cells.Item($i, 1).text
    $b = Get-ADUser -Filter {EmployeeID -like $a} -properties * | Select-Object SamAccountName,Description..."Additional Data Removed for Privacy Reasons"
    $c = $worksheet.cells.Item($i, 1).text
    $d = $worksheet.cells.Item($i, 6).text

    # Set Email to Email Updates Only
    Set-Mailbox -Identity $b -AcceptMessagesOnlyFrom @{add=‘CN=Email Updates,OU=..."Additional Data Removed for Privacy Reasons"’}
        

    [pscustomobject][ordered]@{
        Num = $i
        EMP = $b.EmployeeID
        Office = $b.DeliveryOfficeName
        Hide_Directory = $b.HideFromDirectory
        Hide_Internet = $b.DirectoryHideFromInternet
        Hide_Addressbook = $b.FromAddressLists
        Emails_From =$b.authOrig
        OU_Name = $b.distinguishedName
        Enabled = $b.enabled
        Groups = $b.MemberOf

        }

    if($b.enabled -ne 'Truex')
    {
        Write-Host = "This Person is NOT Disabled"
        $worksheet.Rows($i).interior.colorindex = 6
        $worksheet.cells.Item($i, 12) = "No Action"
    }
 }   

#$workbook.SaveAs($xlsx)
$workbook.Close($false)
$objExcel.quit()