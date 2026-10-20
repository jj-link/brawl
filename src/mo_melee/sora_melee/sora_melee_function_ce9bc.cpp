#pragma force_active on
typedef unsigned int u32;

struct fn_27_CE9BC_obj {
    u32 unk0;
    u32 unk4;
    u32 field0 : 6;
    u32 field1 : 26;
};

extern "C" {
void fn_27_CE9BC(fn_27_CE9BC_obj* self, u32 v) {
    self->field0 = v;
}
}
