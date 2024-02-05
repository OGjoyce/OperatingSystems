const http = require("http");

const host = 'localhost';
const port = 3535;

const requestListener = function (req, res) {};


app.get("/",function(request, response){
    var id = request.params.id;
    // do something with id
    // send a response to user based on id
    var obj = { id : id, Content : "content " +id };
    
    response.writeHead(200, {"Content-Type": "application/json"});
    response.write(JSON.stringify(obj));
});

const server = http.createServer(requestListener);
server.listen(port, host, () => {
    console.log(`Server is running on http://${host}:${port}`);
});