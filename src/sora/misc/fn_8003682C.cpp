#pragma force_active on
extern "C" void __dt__14gfFileIOHandleFv(void* p, short flag);
extern "C" void __dl__FPv(void* p);

extern "C" void* fn_8003682C(void* a, int b) {
    if (a) {
        __dt__14gfFileIOHandleFv((char*)a + 0xAC, -1);
        if (b > 0)
            __dl__FPv(a);
    }
    return a;
}
