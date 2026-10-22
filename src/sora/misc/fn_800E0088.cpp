#pragma force_active on
extern "C" {
void fn_800E011C(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void fn_800DFE6C(void*, int);
void fn_800726A8(void*, int);
void __dt__14gfFileIOHandleFv(void*, int);
void __dl__FPv(void*);
extern char lbl_8045A38C[];

void* fn_800E0088(char* self, int flags) {
    if (self) {
        *(char**)(self + 0x5D4) = lbl_8045A38C;
        fn_800E011C(self);
        __destroy_arr(self + 0x3EC, fn_800DFE6C, 0x48, 4);
        fn_800726A8(self + 0x3A8, -1);
        {
            char* p = self + 0x290;
            if (p) {
                __dt__14gfFileIOHandleFv(p, -1);
            }
        }
        if (flags > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
}
