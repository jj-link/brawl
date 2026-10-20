#pragma force_active on
struct Object {
    void* data;
    unsigned int count;
    unsigned char padding[0x18];
    unsigned char enabled;

    virtual void unused0();
    virtual void unused1();
    virtual void reset();
};

extern "C" void fn_41_3056C(void*);
extern "C" void fn_803F0D4C(void*, void (*)(void*));

extern "C" void fn_41_2BFE8(Object* self) {
    if (self->enabled) {
        self->reset();
        if (self->data) {
            fn_803F0D4C(self->data, fn_41_3056C);
            self->data = 0;
            self->count = 0;
        }
    }
}
