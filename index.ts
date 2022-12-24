import binding from 'bindings'
type WindowOperation = {
    /**
     * test function,
     * doing nothing
     */
    test: () => void;
    findWindow: (titileName: string, className?: string) => number;
    getWindowText: (handle: number) => string;
    getForegroundWindow: () => number;
}

const winOperation: WindowOperation = binding('windowOperation');
// const handle = winOperation.findWindow('Path of Exile', 'POEWindowClass');
// console.log(handle, winOperation.getWindowText(handle));
// console.log(winOperation.test());
//r.nn)*w^u7R/LV:
export default {...winOperation};