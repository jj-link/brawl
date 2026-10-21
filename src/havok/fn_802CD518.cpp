#pragma force_active on
typedef int s32;

extern "C" {
    s32 fn_802CD054(void);
    void fn_802CD000(void);
    void fn_802CD040(void);
    extern char lbl_804101A8[];

    struct Holder {
        void* unk0;
        void* unk4;
        void* unk8;
        s32 unkC;
    };
    extern Holder lbl_805325F0;

    void fn_802CD518(void) {
        s32 temp_r3 = fn_802CD054();
        lbl_805325F0.unk0 = lbl_804101A8;
        lbl_805325F0.unk4 = (void*)fn_802CD000;
        lbl_805325F0.unk8 = (void*)fn_802CD040;
        lbl_805325F0.unkC = temp_r3;
    }
}

__declspec(section ".ctors") extern void* const fn_802CD518_ctor = (void*)fn_802CD518;
