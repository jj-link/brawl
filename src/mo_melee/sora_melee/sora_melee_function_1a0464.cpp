#pragma force_active on
struct Data {
    unsigned int pad[2];
    unsigned int upper : 14;
    unsigned int value : 7;
    unsigned int lower : 11;
};

extern "C" void fn_27_1A0464(Data* self, unsigned int value) {
    self->value = value;
}
