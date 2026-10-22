#pragma force_active on
extern unsigned char lbl_80488988[];

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

struct Obj {
    void* vtable;
    unsigned short type;
    char pad[0x8];
    void* m_10;
};

extern "C" {
Obj* dtor_80312FD8(Obj* self, int flag) {
    if (self != 0) {
        self->vtable = lbl_80488988;
        if (self->m_10 != 0) {
            if (self->m_10 != 0) {
                lbl_805A0EB8->free(self->m_10, 1, 0x13);
            }
            self->m_10 = 0;
        }
        if (flag > 0) {
            lbl_805A0EB8->free(self, self->type, 0x1f);
        }
    }
    return self;
}
}
