#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct fn27Obj {
    void* p0;
    u8* p4;
    u32 p8;
};

extern "C" {
extern u8 lbl_27_data_35908[];

void fn_27_1A4754(fn27Obj* self) {
    u32 v = self->p8;
    u8* base = lbl_27_data_35908;
    self->p0 = base;
    self->p4 = base + 0x48;
    self->p8 = v & 0x7FFFF;
}
}
