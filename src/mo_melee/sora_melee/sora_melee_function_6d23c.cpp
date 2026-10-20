#pragma force_active on
struct TargetBase {
    char padding[8];
};

struct Target : TargetBase {
    virtual void dummy0();
    virtual void dummy1();
    virtual void dummy2();
    virtual void dummy3();
    virtual void dummy4();
    virtual void dummy5();
    virtual void dummy6();
    virtual void dummy7();
    virtual void dummy8();
    virtual void call(int, unsigned int, int);
};

struct Holder {
    Target* target;
};

struct Modules {
    char padding[0xD8];
    Holder* holder;
};

struct Object {
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
    virtual void dummy49();
    virtual void dummy50();
    virtual void call(int, int);

    char padding[0x3C];
    int index;
    Modules* modules;
};

extern "C" void fn_27_6D23C(Object* self, int value) {
    if (self->index != -1) {
        self->call(self->index, value);
    } else {
        self->modules->holder->target->call(value, 0xFFFF, 0);
    }
}
