#pragma force_active on
struct Self {
    char pad0[0x3c];
    void* tbl;
    char pad1[0x158 - 0x40];
    int i158;
    int i15c;
    unsigned char b160;
    unsigned char pad160[3];
    float f164;
    int i168;
    int i16c;
    int i170;
    int i174;
    int i178;
    int i17c;
    int i180;
    int i184;
    int i188;
};

extern "C" {
extern char lbl_71_data_16A0[];
extern const float lbl_71_rodata_168;
void fn_71_2708(Self* self);

Self* fn_71_6030(Self* self) {
    fn_71_2708(self);
    self->tbl = lbl_71_data_16A0;
    self->i158 = 0;
    self->i15c = 0;
    self->i168 = 0;
    self->i16c = 0;
    self->b160 = 1;
    self->f164 = lbl_71_rodata_168;
    self->i170 = 0;
    self->i174 = 0;
    self->i178 = 0;
    self->i17c = 0;
    self->i180 = 0;
    self->i184 = 0;
    self->i188 = 0;
    return self;
}
}
