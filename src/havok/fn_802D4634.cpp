#pragma force_active on

struct Fn802D4634Data {
    void* unk0;
    void* unk4;
    void* unk8;
    void* unkC;
};

extern "C" {
    extern void* fn_802D26CC(void);
    extern void fn_802D2628(void);
    extern void fn_802D265C(void);
    extern char lbl_80410778[];
    extern Fn802D4634Data lbl_805327E8;
}

extern "C" void fn_802D4634(void) {
    void* temp_r3 = fn_802D26CC();
    lbl_805327E8.unk0 = (void*)(lbl_80410778 + 0x19);
    lbl_805327E8.unk4 = (void*)fn_802D2628;
    lbl_805327E8.unk8 = (void*)fn_802D265C;
    lbl_805327E8.unkC = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802D4634_ctor = (void*)fn_802D4634;
