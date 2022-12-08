"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const windowOperation_node_1 = __importDefault(require("./build/Release/windowOperation.node"));
var EMouseEvent;
(function (EMouseEvent) {
    EMouseEvent[EMouseEvent["Move"] = 1] = "Move";
    EMouseEvent[EMouseEvent["LeftDown"] = 2] = "LeftDown";
    EMouseEvent[EMouseEvent["LeftUp"] = 4] = "LeftUp";
    EMouseEvent[EMouseEvent["RightDown"] = 8] = "RightDown";
    EMouseEvent[EMouseEvent["RightUp"] = 16] = "RightUp";
    EMouseEvent[EMouseEvent["MiddleDown"] = 32] = "MiddleDown";
    EMouseEvent[EMouseEvent["MiddleUp"] = 64] = "MiddleUp";
    EMouseEvent[EMouseEvent["Wheel"] = 2048] = "Wheel";
})(EMouseEvent || (EMouseEvent = {}));
var EKeyBoard;
(function (EKeyBoard) {
    EKeyBoard[EKeyBoard["BackSpace"] = 8] = "BackSpace";
    EKeyBoard[EKeyBoard["Tab"] = 9] = "Tab";
    EKeyBoard[EKeyBoard["Enter"] = 13] = "Enter";
    EKeyBoard[EKeyBoard["Shift"] = 16] = "Shift";
    EKeyBoard[EKeyBoard["Ctrl"] = 17] = "Ctrl";
    EKeyBoard[EKeyBoard["Alt"] = 18] = "Alt";
    EKeyBoard[EKeyBoard["Pau"] = 19] = "Pau";
    EKeyBoard[EKeyBoard["Caps"] = 20] = "Caps";
    EKeyBoard[EKeyBoard["Esc"] = 27] = "Esc";
    EKeyBoard[EKeyBoard["Space"] = 32] = "Space";
    EKeyBoard[EKeyBoard["Zero"] = 48] = "Zero";
    EKeyBoard[EKeyBoard["One"] = 49] = "One";
    EKeyBoard[EKeyBoard["Two"] = 50] = "Two";
    EKeyBoard[EKeyBoard["Three"] = 51] = "Three";
    EKeyBoard[EKeyBoard["Four"] = 52] = "Four";
    EKeyBoard[EKeyBoard["Five"] = 53] = "Five";
    EKeyBoard[EKeyBoard["Six"] = 54] = "Six";
    EKeyBoard[EKeyBoard["Seven"] = 55] = "Seven";
    EKeyBoard[EKeyBoard["Eight"] = 56] = "Eight";
    EKeyBoard[EKeyBoard["Nine"] = 57] = "Nine";
    EKeyBoard[EKeyBoard["A"] = 65] = "A";
    EKeyBoard[EKeyBoard["B"] = 66] = "B";
    EKeyBoard[EKeyBoard["C"] = 67] = "C";
    EKeyBoard[EKeyBoard["D"] = 68] = "D";
    EKeyBoard[EKeyBoard["E"] = 69] = "E";
    EKeyBoard[EKeyBoard["F"] = 70] = "F";
    EKeyBoard[EKeyBoard["G"] = 71] = "G";
    EKeyBoard[EKeyBoard["H"] = 72] = "H";
    EKeyBoard[EKeyBoard["I"] = 73] = "I";
    EKeyBoard[EKeyBoard["J"] = 74] = "J";
    EKeyBoard[EKeyBoard["K"] = 75] = "K";
    EKeyBoard[EKeyBoard["L"] = 76] = "L";
    EKeyBoard[EKeyBoard["M"] = 77] = "M";
    EKeyBoard[EKeyBoard["N"] = 78] = "N";
    EKeyBoard[EKeyBoard["O"] = 79] = "O";
    EKeyBoard[EKeyBoard["P"] = 80] = "P";
    EKeyBoard[EKeyBoard["Q"] = 81] = "Q";
    EKeyBoard[EKeyBoard["R"] = 82] = "R";
    EKeyBoard[EKeyBoard["S"] = 83] = "S";
    EKeyBoard[EKeyBoard["T"] = 84] = "T";
    EKeyBoard[EKeyBoard["U"] = 85] = "U";
    EKeyBoard[EKeyBoard["V"] = 86] = "V";
    EKeyBoard[EKeyBoard["W"] = 87] = "W";
    EKeyBoard[EKeyBoard["X"] = 88] = "X";
    EKeyBoard[EKeyBoard["Y"] = 89] = "Y";
    EKeyBoard[EKeyBoard["Z"] = 90] = "Z";
    EKeyBoard[EKeyBoard["Win"] = 91] = "Win";
    EKeyBoard[EKeyBoard["PadZero"] = 96] = "PadZero";
    EKeyBoard[EKeyBoard["PadOne"] = 97] = "PadOne";
    EKeyBoard[EKeyBoard["PadTwo"] = 98] = "PadTwo";
    EKeyBoard[EKeyBoard["PadThree"] = 99] = "PadThree";
    EKeyBoard[EKeyBoard["PadFour"] = 100] = "PadFour";
    EKeyBoard[EKeyBoard["PadFive"] = 101] = "PadFive";
    EKeyBoard[EKeyBoard["PadSix"] = 102] = "PadSix";
    EKeyBoard[EKeyBoard["PadSeven"] = 103] = "PadSeven";
    EKeyBoard[EKeyBoard["PadEight"] = 104] = "PadEight";
    EKeyBoard[EKeyBoard["PadNine"] = 105] = "PadNine";
    EKeyBoard[EKeyBoard["Pad*"] = 106] = "Pad*";
    EKeyBoard[EKeyBoard["Pad+"] = 107] = "Pad+";
    EKeyBoard[EKeyBoard["Pad-"] = 109] = "Pad-";
    EKeyBoard[EKeyBoard["PadDot"] = 110] = "PadDot";
    EKeyBoard[EKeyBoard["Pad\\"] = 111] = "Pad\\";
    EKeyBoard[EKeyBoard["F1"] = 112] = "F1";
    EKeyBoard[EKeyBoard["F2"] = 113] = "F2";
    EKeyBoard[EKeyBoard["F3"] = 114] = "F3";
    EKeyBoard[EKeyBoard["F4"] = 115] = "F4";
    EKeyBoard[EKeyBoard["F5"] = 116] = "F5";
    EKeyBoard[EKeyBoard["F6"] = 117] = "F6";
    EKeyBoard[EKeyBoard["F7"] = 118] = "F7";
    EKeyBoard[EKeyBoard["F8"] = 119] = "F8";
    EKeyBoard[EKeyBoard["F9"] = 120] = "F9";
    EKeyBoard[EKeyBoard["F10"] = 121] = "F10";
    EKeyBoard[EKeyBoard["F11"] = 122] = "F11";
    EKeyBoard[EKeyBoard["F12"] = 123] = "F12";
    EKeyBoard[EKeyBoard["LeftArrow"] = 37] = "LeftArrow";
    EKeyBoard[EKeyBoard["UpArrow"] = 38] = "UpArrow";
    EKeyBoard[EKeyBoard["RightArrow"] = 39] = "RightArrow";
    EKeyBoard[EKeyBoard["DownArrow"] = 40] = "DownArrow";
    EKeyBoard[EKeyBoard[";"] = 186] = ";";
    EKeyBoard[EKeyBoard["="] = 187] = "=";
    EKeyBoard[EKeyBoard[","] = 188] = ",";
    EKeyBoard[EKeyBoard["-"] = 189] = "-";
    EKeyBoard[EKeyBoard["."] = 190] = ".";
    EKeyBoard[EKeyBoard["/"] = 191] = "/";
    EKeyBoard[EKeyBoard["["] = 219] = "[";
    EKeyBoard[EKeyBoard["\\"] = 220] = "\\";
    EKeyBoard[EKeyBoard["]"] = 221] = "]";
    EKeyBoard[EKeyBoard["'"] = 222] = "'";
})(EKeyBoard || (EKeyBoard = {}));
var EKeyBoardEvent;
(function (EKeyBoardEvent) {
    EKeyBoardEvent[EKeyBoardEvent["Up"] = 2] = "Up";
    EKeyBoardEvent[EKeyBoardEvent["Down"] = 0] = "Down";
})(EKeyBoardEvent || (EKeyBoardEvent = {}));
let win = windowOperation_node_1.default;
let processes = win.getAllProcesses();
let result = processes.find(process => {
    return process[0].match(/path of exile/gi);
});
let capture = win.captureWindow(1380708);
// win.mouseEvent(EMouseEvent.Move, 100, 200);
win.keyBoardEvent(EKeyBoard.Caps, EKeyBoardEvent.Down);
// win.keyBoardEvent(EKeyBoard.A, EKeyBoardEvent.Up);
// win.saveAsPng(capture, './ddsa.png');
exports.default = windowOperation_node_1.default;