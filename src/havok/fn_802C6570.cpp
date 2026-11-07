#pragma force_active on
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4(unsigned int);
};
class Class_804870B8 {
public:
    virtual void fn_802C65E4(int);
    virtual void fn_80080A64();
    virtual void fn_802C6E20();
    virtual void fn_802C6930();
    virtual void fn_802B7A14();
    int unk4;
    Object_vptr_0* unk8;
    unsigned short unkC;
};
extern "C" void fn_802C6570(Class_804870B8* self) {
    unsigned int id = self->unkC;
    if (id != 0xFFFF) {
        self->unk8->slot4(id);
        self->unkC = 0xFFFF;
    }
    if (self != 0) {
        self->fn_802C65E4(1);
    }
}