#include <mt/mt_vector.h>
#include <nw4r/math/math_arithmetic.h>
#pragma force_active on
#pragma fp_contract off
struct Owner;
struct Msg { int id; float a, b; unsigned char flags[4]; };
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(int);
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
    virtual void slot15();
    virtual void slot16();
    virtual int slot17(int);
    virtual void slot18(int);
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
};
class Posture {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual Vec3f slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual float slot9();
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
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
};
class Motion {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual int slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30(Msg*, float);
};
class Kinetic {
public:
    char pad[8];
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int, int);
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
};
class Ground {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
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
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
};
class Status {
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
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21(int, Owner*);
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
};

struct Modules {
    char pad0[8];
    Motion* motion;
    Posture* posture;
    Kinetic* kinetic;
    Ground* ground;
    char pad1[0x4c];
    Object_vptr_0* work;
    char pad2[0x14];
    Status* status;
};
struct Owner { char pad[0xd8]; Modules* modules; };
struct Local { int id, zero; float x, y, z; unsigned char flag; };
extern "C" void fn_27_1744D4(void*, Owner*);
extern "C" void fn_27_174C08(void*, Local*, Owner*);
extern float lbl_27_rodata_22CC;
extern float lbl_27_rodata_22D0;

extern "C" void fn_27_175F10(void* arg0, Owner* obj) {
    fn_27_1744D4(arg0, obj);
    Local local;
    local.id = 0x11;
    local.zero = 0;
    fn_27_174C08(arg0, &local, obj);
    obj->modules->work->slot13(0x21000004, local.x);
    obj->modules->work->slot13(0x21000005, local.y);
    if (local.flag == 1) obj->modules->work->slot18(0x22000010);
    switch (obj->modules->work->slot4(0x10000017)) {
    case 0x28:
    case 0x2a: {
        Vec3f pos = obj->modules->posture->slot4();
        float dx = local.x - pos.m_x;
        int motion;
        int status;
        if ((float)(double)nw4r::math::FAbs(dx) < lbl_27_rodata_22CC) {
            status = 0x32;
            if (obj->modules->work->slot17(0x22000010) == 0) {
                motion = 0xb;
                obj->modules->work->slot5(2, 0x20000000);
            } else {
                motion = 0;
                obj->modules->work->slot5(3, 0x20000000);
            }
        } else {
            if (dx * obj->modules->posture->slot9() < lbl_27_rodata_22D0) {
                motion = 0x11;
                status = 0x32;
                obj->modules->work->slot5(0, 0x20000000);
            } else {
                motion = 0xb;
                status = 0xe;
                obj->modules->work->slot5(1, 0x20000000);
            }
        }
        if (motion != obj->modules->motion->slot21()) {
            Msg msg;
            msg.id = motion;
            msg.a = lbl_27_rodata_22D0;
            msg.b = lbl_27_rodata_22CC;
            msg.flags[0] = 0;
            msg.flags[1] = 0;
            msg.flags[2] = 0;
            msg.flags[3] = 0;
            obj->modules->motion->slot30(&msg, lbl_27_rodata_22D0);
        }
        obj->modules->kinetic->slot19(2, 0);
        obj->modules->ground->slot6(0, 0);
        obj->modules->status->slot21(status, obj);
        break;
    }
    case 0x29: {
        Msg msg;
        msg.id = 0x38;
        msg.a = lbl_27_rodata_22D0;
        msg.b = lbl_27_rodata_22CC;
        msg.flags[0] = 0;
        msg.flags[1] = 0;
        msg.flags[2] = 0;
        msg.flags[3] = 0;
        obj->modules->motion->slot30(&msg, lbl_27_rodata_22D0);
        obj->modules->kinetic->slot19(5, 0);
        obj->modules->ground->slot6(2, 0);
        obj->modules->status->slot21(0x32, obj);
        break;
    }
    }
}
