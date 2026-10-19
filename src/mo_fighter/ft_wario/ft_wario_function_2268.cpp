#pragma force_active on
extern "C" {
void* __dt__16acCmdInterpreterFv(void*, short);
void __dl__FPv(void*);
void* fn_110_2268(void* p1, short p2);
}

extern "C" void* fn_110_2268(void* p1, short p2) {
    if (p1 != 0) {
        __dt__16acCmdInterpreterFv(p1, 0);
        if (p2 > 0) {
            __dl__FPv(p1);
        }
    }
    return p1;
}
