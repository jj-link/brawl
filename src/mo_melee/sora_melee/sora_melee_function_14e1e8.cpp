#pragma force_active on
struct Col { unsigned char r, g, b, a; };

class Obj {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void set(int i, Col c);
};

extern "C" void fn_27_A3D5C(void*);

extern "C" void fn_27_14E1E8(Obj* self) {
    fn_27_A3D5C(self);
    Col c;
    c.r = 0x40; c.g = 0x80; c.b = 0xC0; c.a = 0x80;
    self->set(1, c);
    self->set(2, c);
    c.r = 0xFF; c.g = 0x80; c.b = 0; c.a = 0x40;
    self->set(4, c);
    self->set(5, c);
    c.r = 0x40; c.g = 0xD0; c.b = 0x40; c.a = 0x10;
    self->set(6, c);
    self->set(7, c);
}
