#include <types.h>
#pragma force_active on

extern "C" s32 fn_802F0094();
extern "C" void fn_802F004C(void*);
extern "C" void fn_802F0080(void*);
extern "C" char lbl_80413748[];

struct Unk_80533200 {
    void* unk0;
    void* unk4;
    void* unk8;
    s32 unkC;
};

extern "C" struct Unk_80533200 lbl_80533200;

extern "C" void fn_802F0358(void) {
    s32 result = fn_802F0094();
    lbl_80533200.unk0 = &lbl_80413748;
    lbl_80533200.unk4 = &fn_802F004C;
    lbl_80533200.unk8 = &fn_802F0080;
    lbl_80533200.unkC = result;
}

__declspec(section ".ctors") extern void* const fn_802F0358_ctor = (void*)fn_802F0358;
