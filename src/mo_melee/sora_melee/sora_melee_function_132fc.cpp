#pragma force_active on
struct Data {
    unsigned char padding[0x44];
    unsigned char upper : 1;
    unsigned char flag : 1;
    unsigned char lower : 6;
};

extern "C" void fn_27_132FC(Data* self, unsigned int value) {
    self->flag = value;
}
