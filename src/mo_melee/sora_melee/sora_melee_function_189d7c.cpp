#pragma force_active on

extern "C" const float lbl_27_rodata_251C;
extern "C" bool fn_27_194724(void*, int);

struct Module {
    virtual void unused0();
    virtual void unused1();
    virtual void unused2();
    virtual void unused3();
    virtual void unused4();
    virtual void unused5();
    virtual void unused6();
    virtual void unused7();
    virtual void unused8();
    virtual void unused9();
    virtual void unused10();
    virtual void unused11();
    virtual void unused12();
    virtual void unused13();
    virtual void unused14();
    virtual void unused15();
    virtual int get(int);
    virtual void unused17();
    virtual void unused18();
    virtual void unused19();
    virtual void unused20();
    virtual void unused21();
    virtual void unused22();
    virtual void unused23();
    virtual void unused24();
    virtual void unused25();
    virtual void unused26();
    virtual void unused27();
    virtual void unused28();
    virtual void unused29();
    virtual void unused30();
    virtual void unused31();
    virtual void unused32();
    virtual void unused33();
    virtual void unused34();
    virtual void unused35();
    virtual void unused36();
    virtual void unused37();
    virtual void unused38();
    virtual void change(int);
    virtual void set(int, float, int);
    virtual void unused41();
    virtual void unused42();
    virtual void unused43();
    virtual void unused44();
    virtual void unused45();
    virtual void unused46();
    virtual void unused47();
    virtual void unused48();
    virtual void unused49();
    virtual void unused50();
    virtual void unused51();
    virtual void unused52();
    virtual void unused53();
    virtual void unused54();
    virtual void unused55();
    virtual void enable(int, bool);
};

struct Modules {
    char pad0[0x5C];
    Module* module5C;
    char pad1[0x88 - 0x60];
    Module* module88;
    char pad2[0xA8 - 0x8C];
    Module* moduleA8;
};

struct Object {
    char pad[0xD8];
    Modules* modules;
};

extern "C" void fn_27_189D7C(void*, Object* object, int id) {
    if (fn_27_194724(object, id) == 0) {
        if (object->modules->moduleA8->get(0) == 0x1D) {
            object->modules->moduleA8->set(2, lbl_27_rodata_251C, 0);
            object->modules->module88->change(0x14);
        } else {
            object->modules->moduleA8->set(2, lbl_27_rodata_251C, 0);
            object->modules->module88->change(0x15);
        }
        object->modules->module5C->enable(2, true);
    }
}
