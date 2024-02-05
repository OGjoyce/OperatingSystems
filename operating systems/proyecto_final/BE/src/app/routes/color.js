const conn = require('../../config/database');

module.exports = (app) => {
    app.get('/color', (req, res, next) => {

        var operation = req.query.operation;
        var action = req.query.action;
        if(operation == "insert"){
            if(action == "usuario"){
                let query = "INSERT INTO `usuarios` (`idusuario`, `nombre`, `usuario`, `password`, `fecha_nac`, `sexo`) VALUES" + ` (NULL, '${req.query.name}', '${req.query.user}', '${req.query.pwd}', '${req.query.date}', '${req.query.sexo}');`;
                        conn.query(query, (err, rows, cols) => {
            if (err) {
                res.json({status: 0, message: "Error en la db"});
            } else {
                res.json({status: 1, msg: "ok"});
            }
         });
            }
            if(action == "comic"){
                 let query = "INSERT INTO `comic` (`idcomic`, `nombre`, `impresion`, `sinopsis`, `editorial`, `idusuario`) VALUES" + ` (NULL, '${req.query.nombre}', '${req.query.impresion}', '${req.query.sinopsis}', '${req.query.editorial}', '${req.query.idusuario}');`;
                        console.log(query);
                        conn.query(query, (err, rows, cols) => {
            if (err) {
                res.json({status: 0, message: "Error en la db"});
            } else {
                res.json({status: 1, msg: "ok"});
            }
         });

            }
        }
        if(operation == "select"){
            if(action == "usuario"){
            let query = "SELECT * FROM  `usuarios` where usuario =" +`'${req.query.usuario}'AND password = '${req.query.pwd}' `;
             conn.query(query, (err, rows, cols) => {
            if (err) {
                 return res.json({status: 0, message: "Error en la db"});
            } else {
                return res.json({status: 1, msg: rows});
            }
         });

            }
            if(action == "comic"){
            let query = "SELECT * FROM  `comic` where idusuario =" +`'${req.query.usuario}'`;
             conn.query(query, (err, rows, cols) => {
            if (err) {
                res.json({status: 0, message: "Error en la db"});
            } else {
                res.json({status: 1, msg: rows});
            }
         });



            }

        }
                if(operation == "delete"){
                    if(action=="comic"){

                            let query = "DELETE FROM `comic` WHERE `comic`.`idcomic` = '"+req.query.id+"'";
                            console.log(query);
                            conn.query(query, (err, rows, cols) => {
                        if (err) {
                            res.json({status: 0, message: "Error en la db"});
                        } else {
                            res.json({status: 1, msg: rows});
                        }
                        });
                }
    }
                if(operation == "update"){
                    if(action=="comic"){

                        let query = "UPDATE `comic` SET `nombre` = "+`'${req.query.nombre}', sinopsis='${req.query.sinopsis} '`+" WHERE `comic`.`idcomic` = "+req.query.id+";"
                        console.log(query);
                            conn.query(query, (err, rows, cols) => {
                        if (err) {
                            res.json({status: 0, message: "Error en la db"});
                        } else {
                            res.json({status: 1, msg: rows});
                        }
                        });
                    }
                }
    

    });

}