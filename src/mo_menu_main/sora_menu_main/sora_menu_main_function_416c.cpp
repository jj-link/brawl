#pragma force_active on
extern "C" {
extern unsigned int lbl_2_bss_8[2];
extern unsigned int lbl_2_bss_10[2];

void fn_2_416C(void) {
    lbl_2_bss_8[0] = 0xff;
    lbl_2_bss_8[1] = 0;
    lbl_2_bss_10[0] = 0xff;
    lbl_2_bss_10[1] = 1;
}
}

__declspec(section ".ctors") extern void* const fn_2_416C_ctor = (void*)fn_2_416C;
