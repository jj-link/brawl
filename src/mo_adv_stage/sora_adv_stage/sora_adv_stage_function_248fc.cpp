#pragma force_active on
struct Fn40Obj {
    int unk0;
    int unk4;
    int unk8;
};

extern "C" {
int fn_40_248FC(Fn40Obj* obj) {
    return obj->unk8 >> 30;
}
}
