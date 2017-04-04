var http = require('http');

var s = http.createServer(function(req,res) {
    //console.log("Ashutosh Godara");
    res.writeHead(200, { 'content-type':'text/plain'});
    res.write("Hello Ashu");
    setTimeout(function() {
        res.end(" Godara");
    }, 2000);
    //res.end("HIHIHI World");
});

s.listen(8001);
