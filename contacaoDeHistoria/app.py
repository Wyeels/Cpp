from flask import Flask, render_template, request, redirect, url_for, flash
import sqlite3
import re

app = Flask(__name__)
app.secret_key = 'Wes123ley'

def conectar_db():
    conectar = sqlite3.connect('notas.db')
    return conectar

def criar_tabela():
    conectar = conectar_db()
    cursor = conectar.cursor()
    cursor.execute('''
        CREATE TABLE IF NOT EXISTS notas (
            turma TEXT NOT NULL,
            nome TEXT NOT NULL,
            nota INTEGER
        )
    ''')
    conectar.commit()
    conectar.close()


@app.route('/')
def index():
    return render_template('index.html')

@app.route('/cadastro', methods=['POST'])
def adicionar_nota():
    if request.method == 'POST':
        turma = request.form['turma']
        nome = request.form['nome']
        nota = request.form['nota']

    conectar = conectar_db()
    cursor = conectar.cursor()
    cursor.execute(
        'INSERT INTO notas (turma, nome, nota) VALUES (?, ?, ?)', (turma, nome, nota) 
    )
    conectar.commit()
    conectar.close()
    return redirect(url_for('index'))

# @app.route('/teste')


if __name__ == '__main__':
    criar_tabela()
    app.run(debug=True, host="0.0.0.0", port=5000)