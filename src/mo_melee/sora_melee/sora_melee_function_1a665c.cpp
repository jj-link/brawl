#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int : 10;
    unsigned int value : 10;
    unsigned int : 12;
};

extern "C" void fn_27_1A665C(Data* self, unsigned int value) {
    self->value = value;
}
