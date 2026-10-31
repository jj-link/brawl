#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);

class SoAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();

    int field_04;
    int field_08;
    int field_0C;
    unsigned int field_10;
    int field_14;
    unsigned int field_18;
};

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned short, int);
};

extern SoAllocator* lbl_805A0EC8;
extern SoHeapAllocator* lbl_805A0EB8;

struct ArrayObj {
    void* data;
    int size;
    unsigned int raw;
    unsigned int field_C;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }

    void dealloc() {
        fn_8027EABC(lbl_805A0EC8, data, raw << 2, 0x15);
    }

    ~ArrayObj() {
        if (isOwned())
            dealloc();
    }
};

extern "C" ArrayObj* __dt__14Class_8030F998Fv(ArrayObj* self, int flag) {
    if (self) {
        unsigned int value = self->field_C;
        SoAllocator* allocator = lbl_805A0EC8;
        allocator->field_10 = value;
        if (value == allocator->field_18)
            allocator->vf4();

        self->~ArrayObj();

        if (flag > 0)
            lbl_805A0EB8->free(self, 0x10, 0x15);
    }
    return self;
}
