#pragma force_active on
struct _fn27_struct {
    int unk0;
    int unk4;
    unsigned unk8_low : 15;
    unsigned value : 1;
    unsigned unk8_high : 16;
};

extern "C" int fn_27_1A4D38(_fn27_struct* self) {
    return self->value;
}
