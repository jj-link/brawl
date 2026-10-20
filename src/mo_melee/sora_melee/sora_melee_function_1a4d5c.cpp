#pragma force_active on
typedef unsigned int u32;

struct fn_27_1A4D5C_obj {
    u32 unk0;
    u32 unk4;
    struct {
        u32 a : 10;
        u32 b : 5;
        u32 c : 17;
    } unk8;
};

extern "C" {
void fn_27_1A4D5C(fn_27_1A4D5C_obj* self, u32 v)
{
    self->unk8.b = v;
}
}
