#pragma force_active on
extern "C" {
extern void fn_27_D2FF0(void* self, int a, int b);
extern void* fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);
extern unsigned char lbl_27_bss_4694[0xC];
extern unsigned char lbl_27_bss_46AC[0x4];

void* fn_123_7960(void* self, void* arg1, void* arg2) {
    fn_27_D2FF0(self, 1, 0);
    fn_27_61454(static_cast<unsigned char*>(self) + 0xAC, arg1, self, lbl_27_bss_4694, lbl_27_bss_46AC, arg2);
    return self;
}
}
