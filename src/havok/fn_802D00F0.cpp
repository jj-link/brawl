#pragma force_active on

extern "C" int fn_802CEBA4();
extern "C" void fn_802CEB14();
extern "C" void fn_802CEB34();

struct Entry {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int unk8;
    int unkC;
};

extern char lbl_804103F8[];
extern Entry lbl_805326D0;

extern "C" void fn_802D00F0(void) {
    int r3 = fn_802CEBA4();
    lbl_805326D0.unk0 = (unsigned int)(&lbl_804103F8[0x1C]);
    lbl_805326D0.unk4 = (unsigned int)fn_802CEB14;
    lbl_805326D0.unk8 = (unsigned int)fn_802CEB34;
    lbl_805326D0.unkC = r3;
}

__declspec(section ".ctors") extern void* const fn_802D00F0_ctor = (void*)fn_802D00F0;
