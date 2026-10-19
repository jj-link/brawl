#pragma force_active on
typedef unsigned int u32;

extern "C" {
extern int lbl_2_bss_58;
void __dt__6gfTaskFv(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* fn_2_3CBB4(void* self, int flag) {
    if (self) {
        lbl_2_bss_58 = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
