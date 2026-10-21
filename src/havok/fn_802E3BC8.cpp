#pragma force_active on

extern "C" int fn_802E3870();
extern "C" char lbl_80412DA8[];
extern "C" void fn_802E37E0(void*);
extern "C" void fn_802E3800(void*);

struct S {
    void* unk0;
    void (*unk4)(void*);
    void (*unk8)(void*);
    int unkC;
};
extern S lbl_80533058;

extern "C" void fn_802E3BC8() {
    int temp = fn_802E3870();
    lbl_80533058.unk0 = lbl_80412DA8;
    lbl_80533058.unk4 = fn_802E37E0;
    lbl_80533058.unk8 = fn_802E3800;
    lbl_80533058.unkC = temp;
}

__declspec(section ".ctors") extern void* const fn_802E3BC8_ctor = (void*)fn_802E3BC8;
