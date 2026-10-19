#pragma force_active on
extern "C" {
void fn_27_D2FF0(void* object, int a, int b);
void* fn_27_61454(void* a, void* b, void* c, void* d, void* e, void* f);
extern unsigned char lbl_27_bss_4694[0xC];
extern unsigned char lbl_27_bss_46AC[0x4];
}

extern "C" void* fn_110_795C(void* object, void* context, int index) {
    fn_27_D2FF0(object, 1, 0);
    fn_27_61454(static_cast<unsigned char*>(object) + 0xAC, context, object,
                lbl_27_bss_4694, lbl_27_bss_46AC, reinterpret_cast<void*>(index));
    return object;
}
