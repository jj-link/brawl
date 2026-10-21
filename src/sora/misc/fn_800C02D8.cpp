#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_800C02D8(void* p, int n) {
    if (p) {
        __dt__14gfFileIOHandleFv(p, -1);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
