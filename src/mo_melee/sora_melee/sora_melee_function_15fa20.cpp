#pragma force_active on

typedef unsigned char u8;

struct Data {
    u8 pad[5];
    u8 flag : 1;
    u8 rest : 7;
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual Data* slot6(unsigned);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(float, unsigned);
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual unsigned slot17(unsigned);
};

struct Modules {
    char pad[0x64];
    Object_vptr_0* work;
    char pad68[0x14];
    Object_vptr_0* accessor;
};

struct Object {
    char pad[0xd8];
    Modules* modules;
};

struct Speed {
    unsigned x;
    unsigned y;
};

extern "C" {
Speed fn_27_164B10(Object*, bool, bool);
void fn_27_15FBC8(int, int, Speed*, Object*);
extern const float lbl_27_rodata_1FC0;
}

extern "C" void fn_27_15FA20(int kind, int reset, Object* a) {
    if (kind > -1) {
        if (kind < 0x52) goto valid;
    }
    return;
valid:
    {
        Speed speed;
        Speed returned = fn_27_164B10(a, true, kind != 0x31);
        speed = returned;
        fn_27_15FBC8(kind, reset, &speed, a);

        if (a->modules->work->slot17(0x2200000d) == 1U) {
            Data* p = a->modules->accessor->slot6(5);
            p->flag = 0;
            Data* q = a->modules->accessor->slot6(7);
            q->flag = 0;
        } else {
            Data* p = a->modules->accessor->slot6(5);
            p->flag = 1;
            Data* q = a->modules->accessor->slot6(7);
            q->flag = 1;
        }

        a->modules->work->slot13(lbl_27_rodata_1FC0, 0x1100000f);
        a->modules->work->slot13(lbl_27_rodata_1FC0, 0x11000010);
    }
}
