#pragma force_active on
struct Fn40Obj {
    int unk0;
    int unk4;
    struct {
        unsigned int a : 5;
        unsigned int b : 5;
        unsigned int c : 22;
    } flags;
};

extern "C" {
void fn_40_30A54(Fn40Obj* obj, unsigned int val) {
    obj->flags.b = val;
}
}
