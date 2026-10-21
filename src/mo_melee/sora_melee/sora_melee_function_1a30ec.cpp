#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int : 6;
    unsigned int value : 3;
    unsigned int : 23;
};

extern "C" void fn_27_1A30EC(Data* self, unsigned int value) {
    self->value = value;
}
