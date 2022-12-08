import winOperation from './build/Release/windowOperation.node'
type WindowOperation = {
    test: () => void;
    findWindow: (titileName: string, className?: string) => number;
    getWindowText: (handle: number) => string;
    getForegroundWindow: () => number;
    getAllProcesses: () => Array<[string, number]>;
    captureWindow: (handle: number) => Array<Array<[number, number, number]>>;
    saveAsPng: (points: Array<Array<[number, number, number]>>, path: string) => void;
    setCursorPos: (x: number, y: number) => void;
    keyBoardEvent: (key: EKeyBoard, e: EKeyBoardEvent) => void,
} & {
    mouseEvent: (e: EMouseEvent.Wheel, steps: number) => void;
} & {
    mouseEvent: (e: Exclude<EMouseEvent, EMouseEvent.Wheel>, x: number, y: number) => void;
}

enum EMouseEvent
{
    Move = 0x0001,
    LeftDown = 0x0002,
    LeftUp = 0x0004,
    RightDown = 0x0008,
    RightUp = 0x0010,
    MiddleDown = 0x0020,
    MiddleUp = 0x0040,
    Wheel = 0x0800,
}

enum EKeyBoard
{
    BackSpace = 8, Tab,
    Enter = 13,
    Shift = 16, Ctrl, Alt, Pau, Caps,
    Esc = 27,
    Space = 32,
    Zero = 48, One, Two, Three, Four, Five, Six, Seven, Eight, Nine,
    A = 65, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    Win = 91,
    PadZero = 96, PadOne, PadTwo, PadThree, PadFour, PadFive, PadSix, PadSeven, PadEight, PadNine, 'Pad*', 'Pad+',
    'Pad-' = 109, PadDot, 'Pad\\', F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
    LeftArrow = 37, UpArrow, RightArrow, DownArrow,
    ';' = 186, '=', ',', '-', '.', '/',
    '[' = 219, '\\', ']', '\'',
}

enum EKeyBoardEvent
{
    Up = 2,
    Down = 0,
}


// let win = winOperation as WindowOperation;
// let processes = win.getAllProcesses();
// let result = processes.find(process =>
// {
//     return process[0].match(/path of exile/gi);
// });
// let capture = win.captureWindow(1380708);
// win.mouseEvent(EMouseEvent.Move, 100, 200);
// win.keyBoardEvent(EKeyBoard.Caps, EKeyBoardEvent.Down);
// win.keyBoardEvent(EKeyBoard.A, EKeyBoardEvent.Up);
// win.saveAsPng(capture, './ddsa.png');


export default winOperation as WindowOperation;