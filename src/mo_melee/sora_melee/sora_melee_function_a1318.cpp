#pragma force_active on
typedef unsigned int u32;
typedef unsigned char u8;

struct Obj {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void pad9();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual u8* get(u32);
};

extern "C" void fn_27_A1318(Obj* self, u32 ignored, u32 index) {
    u8* first = self->get(ignored);
    u8* second = self->get(index);
    *second = *first;
}
