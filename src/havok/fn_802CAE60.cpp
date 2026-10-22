#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void allocate(void* ptr, unsigned short size, int align);
};

extern SoHeapAllocator* lbl_805A0EB8;

class Inner {
public:
    virtual void destroy(int flag);
};

struct Handle {
    char padding[0x100];
    Inner* inner;
};

extern "C" Handle* fn_802CAE60(Handle* self, int flag) {
    if (self != 0) {
        Inner* obj = self->inner;
        if (obj != 0) {
            obj->destroy(1);
        }
        if (flag > 0) {
            lbl_805A0EB8->allocate(self, 0x104, 0x25);
        }
    }
    return self;
}
