#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

extern "C" void __ct__14snd3DGeneratorFv(void*);

struct snd3DGenerator {
    u32 unk0;
    u32 unk4;
};

struct Obj {
    u32 unk00;
    void* data;
    u32 count;
    u32 unk0C;
    snd3DGenerator generator;
    u8 unk18;
    float unk1C;
    u32 unk20;
    u8 unk24;
};

extern "C" {
    extern u8 lbl_40_data_317C[];
    extern float lbl_40_rodata_1F8;
    Obj* fn_40_14988(Obj* self, u32 val);
}

Obj* fn_40_14988(Obj* self, u32 val) {
    self->unk00 = 0;
    self->count = 11;
    self->data = &lbl_40_data_317C;
    __ct__14snd3DGeneratorFv(&self->generator);
    float f = lbl_40_rodata_1F8;
    self->unk18 = 0;
    self->unk1C = f;
    self->unk20 = -1;
    self->unk24 = 0;
    self->unk0C = val;
    return self;
}
