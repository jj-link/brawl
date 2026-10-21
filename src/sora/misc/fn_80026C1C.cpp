#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_80026C1C(void* p, int n) {
    if (p) {
        __dt__14gfFileIOHandleFv((char*)p + 0x14, -1);
        if (n > 0)
            __dl__FPv(p);
    }
    return p;
}
}
