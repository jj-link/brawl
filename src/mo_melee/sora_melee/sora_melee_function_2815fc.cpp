#pragma force_active on
struct fn_27_2815FC_t {
    char _0x2c[0x2c];
    unsigned int f0 : 17;
    int f1 : 8;
    unsigned int f2 : 7;
};

extern "C" int fn_27_2815FC(fn_27_2815FC_t* self) {
    return self->f1;
}
