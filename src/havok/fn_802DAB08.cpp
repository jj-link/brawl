#pragma force_active on
extern "C" {
    int fn_802DA4E4();
    void fn_802DA49C();
    void fn_802DA4D0();
    extern char lbl_804121D8[];
}

struct Holder {
    void* unk0;
    void* unk4;
    void* unk8;
    int unkC;
};

extern "C" Holder lbl_80532E40;

extern "C" void fn_802DAB08() {
    int temp_r3;

    temp_r3 = fn_802DA4E4();
    lbl_80532E40.unk0 = lbl_804121D8;
    lbl_80532E40.unk4 = (void*)fn_802DA49C;
    lbl_80532E40.unk8 = (void*)fn_802DA4D0;
    lbl_80532E40.unkC = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802DAB08_ctor = (void*)fn_802DAB08;
