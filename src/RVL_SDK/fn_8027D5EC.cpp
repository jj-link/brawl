#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5(void*, unsigned int, int);
};

extern Object_vptr_0* lbl_805A0EB8;

struct Class_8027D5EC {
    void* data;
    unsigned int flags;
    int count;
};

extern "C" {
Class_8027D5EC* __dt__14Class_8027D5ECFv(Class_8027D5EC* self, int flag) {
    if (self) {
        if ((self->flags & 0x80000000) == 0) {
            lbl_805A0EB8->slot5(self->data, (self->count + 1) * 16, 0x15);
        }
        if (flag > 0) {
            lbl_805A0EB8->slot5(self, 0xC, 0x1A);
        }
    }
    return self;
}
}
