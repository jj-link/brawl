#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(unsigned long, int);
};

extern Object_vptr_0* lbl_805A0EB8;
extern "C" void fn_8027D438(void*);

struct Class_8027D01C {
    void* unk0;
    int unk4;
    int unk8;
};

extern "C" Class_8027D01C* __ct__14Class_8027D01CFv(Class_8027D01C* self) {
    self->unk0 = lbl_805A0EB8->slot4(0x80, 0x15);
    self->unk4 = 0;
    self->unk8 = 15;
    fn_8027D438(self);
    return self;
}
