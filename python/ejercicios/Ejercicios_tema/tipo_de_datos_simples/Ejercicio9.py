# -*- coding: utf-8 -*-
"""
Created on Fri Oct 17 15:31:02 2025

@author: alesa
"""

"""Modulo 1, Problema 9: Inversion con retorn anual"""


amount_invest = float(input('¿Cuánto quiere invertir en doláres? '))
annual_interest = float(input('¿Con cuánto porcentaje de interes anual? '))
years_in_invest = int(input('¿Cuantos años durará inversión? '))
money_gained = amount_invest * (annual_interest/100 + 1) ** years_in_invest


print(f'''El dinero ganado de su inversión con un monto inicial de {amount_invest}$
con un rendimiento anual de {annual_interest}% es: {money_gained:.2f}$''')
