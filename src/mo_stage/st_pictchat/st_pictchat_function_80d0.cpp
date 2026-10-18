#pragma force_active on
extern "C" void processAnim__6GroundFv(void*);
extern "C" char lbl_73_data_11E8[];
extern "C" char lbl_73_data_11F0[];

struct Base {
    char pad[0x3C];
};

struct Obj : Base {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void dummy9();
    virtual void dummy10();
    virtual void dummy11();
    virtual void dummy12();
    virtual void dummy13();
    virtual void dummy14();
    virtual void dummy15();
    virtual void dummy16();
    virtual void dummy17();
    virtual void dummy18();
    virtual void dummy19();
    virtual void dummy20();
    virtual void dummy21();
    virtual void dummy22();
    virtual void dummy23();
    virtual void dummy24();
    virtual void dummy25();
    virtual void dummy26();
    virtual void dummy27();
    virtual void dummy28();
    virtual void dummy29();
    virtual void dummy30();
    virtual void dummy31();
    virtual void dummy32();
    virtual void dummy33();
    virtual void dummy34();
    virtual void dummy35();
    virtual void dummy36();
    virtual void dummy37();
    virtual void dummy38();
    virtual void dummy39();
    virtual void dummy40();
    virtual void dummy41();
    virtual void dummy42();
    virtual void dummy43();
    virtual void dummy44();
    virtual void dummy45();
    virtual void dummy46();
    virtual void dummy47();
    virtual void dummy48();
    virtual void call(void*, int, const char*);

    char pad2[0x254];
    char* data;
};

extern "C" void fn_73_80D0(Obj* self) {
    processAnim__6GroundFv(self);
    if (self->data) {
        self->call(self->data, 0, lbl_73_data_11E8);
        self->call(self->data + 12, 0, lbl_73_data_11F0);
    }
}
