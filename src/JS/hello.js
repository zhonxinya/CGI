


var http = require("http");
console.log("http");

var server = http.createServer(request,response){
    response.setHeader("Content-Type","text/html; charset=utf-8");
    response.write("<h1>Hello World</h1>");
    response.end();
};

server.linste(9000);