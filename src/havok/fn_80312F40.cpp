#pragma force_active on

struct Lbl805332B0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
};

extern "C" Lbl805332B0 lbl_805332B0;

extern "C" void fn_80312F40(void) {
    lbl_805332B0.unk0 = 8;
    lbl_805332B0.unk4 = 0xA;
    lbl_805332B0.unk8 = 0;
    lbl_805332B0.unkC = 4;
    lbl_805332B0.unk10 = 2;
    lbl_805332B0.unk14 = 6;
}

__declspec(section ".ctors") extern void* const fn_80312F40_ctor = (void*)fn_80312F40;
