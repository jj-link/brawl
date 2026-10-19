#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void* fn_25_F30(void* p, int flag);
}

void* fn_25_F30(void* p, int flag) {
    if (p) {
        __dt__14gfFileIOHandleFv((char*)p + 0x40, -1);
        __dt__6gfTaskFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
