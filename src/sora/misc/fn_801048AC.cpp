#pragma force_active on
typedef signed char s8;

struct Blk {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
};

extern "C" {
extern struct Blk lbl_8049E560;
extern s8 lbl_805A0314;

void fn_801048AC(void) {
    if (lbl_805A0314 == 0) {
        lbl_8049E560.unk4 = 0;
        lbl_8049E560.unk0 = 0;
        lbl_8049E560.unk8 = 0;
        lbl_805A0314 = 1;
    }
}
}

__declspec(section ".ctors") extern void* const fn_801048AC_ctor = (void*)fn_801048AC;
