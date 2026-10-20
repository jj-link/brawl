#pragma force_active on
typedef unsigned int u32;

extern "C" {

struct fn_27_1A1F24_struct {
    u32 unk0;
    u32 unk4;
    u32 flags;
};

void fn_27_1A1F24(fn_27_1A1F24_struct *obj) {
    obj->flags |= 0x80000;
}

}
