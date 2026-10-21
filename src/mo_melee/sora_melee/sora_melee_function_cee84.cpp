#pragma force_active on
struct Data {
    unsigned int padding[2];
    unsigned int value : 6;
    unsigned int remainder : 26;
};

extern "C" void fn_27_CEE84(Data* self, unsigned int value) {
    self->value = value;
}
