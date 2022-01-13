/************************************************************************
Author: Michael Delgadillo
Teacher: Dennis Hunchuck
Class: COP 1000c
Date: 8 March 2019
Project Name: Redo Payroll
*************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//contains all of the functions used in this program
void displayPaystub(float, float, float, float, float, float, float, float);
float getFederalTax(float);
float getGrossPay(float, float);
float getHourlyWage();
float getHoursWorked();
float getMedicalInsurance(float);
float getNetPay(float, float, float);
float getOverTimePay(float, float);
float getRegularPay(float, float);


int main()
{
    float hourlyWage = getHourlyWage(); //Calls a function to get the hourly wage from user
    float hoursWorked = getHoursWorked(); //Calls a function to get the hours worked from the user
    float regularPay = getRegularPay(hourlyWage, hoursWorked); //takes in the inputs from the user to calculate regular pay
    float overTimePay = getOverTimePay(hourlyWage, hoursWorked); //tkaes in the inputs from the user to calculate overtime if any
    float grossPay = getGrossPay(regularPay, overTimePay); //adds any overtime and regular pay to get the gross pay
    float federalTax = getFederalTax(grossPay); //Calculates the federal tax from the gross pay
    float medicalInsurance = getMedicalInsurance(grossPay); //Calculates the medical insurance from the gross pay
    float netPay = getNetPay(grossPay, federalTax, medicalInsurance); //Calculates the final number after subtracting Fed and Med tax
    displayPaystub(hourlyWage,hoursWorked, regularPay, overTimePay, grossPay, federalTax, medicalInsurance, netPay); //Outputs the information

    return 0;
}

//This function is the last step in the program and it displays all of the information like a paystub
void displayPaystub(float hourlyWage, float hoursWorked, float regularPay, float overTimePay, float grossPay, float federalTax, float medicalInsurance, float netPay)
{
    system("cls");
    printf("*********************************\n");
    printf("*****  PAYSTUB INFORMATION  *****\n");
    printf("*********************************\n");
    printf("Hourly Rate............: $%.2f\n", hourlyWage);
    printf("Hours Worked...........: $%.2f\n", hoursWorked);
    printf("Regular Pay............: $%.2f\n", regularPay);
    printf("OT Pay.................: $%.2f\n", overTimePay);
    printf("Gross Pay..............: $%.2f\n", grossPay);
    printf("Federal Tax (27%%)......: $%.2f\n", federalTax);
    printf("Medical Insurance (14%%): $%.2f\n", medicalInsurance);
    printf("Net Pay................: $%.2f\n", netPay);

}

//Calculates the federal tax from the gross pay at 27%
float getFederalTax(float grossPay)
{
    float federalTax = grossPay * .27;
    return federalTax;
}

//Calculates the gross pay by adding regular pay and overtime
float getGrossPay(float regularPay, float overTimePay)
{
    float grossPay = regularPay + overTimePay;
    return grossPay;
}

//Gets and returns the value of Hourly wage from the user
float getHourlyWage()
{
    float hourlyWage = 0.00;
    printf("Welcome to Payroll.\n");
    printf("Hourly Rate: ");
    scanf("%f", &hourlyWage);
    return hourlyWage;
}

//Gets and returns the value of hours worked from the user
float getHoursWorked()
{
    float hoursWorked = 0.00;
    printf("Hours Worked: ");
    scanf("%f", &hoursWorked);
    return hoursWorked;
}

//Calculates the medical insurance from the gross pay at 14%
float getMedicalInsurance(float grossPay)
{
    float medicalInsurance = grossPay * .14;
    return medicalInsurance;
}

//Calculates the net pay by subtracting fed tax and med tax from gross pay
float getNetPay(float grossPay, float federalTax, float medicalInsurance)
{
    float netPay = grossPay - federalTax - medicalInsurance;
    return netPay;
}

//Calculates overtime by checking if hours worked is greater than 40
float getOverTimePay(float hourlyWage, float hoursWorked)
{
    float overTimePay = 0.00;

    if(hoursWorked > 40)
    {
        overTimePay = (hourlyWage + (hourlyWage / 2)) * (hoursWorked - 40);
    }
    return overTimePay;
}

//Calculates regular pay by multiplying hourly wage and hours worked
float getRegularPay(float hourlyWage, float hoursWorked)
{
    float overage = 0.00, regularPay = 0.00;
    if (hoursWorked > 40)
    {
        overage = hoursWorked - 40;
        regularPay = (hoursWorked - overage) * hourlyWage;
    }
    else
    {
        regularPay = hoursWorked * hourlyWage;
    }

    return regularPay;
}