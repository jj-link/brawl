#pragma force_active on
extern "C" void __dt__14gfFileIOHandleFv(void*, int);
extern "C" void __dt__6gfTaskFv(void*, int);
extern "C" void __dl__FPv(void*);

extern "C" {
void* fn_80033988(void* p, int flag) {
    if (p != 0) {
        __dt__14gfFileIOHandleFv((char*)p + 0xE8, -1);
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
