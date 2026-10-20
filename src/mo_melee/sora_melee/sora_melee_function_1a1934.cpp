#pragma force_active on
struct fn27Obj {
    unsigned int unk0;
    unsigned int unk4;
    unsigned int hi : 6;
    unsigned int field : 6;
    unsigned int lo : 20;
};

extern "C" {
void fn_27_1A1934(fn27Obj* obj, unsigned int val) {
    obj->field = val;
}
}
