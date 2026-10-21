#include <types.h>
#pragma force_active on

extern "C" s32 fn_802E6120();
extern "C" void fn_802E60EC(void*);
extern "C" void fn_802E610C(void*);
extern "C" char lbl_804131F8[];

struct Lbl80533180 {
    void* unk0;
    void* unk4;
    void* unk8;
    s32 unkC;
};

extern "C" Lbl80533180 lbl_80533180;

extern "C" void fn_802E61A0() {
    s32 val = fn_802E6120();
    lbl_80533180.unk0 = (void*)lbl_804131F8;
    lbl_80533180.unk4 = (void*)fn_802E60EC;
    lbl_80533180.unk8 = (void*)fn_802E610C;
    lbl_80533180.unkC = val;
}

__declspec(section ".ctors") extern void* const fn_802E61A0_ctor = (void*)fn_802E61A0;
