declare type WindowOperation = {
    /**
     * test function,
     * doing nothing
     */
    test: () => void;
    findWindow: (titileName: string, className?: string) => number;
    getWindowText: (handle: number) => string;
    getForegroundWindow: () => number;
    getAllProcesses: () => Array<[string, number]>;
    captureWindow: (handle: number) => Array<Array<[number, number, number]>>;
    saveAsPng: (points: Array<Array<[number, number, number]>>, path: string) => void;
    setCursorPos: (x: number, y: number) => void;
    keyBoardEvent: (key: EKeyBoard, e: EKeyBoardEvent) => void;
} & {
    mouseEvent: (e: EMouseEvent.Wheel, steps: number) => void;
} & {
    mouseEvent: (e: Exclude<EMouseEvent, EMouseEvent.Wheel>, x: number, y: number) => void;
};
declare enum EMouseEvent {
    Move = 1,
    LeftDown = 2,
    LeftUp = 4,
    RightDown = 8,
    RightUp = 16,
    MiddleDown = 32,
    MiddleUp = 64,
    Wheel = 2048
}
declare enum EKeyBoard {
    BackSpace = 8,
    Tab = 9,
    Enter = 13,
    Shift = 16,
    Ctrl = 17,
    Alt = 18,
    Pau = 19,
    Caps = 20,
    Esc = 27,
    Space = 32,
    Zero = 48,
    One = 49,
    Two = 50,
    Three = 51,
    Four = 52,
    Five = 53,
    Six = 54,
    Seven = 55,
    Eight = 56,
    Nine = 57,
    A = 65,
    B = 66,
    C = 67,
    D = 68,
    E = 69,
    F = 70,
    G = 71,
    H = 72,
    I = 73,
    J = 74,
    K = 75,
    L = 76,
    M = 77,
    N = 78,
    O = 79,
    P = 80,
    Q = 81,
    R = 82,
    S = 83,
    T = 84,
    U = 85,
    V = 86,
    W = 87,
    X = 88,
    Y = 89,
    Z = 90,
    Win = 91,
    PadZero = 96,
    PadOne = 97,
    PadTwo = 98,
    PadThree = 99,
    PadFour = 100,
    PadFive = 101,
    PadSix = 102,
    PadSeven = 103,
    PadEight = 104,
    PadNine = 105,
    'Pad*' = 106,
    'Pad+' = 107,
    'Pad-' = 109,
    PadDot = 110,
    'Pad\\' = 111,
    F1 = 112,
    F2 = 113,
    F3 = 114,
    F4 = 115,
    F5 = 116,
    F6 = 117,
    F7 = 118,
    F8 = 119,
    F9 = 120,
    F10 = 121,
    F11 = 122,
    F12 = 123,
    LeftArrow = 37,
    UpArrow = 38,
    RightArrow = 39,
    DownArrow = 40,
    ';' = 186,
    '=' = 187,
    ',' = 188,
    '-' = 189,
    '.' = 190,
    '/' = 191,
    '[' = 219,
    '\\' = 220,
    ']' = 221,
    '\'' = 222
}
declare enum EKeyBoardEvent {
    Up = 2,
    Down = 0
}
declare const _default: WindowOperation;
export default _default;
