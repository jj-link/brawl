#pragma force_active on

extern "C" void* __dynamic_cast(void*, long, const void*, const void*, short);
extern "C" char lbl_27_data_2E380[];
extern "C" char lbl_27_data_CDF8[];
extern "C" const float lbl_27_rodata_2070;
extern "C" const float lbl_27_rodata_2074;
extern "C" void fn_27_15CF5C(void*, float);

struct Vec2 {
    float x;
    float y;
    Vec2() {}
    Vec2(const Vec2& v) : x(v.x), y(v.y) {}
};

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
    virtual void* slot6(int);
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float slot12(unsigned long);
    virtual void slot13(unsigned long, float, void*);
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual void slot17();
    virtual void slot18(unsigned long);
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
    virtual void slot30();
    virtual void slot31();
    virtual int slot32(int);
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38(int, float);
};

class PosModule {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec2 slot4();
};

class AudienceSub {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9(int, float);
};

struct AudMgr {
    char pad[8];
    AudienceSub* sub;
};

extern AudMgr* g_ftAudienceManager;

struct Modules {
    char pad0[0xc];
    PosModule* pos;
    char pad10[0x54];
    Object_vptr_0* m64;
    char pad68[0x8];
    Object_vptr_0* m70;
    char pad74[0x8];
    Object_vptr_0* m7C;
    char pad80[0x8];
    Object_vptr_0* m88;
};

struct Obj {
    char pad[0xd8];
    Modules* modules;
};

extern "C" void fn_27_1670C0(void* self, Obj* obj) {
    float f;
    int r;
    int r30;
    Modules* m;

    r = obj->modules->m70->slot16();
    switch (r) {
    case 14:
        obj->modules->m64->slot5(0x21, 0x20000000);
        obj->modules->m64->slot5(0x22, 0x20000001);
        break;
    case 15:
        obj->modules->m64->slot5(0x24, 0x20000000);
        obj->modules->m64->slot5(0x25, 0x20000001);
        break;
    case 16:
        obj->modules->m64->slot5(0x27, 0x20000000);
        obj->modules->m64->slot5(0x28, 0x20000001);
        r30 = obj->modules->m64->slot4(0x10000000);
        {
            Vec2 v = obj->modules->pos->slot4();
            g_ftAudienceManager->sub->slot9(r30, v.y);
        }
        obj->modules->m88->slot38(0x18, lbl_27_rodata_2070);
        break;
    }
    obj->modules->m64->slot5(-1, 0x20000002);
    m = obj->modules;
    float c = lbl_27_rodata_2070;
    m->m64->slot13(0x21000004, c, m);
    f = obj->modules->m64->slot12(0x11000001);
    if (lbl_27_rodata_2074 != f) {
        fn_27_15CF5C(__dynamic_cast(obj->modules->m7C->slot6(2), 0, lbl_27_data_2E380, lbl_27_data_CDF8, 1), f);
    }
    r = obj->modules->m70->slot32(0);
    if (r == 1 || (unsigned long)(r - 3) <= 1) {
        obj->modules->m64->slot18(0x22000010);
    }
}
