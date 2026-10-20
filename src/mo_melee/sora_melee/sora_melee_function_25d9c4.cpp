#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_25CEA4(void*, int);
extern char lbl_27_data_543B8[];
extern u32 lbl_27_data_543A8[];

struct Obj {
    void* vtbl;
    u32 unk4[3];
    u32 unk10;
    u32 unk14;
};

Obj* fn_27_25D9C4(Obj* self) {
    fn_27_25CEA4(self, 1);
    self->vtbl = lbl_27_data_543B8;
    self->unk10 = lbl_27_data_543A8[0];
    self->unk14 = 0;
    return self;
}
}
