#pragma force_active on
struct Data {
    unsigned char pad[8];
    unsigned int value;
    unsigned short index;
};

extern "C" void fn_27_1E8C6C(Data* self) {
    self->index = 0xFFFF;
    self->value = 0;
}
