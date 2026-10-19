#pragma force_active on
extern "C" {
void* __dt__16acCmdInterpreterFv(void*, short);
void __dl__FPv(void*);
}

extern "C" void* fn_122_2158(void* p, short del) {
    if (p) {
        __dt__16acCmdInterpreterFv(p, 0);
        if (del > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
