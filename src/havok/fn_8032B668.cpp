#pragma force_active on

extern "C" void fn_8027EABC(void*, void*, unsigned int, int);
extern void* lbl_805A0EC8;

class HeapAlloc {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void free(void*, int, int);
};

extern HeapAlloc* lbl_805A0EB8;

struct Obj {
    void* data;
    int size;
    unsigned int raw;

    bool isOwned() const {
        return (raw & 0x80000000) == 0;
    }
};

extern "C" void* dtor_8032B668(Obj* self, int flag) {
    if (self) {
        if (self) {
            if (self->isOwned()) {
                fn_8027EABC(lbl_805A0EC8, self->data, (self->raw & 0x3FFFFFFF) * 12, 0x15);
            }
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, 0x30C, 0x15);
        }
    }
    return self;
}
