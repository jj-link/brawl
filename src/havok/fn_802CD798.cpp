#pragma force_active on
typedef unsigned int u32;

extern "C" int fn_802CD71C();
extern "C" void fn_802CD6C8();
extern "C" void fn_802CD708();
extern "C" char lbl_80410238[];

struct Entry {
    void* unk0;
    void* unk4;
    void* unk8;
    int unkC;
};

extern "C" Entry lbl_80532650;

extern "C" void fn_802CD798() {
    int temp_r3 = fn_802CD71C();
    lbl_80532650.unk0 = lbl_80410238;
    lbl_80532650.unk4 = (void*)fn_802CD6C8;
    lbl_80532650.unk8 = (void*)fn_802CD708;
    lbl_80532650.unkC = temp_r3;
}

__declspec(section ".ctors") extern void* const fn_802CD798_ctor = (void*)fn_802CD798;
