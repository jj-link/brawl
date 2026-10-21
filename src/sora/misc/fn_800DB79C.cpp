#pragma force_active on
extern "C" {
typedef struct { int x0; int x4; } Struct_805A02B0;
extern Struct_805A02B0 lbl_805A02B0;
extern int fn_801A7550(Struct_805A02B0*, int);

void fn_800DB79C(void) {
    fn_801A7550(&lbl_805A02B0, 0);
}
}

__declspec(section ".ctors") extern void* const fn_800DB79C_ctor = (void*)fn_800DB79C;
