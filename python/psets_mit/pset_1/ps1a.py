# Problem set a of 1 MIT

annual_salary = float(input("Cual es tu salario anual?: "))
portion_saved = float(input("Cuanta porcion de tu salario guardas?: "))
total_cost = float(input("Cuanto cuesta la casa?: "))
portion_down_payment = total_cost * 0.25
current_savings = 0.0
r = 0.04

months = 0
while current_savings < portion_down_payment:
    current_savings += ((current_savings * r) / 12) + ((annual_salary / 12) * portion_saved)
    months += 1

print("Total months:", months)

"""Akon version
var float annual_salary = readFloat("Cual es tu salario anual?: ");
var float portion_saved = readFloat("Cuanta porcion de tu salario guardas?: ");
var float total_cost = readFloat("Cuanto cuesta la casa?: ");
let float portion_down_payment = total_cost * 0.25;
var float current_savings = 0;
let float r = 0.04;

var int months = 0;

while current_savings < portion_down_payment
{
    current_savings += ((current_savings * r) / 12) + ((annual_salary / 12) * portion_saved);
    months += 1;
}
"""