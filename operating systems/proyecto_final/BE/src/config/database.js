const mysql = require('mysql');
const conn = mysql.createConnection({
    host: "127.0.0.1",
    user: "root",
    database: "comics"
});

conn.connect((error) => {
    if (error) {
        console.log("No se pudo conectar a la db");
    } else {
        console.log("Servidor DB corriendo");
    }
});

module.exports = conn;

