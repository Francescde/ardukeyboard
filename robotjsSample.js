//var robot = require("robotjs");
//var ks = require('node-key-sender');
/*
var robot = require("kbm-robot");
robot.startJar();
var express = require('express'),
    app = express(),
    port = process.env.PORT || 3000;

app.listen(port, "0.0.0.0");

var actionsP1 =['up','down','right','left','shift','enter','q','w','a','s','d'];
function executeAction(controller,action){
    if(controller==1){
        //ks.sendKey(actionsP1[action-1]);
        //robot.keyTap(actionsP1[action-1]);

        robot.press(actionsP1[action-1]);
            //.typeString("Hello World!");
        //robot.press(actionsP1[action-1]);
    }
}
console.log('API server started on: ' + port);
app.get('/controller/:controller/action/:action', function (req, res, next) {
    console.log('requesr');
    var controller = req.params.controller;
    var actions = req.params.action;
    actionsArr = actions.split(",");
    //robot.startJar();
    if(actionsArr.length>0) {
        for (var i = 0, len = actionsArr.length; i < len; i++) {
            executeAction(controller,parseInt(actionsArr[i]));
        }
        robot.go();
    }
    //robot.go().then(robot.stopJar);

    console.log('controller '+controller+' asks action '+actions);
});

console.log('All ready');*/

import robotjs from 'robotjs';
var i=1;
//Move the mouse to 100, 100 on the screen.
setInterval(function() {
    var mouse = robotjs.getMousePos();
    console.log("Mouse is at x:" + mouse.x + " y:" + mouse.y);
    robotjs.moveMouse( mouse.x + (2 * i), mouse.y + (4 * i));
    i = i * -1;
}, 5000);


