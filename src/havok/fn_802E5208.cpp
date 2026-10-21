#pragma force_active on
typedef int s32;

struct Fn830Obj {
    void* unk0;
    void* unk4;
    void* unk8;
    s32 unkC;
};

extern "C" s32 fn_802E485C();
extern "C" void fn_802E4828(void* self);
extern "C" void fn_802E4848(void* self);
extern "C" char lbl_80413120[];
extern "C" Fn830Obj lbl_805330E8;

extern "C" void fn_802E5208(void) {
    s32 temp_r3 = fn_802E485C();
    lbl_805330E8.unk0 = lbl_80413120;
    lbl_805330E8.unk4 = (void*)fn_802E4828;
    lbl_805330E8.unk8 = (void*)fn_802E4848;
    lbl_805330E8.unkC = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802E5208_ctor = (void*)fn_802E5208;
