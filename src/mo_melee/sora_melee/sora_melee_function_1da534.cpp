#pragma force_active on
struct Middle;

class Target {
public:
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void call(int value, Middle* middle);
};

struct Inner {
    unsigned char padding[0x70];
    Target* target;
};

struct Middle {
    unsigned char padding[0xD8];
    Inner* inner;
};

struct Object {
    unsigned char padding[0x60];
    Middle* middle;
};

extern "C" void fn_27_1DA534(Object* self, int value) {
    self->middle->inner->target->call(value, self->middle);
}
