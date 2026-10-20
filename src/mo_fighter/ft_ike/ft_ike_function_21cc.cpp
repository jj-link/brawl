#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" void* fn_119_21CC(void* p, short flag) {
    if (p != 0) {
        __dt__16acCmdInterpreterFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
