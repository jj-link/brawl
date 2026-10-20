#pragma force_active on
struct Data {
    unsigned char pad[0x72];
    unsigned char upper : 4;
    unsigned char flag : 1;
    unsigned char lower : 3;
};

struct Object {
    unsigned int unk0;
    Data* data;
    unsigned char pad[0x30];
    unsigned int upper : 31;
    unsigned int flag : 1;
};

extern "C" void fn_27_2EE9C(Object* self, unsigned int value, unsigned int mode) {
    self->data->flag = value;
    if (mode == 1) {
        self->flag = value;
    }
}
