#pragma force_active on
extern "C" void fn_90_72D8(void*, unsigned int, unsigned int, unsigned int);

struct Object {
    unsigned char pad[0x208];
    int state;
    unsigned char pad2[4];
    unsigned int arg0;
    unsigned int arg1;
    unsigned int arg2;
};

extern "C" void fn_90_4C40(Object* self) {
    if (self->state == 1) {
        fn_90_72D8(self, self->arg0, self->arg1, self->arg2);
        self->state = 2;
    }
}
