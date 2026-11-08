#pragma force_active on
#include <so/so_value_accesser.h>

struct Vec3 {
    float x, y, z;
    Vec3() {}
    Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Position {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual Vec3 get();
    virtual void set(const Vec3*);
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int, int);
    virtual void slot5(int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13(int, float);
    virtual void slot14();
    virtual void slot15(int, int);
    virtual int slot16();
    virtual void slot17();
    virtual void slot18(int, int);
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(int, float);
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43();
    virtual void slot44();
    virtual void slot45();
    virtual void slot46();
    virtual void slot47();
    virtual void slot48();
    virtual void slot49();
    virtual void slot50();
    virtual void slot51();
    virtual void slot52();
    virtual void slot53();
    virtual void slot54();
    virtual void slot55();
    virtual void slot56();
    virtual void slot57();
    virtual void slot58();
    virtual void slot59();
    virtual void slot60();
    virtual void slot61();
    virtual void slot62();
    virtual void slot63();
    virtual void slot64();
    virtual void slot65();
    virtual void slot66();
    virtual void slot67();
    virtual void slot68();
    virtual void slot69();
    virtual void slot70(int, int);
    virtual void slot71();
    virtual void slot72();
    virtual void slot73();
    virtual void slot74();
    virtual void slot75(int, int, int, int, int);
};

struct Modules {
    char pad0[8];
    Object_vptr_0* m8;
    Position* pos;
    char pad10[0x44];
    Object_vptr_0* m54;
    char pad58[0xc];
    Object_vptr_0* m64;
    char pad68[8];
    Object_vptr_0* work;
};

struct Access {
    char pad[8];
    int obj;
    char padC[0xcc];
    Modules* modules;
};

struct Out {
    int kind;
    unsigned char a;
    unsigned char flag;
    unsigned char c;
    int b;
    float x, y, z;
};

struct Out2 {
    int kind;
    float x, y;
    char p0, p1, p2, p3;
};

extern "C" {
    extern float lbl_27_rodata_2248;
    extern float lbl_27_rodata_224C;
}

extern "C" void fn_27_170DC4(void* self, Access* acc) {
    switch (acc->modules->work->slot16()) {
    case 0x6d:
        if (acc->modules->m54->slot4(3, acc->modules->m64->slot4(0x10000007, (int)acc->modules)) != 0) {
            Vec3 v = acc->modules->pos->get();
            Out out;
            out.kind = 6;
            out.a = 0;
            out.z = lbl_27_rodata_2248;
            out.flag = 0;
            out.b = 0;
            out.x = v.x;
            out.y = v.y;
            acc->modules->m54->slot15(3, (int)&out);
            if (out.flag == 1) {
                Out2 s;
                s.kind = 0x34;
                s.x = lbl_27_rodata_224C;
                s.y = lbl_27_rodata_2248;
                s.p0 = 0;
                s.p1 = 0;
                s.p2 = 0;
                s.p3 = 0;
                acc->modules->m8->slot30((int)&s, lbl_27_rodata_224C);
                acc->modules->m54->slot75(3, 0, out.b, 5, 1);
                acc->modules->m54->slot70(3, acc->obj);
            } else {
                acc->modules->m64->slot18(0x22000010, (int)acc->modules);
                v.x = out.x;
                v.y = out.y;
                acc->modules->pos->set(&v);
            }
            if (out.c == 0) {
                acc->modules->m64->slot5(0, 0x10000005);
            }
            acc->modules->m64->slot13(0x21000004, out.z);
        }
        break;
    case 0x71:
        acc->modules->m64->slot5((int)soValueAccesser::getConstantFloat((soModuleAccesser*)acc, 0xbcd, 0), 0x20000001);
        break;
    }
}
