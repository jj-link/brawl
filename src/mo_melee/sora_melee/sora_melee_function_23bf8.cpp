#pragma force_active on
extern const float lbl_27_rodata_388[];

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
    virtual void call();
    float pad[23];
    float value;
};

extern "C" void fn_27_23BF8(Obj* self) {
    self->value = lbl_27_rodata_388[0];
    self->call();
}
