#pragma force_active on

typedef unsigned char u8;

extern "C" {
void** fn_801B5DC0(void**, void*);
void fn_801B5F34(void**);
void GXSetFog(int, u8*, float, float, float, float);
extern unsigned char lbl_804A4F00[];
extern float lbl_805A331C;
}

extern "C" void fn_801A0E7C(int arg0) {
    void* spC;
    int sp8;
    int flags;

    flags = *(int*)lbl_804A4F00;
    if ((flags & 1) == 0 || (flags & 2) == 0 || arg0 != *(int*)(lbl_804A4F00 + 4)) {
        if (arg0 < 0 || arg0 >= 0x20) {
            sp8 = 0;
            GXSetFog(0, (u8*)&sp8, lbl_805A331C, lbl_805A331C, lbl_805A331C, lbl_805A331C);
        } else {
            fn_801B5F34(fn_801B5DC0(&spC, (void*)(lbl_804A4F00 + arg0 * 0x30 + 8)));
        }
        *(int*)(lbl_804A4F00 + 4) = arg0;
        *(int*)lbl_804A4F00 |= 0x3;
    }
}