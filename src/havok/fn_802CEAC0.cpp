#pragma force_active on

extern "C" {
extern int fn_802CE7C0(void);
extern char lbl_804103D0[];

struct Unk {
    void* unk0;
    void* unk4;
    void* unk8;
    int unkC;
};

extern Unk lbl_805326C0;

extern void fn_802CE5F0(void*);
extern void fn_802CE6A0(void*);

void fn_802CEAC0(void);
}

void fn_802CEAC0(void) {
    int r3 = fn_802CE7C0();
    lbl_805326C0.unk0 = lbl_804103D0 + 0x1D;
    lbl_805326C0.unk4 = (void*)fn_802CE5F0;
    lbl_805326C0.unk8 = (void*)fn_802CE6A0;
    lbl_805326C0.unkC = r3;
}

__declspec(section ".ctors") extern void* const fn_802CEAC0_ctor = (void*)fn_802CEAC0;
