#pragma force_active on
extern "C" void __dl__FPv(void*);

struct Object {
    unsigned char data[0x5c];
    virtual ~Object();
};

struct Owner {
    unsigned int field0;
    Object* objects[3];
};

extern "C" Owner* fn_10_1B8B4(Owner* self, int flag) {
    if (self) {
        for (int i = 0; i < 3; ++i) {
            if (self->objects[i]) {
                delete self->objects[i];
            }
        }
        if (flag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
