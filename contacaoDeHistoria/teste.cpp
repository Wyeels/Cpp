#include <windows.h>
#include <sqlext.h>
#include <iostream>
#include "crow_all.h"
using namespace std;

int main() {
    crow::SimpleApp app;

    CROW_ROUTE(app, "/")([](){
        return "<form action='/cadastro' method='post'>"
                "<input type='radio' name='turma' id='iturma'  required>
                <label for='iturma'>3° 'A'</label>
                <input type='radio' name='turma' id='iturma2'  required>
                <label for='iturma'>3° 'B'</label>"
                "<input type='text' name='nome' id='inome'  required>"
                "<label for='inota'>Nota</label>
                <input type='range' name='nota' id='inota' max='10' required>"
                "<input type='submit' value='Avaliar'>"
                "</form>";
    });

    CROW_ROUTE(app, "/cadastro").methods("POST"_method)
    ([](const crow::request& req){
        auto sala = req.url_params.get("sala");
        auto nome = req.url_params.get("nome");
        auto nota = req.url_params.get("nota");

        if (!sala || !nome || !nota)
            return crow::response(400, "Dados incompletos!");

        return crow::response(200, "Usuário cadastrado!");
    });

    app.port(18080).multithreaded().run();

    SQLHENV env;
    SQLHDBC dbc;
    SQLRETURN ret;

    SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void*)SQL_OV_ODBC3, 0);

    SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    SQLWCHAR connStr[] = L"DRIVER={ODBC Driver 17 for SQL Server};SERVER=localhost;DATABASE=notas;UID=sa;PWD=G&pY!8#_tQz4";
    ret = SQLDriverConnectW(dbc, NULL, connStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_NOPROMPT);

    if (SQL_SUCCEEDED(ret)) {
        cout << "Conectado ao SQL Server!" << endl;

        SQLHSTMT stmt;
        SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
        SQLExecDirectA(stmt, (SQLCHAR*)"SELECT sala, nome, nota FROM usuarios;", SQL_NTS);

        char sala[100], nome[100], nota[100];
        while (SQLFetch(stmt) == SQL_SUCCESS) {
            SQLGetData(stmt, 1, SQL_C_CHAR, sala, sizeof(sala), NULL);
            SQLGetData(stmt, 2, SQL_C_CHAR, nome, sizeof(nome), NULL);
            SQLGetData(stmt, 3, SQL_C_CHAR, nota, sizeof(nota), NULL);
            std::cout << sala << " - " << nome << " - " << nota << endl;
        }

        SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    } else {
        cout << "Erro na conexão." << endl;
    }

    SQLDisconnect(dbc);
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
}