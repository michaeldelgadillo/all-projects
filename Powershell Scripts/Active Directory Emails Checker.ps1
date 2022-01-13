Function Get-FileName($initialDirectory)
{
    [System.Reflection.Assembly]::LoadWithPartialName("System.windows.forms") | Out-Null
    
    $OpenFileDialog = New-Object System.Windows.Forms.OpenFileDialog
    $OpenFileDialog.initialDirectory = $initialDirectory
    #$OpenFileDialog.filter = "excel (*.xlsx)| *.xlsx"
    $OpenFileDialog.ShowDialog() | Out-Null
    $OpenFileDialog.filename
}

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

#List of Values to check for
$CodeType = @('101','111','10Z1','10E','C801')
$Creates = @('101','111')
$Transfers = @('203','204','207','225')
$Charter = @('C101','C301')
$Disables = @('10Z1','10Z6','10E','10B','10C','10H','10G','10M','10N','10S','10J','10L','10O','10Y','10P','14A','14B')
$Position = @('Positions removed from privacy')


# Declare the starting position of each column

for ($i=2; $i -le $rowMax; $i++)
{

    $a = $worksheet.cells.Item($i, 2).text
    $b = Get-ADUser -Filter {EmployeeID -like $a} -properties * | Select-Object SamAccountName,Description,EmployeeID,physicalDeliveryOfficeName,title,enabled,mail
    $c = $worksheet.cells.Item($i, 1).text
    $d = $worksheet.cells.Item($i, 6).text

    if ($c -in $Disables)
    {
        if ($b.mail -notmatch "@polk-fl.net")
        {
            if ($a -eq $b.EmployeeID)
            {
                [pscustomobject][ordered]@{
                CODE = $worksheet.cells.Item($i, 1).text
                STATUS = "EXISTS"
                SAP = $a
                USERNAME = $b.SamAccountName
                OFFICE = $b.physicalDeliveryOfficeName
                AD_TITLE = $b.title
                SAP_TITLE = $worksheet.cells.Item($i, 6).text
                Enabled = $b.enabled
                Notes = $b.Description
                E_mail = $b.mail
                } 
            }
            if ($a -ne $b.EmployeeID)
            {
                [pscustomobject][ordered]@{
                EMP = $b.EmployeeID
                CODE = $worksheet.cells.Item($i, 1).text
                STATUS = "SAP is NOT a match:"
                SAP_TITLE = $worksheet.cells.Item($i, 6).text
                SAP = $a
                Notes = $b.Description
                }
            }
        }
    }
}    

$workbook.SaveAs($xlsx)
$workbook.Close($false)
$objExcel.quit()