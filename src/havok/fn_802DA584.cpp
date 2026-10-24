#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Object {
    void* vtable;
    unsigned short type;
    char pad[0x12];
    void* data;
    unsigned int size;
    unsigned int raw;

    unsigned int rawValue() const {
        return raw;
    }
};

extern "C" Object* fn_802DA584(Object* self, int flag) {
    if (self) {
        if ((unsigned int)self + 0x18 != 0 && !(self->raw & 0x80000000)) {
            fn_8027EABC(lbl_805A0EC8, self->data, self->rawValue() << 5, 0x15);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x2A);
        }
    }
    return self;
}