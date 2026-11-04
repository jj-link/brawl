#pragma force_active on

extern "C" const float lbl_41_rodata_18;
extern "C" const double lbl_41_rodata_40;
extern "C" const float lbl_41_rodata_5C;

struct Inner {
    char pad[4];
    int value;
};

struct Outer {
    Inner* data;
    unsigned char flag;
};

extern "C" float fn_41_A204(Outer* self) {
    if (self->flag == 1) {
        return lbl_41_rodata_18;
    }
    return (float)self->data->value / lbl_41_rodata_5C;
}
