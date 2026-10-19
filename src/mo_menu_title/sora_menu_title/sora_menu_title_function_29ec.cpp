#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dt__6gfTaskFv(void* p, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_24_29EC(void* p, int flag) {
    if (p) {
        __dt__14gfFileIOHandleFv((char*)p + 0x44, -1);
        __dt__14gfFileIOHandleFv((char*)p + 0x40, -1);
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
