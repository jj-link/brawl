#pragma force_active on
extern "C" {

extern int lbl_27_bss_2BD8;

void __dt__6gfTaskFv(void* p, int flag);
void __dl__FPv(void* p);

void* fn_27_C15E8(void* self, int flag) {
    void* result = self;
    if (self) {
        lbl_27_bss_2BD8 = 0;
        __dt__6gfTaskFv(self, 0);
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return result;
}

}
