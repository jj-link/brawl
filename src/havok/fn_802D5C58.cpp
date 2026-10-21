#pragma force_active on
struct Obj5328 {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
};

extern "C" {
    extern char lbl_80410C88[];
    extern Obj5328 lbl_805328B0;
    void fn_802D51F4(void);
    void fn_802D5228(void);
    int fn_802D523C(void);

    void fn_802D5C58(void) {
        int temp_r3;

        temp_r3 = fn_802D523C();
        lbl_805328B0.unk0 = lbl_80410C88 + 0x13;
        lbl_805328B0.unk4 = (void*)fn_802D51F4;
        lbl_805328B0.unk8 = (void*)fn_802D5228;
        lbl_805328B0.unkC = (void*)temp_r3;
    }
}

__declspec(section ".ctors") extern void* const fn_802D5C58_ctor = (void*)fn_802D5C58;
