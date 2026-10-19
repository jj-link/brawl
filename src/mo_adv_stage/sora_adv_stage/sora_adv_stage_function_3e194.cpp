#pragma force_active on
class gfFileIOHandle;

extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_40_3E194(void* p, int flag) {
    if (p != 0) {
        __dt__14gfFileIOHandleFv(p, 0);
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
