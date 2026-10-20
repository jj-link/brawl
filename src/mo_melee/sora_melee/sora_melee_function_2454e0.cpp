#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern char lbl_27_data_4E618[];
extern char lbl_27_data_4E634[];
extern const float lbl_27_rodata_3F30;
void fn_27_241E30(void* self, const char* name);

struct fn27Obj {
    u8 pad0[0x3C];
    void* unk3C;
    u8 unk40;
    u8 pad41[0x48 - 0x41];
    float unk48;
};

fn27Obj* fn_27_2454E0(fn27Obj* self) {
    fn_27_241E30(self, lbl_27_data_4E618);
    self->unk3C = lbl_27_data_4E634;
    self->unk40 = 0;
    self->unk48 = lbl_27_rodata_3F30;
    return self;
}
}
