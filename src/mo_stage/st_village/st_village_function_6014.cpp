#pragma force_active on
extern "C" {
void fn_70_2088(void*);
void __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
    void*, void*, unsigned long, void*, unsigned long);
void __ct__14snd3DGeneratorFv(void*);

extern void* lbl_70_data_27A0[];
extern void* lbl_70_data_29E0[];
extern const float lbl_70_rodata_D0[];
}

struct Self {
    char pad0[0x3c];
    void* vtable;
    char pad1[0x168 - 0x40];
    unsigned char a;
    unsigned char b;
    unsigned char c;
    float x;
    float y;
    char seq[0x50];
    char gen[8];
};

extern "C" Self* fn_70_6014(Self* self) {
    fn_70_2088(self);
    self->vtable = lbl_70_data_27A0;

    char* seq = self->seq;
    __ct__Q28StSeUtil5SeSeqFPQ28StSeUtil10UnkStruct2UlPQ28StSeUtil10UnkStruct3Ul(
        seq, seq + 0x20, 1, seq + 0x2c, 1);
    *(void**)seq = lbl_70_data_29E0;
    __ct__14snd3DGeneratorFv(self->gen);

    self->a = 5;
    self->b = 1;
    self->c = 4;
    self->x = lbl_70_rodata_D0[0];
    self->y = lbl_70_rodata_D0[0];
    return self;
}
