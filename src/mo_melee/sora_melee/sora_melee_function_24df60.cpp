#pragma force_active on
extern "C" {
extern unsigned char lbl_27_data_4F3F8[12];
extern void* lbl_27_bss_59A0[2];

void* fn_27_24DF60() {
    return lbl_27_bss_59A0[0] = lbl_27_data_4F3F8;
}
}

__declspec(section ".ctors") extern void* const fn_27_24DF60_ctor = (void*)fn_27_24DF60;
