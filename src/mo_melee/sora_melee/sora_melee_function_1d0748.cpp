#pragma force_active on
struct Data {
    int a;
    int b;
    int c;
};

extern "C" int fn_27_1D0748(Data* self) {
    return self->c >> 28;
}
