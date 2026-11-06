#pragma force_active on

class Object;
class soNullable {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3(int, Object*);
    virtual int slot4(unsigned int);
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26(int);
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
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
    virtual int slot49(int);
    virtual void slot50();
    virtual float slot51(int);
};
class Status {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual void slot4();
    virtual int slot5();
};
class Work {
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
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual float get(unsigned int);
};
struct Modules {
    char pad0[0x14];
    Status* m14;
    char pad18[0x44];
    soNullable* m5c;
    char pad60[4];
    Work* m64;
    char pad68[8];
    soNullable* m70;
};
class Object {
public:
    char pad[0xd8];
    Modules* modules;
};
extern float lbl_27_rodata_24BC;

extern "C" void fn_27_186560(void*, Object* obj) {
    if (obj->modules->m5c->slot51(0) <= lbl_27_rodata_24BC) {
        obj->modules->m70->slot3(0x40, obj);
    } else {
        if (obj->modules->m14->slot5() != 0) {
            float f31 = obj->modules->m5c->slot51(0);
            float var;
            if (obj->modules->m14->slot3() == 0) {
                var = obj->modules->m64->get(0x21000005) - f31;
                var = obj->modules->m64->get(0x21000004) - var;
            } else {
                var = obj->modules->m64->get(0x21000004) - f31;
                var = obj->modules->m64->get(0x21000005) - var;
            }
            if (var <= lbl_27_rodata_24BC) {
                obj->modules->m70->slot3(0x40, obj);
            } else {
                obj->modules->m5c->slot49(0);
            }
        }
    }
}