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
struct Class_8027D5EC {
    void* unk0;
    int unk4;
    int unk8;
};
extern "C" void fn_8027DAC0(Class_8027D5EC*);
extern "C" Class_8027D5EC* __ct__14Class_8027D5ECFv(Class_8027D5EC* self) {
    self->unk0 = lbl_805A0EB8->slot4(0x100, 0x15);
    self->unk4 = 0;
    self->unk8 = 0xf;
    fn_8027DAC0(self);
    return self;
}