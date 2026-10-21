#pragma force_active on
struct Object {
    unsigned char padding[0x14];
    unsigned char : 2;
    unsigned char flag : 1;
    unsigned char : 5;
};

extern "C" void fn_27_B4664(Object* self, unsigned int value) {
    self->flag = value;
}
