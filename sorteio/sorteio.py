import sqlite3
import random

coneccao = sqlite3.connect("notas.db")
cursor = coneccao.cursor()

cursor.execute("SELECT * FROM notas")
notas = cursor.fetchall()

ganhador = random.choice(notas)

print("O ganhador é ", ganhador)