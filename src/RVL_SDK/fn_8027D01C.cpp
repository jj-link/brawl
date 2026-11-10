#pragma force_active on

class SoHeapAllocator {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, unsigned int, int);
};

extern SoHeapAllocator* lbl_805A0EB8;

struct Obj {
    void* data;
    unsigned int raw;
    int count;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }
};

extern "C" {
Obj* __dt__14Class_8027D01CFv(Obj* self, int flag) {
    if (self) {
        if (self->isOwned()) {
            lbl_805A0EB8->free(self->data, (self->count + 1) * 8, 0x15);
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, 0xC, 0x1A);
        }
    }
    return self;
}
}
