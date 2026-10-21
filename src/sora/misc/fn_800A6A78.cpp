#pragma force_active on
extern "C" char lbl_80454F5C[];

struct Obj {
    int unk0;
    int unk4;
    void* unk8;
};

extern "C" void fn_800A6A78(Obj* p) {
    p->unk0 = 0;
    p->unk8 = lbl_80454F5C;
    p->unk4 = 0;
}
