const SerialPort = require('serialport')
const port = new SerialPort('/dev/ttyACM0', { //'/dev/tty.usbmodem14101'
    baudRate: 9600
});
port.on('error', function(err) {
    console.log('Error: ', err.message)
});

let cortines = {
    connection: true
}

let readStr = "";
const stringEnd = '\n';
port.on('data', (buffer) => {
    readStr += buffer.toString();
    if (readStr.indexOf(stringEnd) >= 0) {
        const strArr = readStr.split(stringEnd);
        if(strArr.length>1) {
            for (let i=0; i<strArr.length-1; ++i) {
                console.log('received message:', strArr[i]);
            }
            readStr = strArr[strArr.length-1];
        }
        else{
            console.log('received message:', strArr[0]);
            readStr ="";
        }
    }
});

cortines.connect = function () {
    cortines.connection = true;
};

cortines.openCortina = function (cortinaId) {
    port.write(cortinaId.toString() + '_'+ (2).toString()+'\n', () => {
        console.log("send Open" + cortinaId.toString() + '_'+ (2).toString()+'\n');
    });
};
cortines.closeCortina = function (cortinaId) {
    port.write(cortinaId.toString()  + '_'+ (4).toString()+'\n', () => {
        console.log("send close" + cortinaId.toString()  + '_'+ (4).toString()+'\n');
    });
};
cortines.controlledCloseCortina = function (cortinaId) {
    port.write(cortinaId.toString() + '_k\n', () => {
        console.log("send timed close" + cortinaId.toString() + '_k\n');
    });
};
cortines.stopCortina = function (cortinaId) {
    port.write(cortinaId.toString()  + '_'+ (1).toString()+'\n', () => {
        console.log("send stop" + cortinaId.toString()  + '_'+ (1).toString()+'\n');
    });
};

module.exports = cortines;
