#pragma force_active on
extern "C" {
void __dt__14gfFileIOHandleFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_800FC3E4(void* p, int n) {
    if (p) {
        __dt__14gfFileIOHandleFv(p, 0);
        if (n > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
}
