#pragma force_active on
extern "C" void* __dt__16acCmdInterpreterFv(void*, short);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_112_21EC(void* p, short flags) {
    if (p != 0) {
        __dt__16acCmdInterpreterFv(p, 0);
        if (flags > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
