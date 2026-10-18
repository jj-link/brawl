#include <mt/mt_vector.h>
#pragma force_active on

struct Flags {
    unsigned char first : 1, second : 1, third : 1, fourth : 1;
    unsigned char fifth : 1, sixth : 1, seventh : 1, eighth : 1;
    unsigned char ninth : 1, tenth : 1, reserved : 6;
};

struct Param {
    int resource, team, teamOwner, teamAnother, index, owner;
    int reserved0, reserved1;
    Vec3f position;
    float facing;
    int parameter, variant, situation, status, reserved2, motion, reserved3;
    Flags flags;
};

struct Module {
    int a, b;
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
    virtual void* get(int);
    virtual void pad44();
    virtual void pad48();
    virtual void pad4c();
    virtual void set(int);
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void q8();
    virtual void q9();
    virtual void q10();
    virtual void q11();
    virtual void q12();
    virtual void q13();
    virtual void q14();
    virtual void q15();
    virtual void q16();
    virtual void q17();
    virtual void q18();
    virtual void q19();
    virtual void q20();
    virtual void q21();
    virtual void q22();
    virtual void q23();
    virtual void q24();
    virtual void q25();
    virtual void q26();
    virtual void q27();
    virtual void q28();
    virtual void q29();
    virtual void q30();
    virtual void q31();
    virtual void q32();
    virtual void q33();
    virtual void q34();
    virtual void q35();
    virtual void q36();
    virtual void setFloat(float);
};

struct Other {
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
    virtual void pad19();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad40();
    virtual void pad41();
    virtual void pad42();
    virtual void pad43();
    virtual void pad44();
    virtual void pad45();
    virtual void pad46();
    virtual void pad47();
    virtual void pad48();
    virtual void pad49();
    virtual void pad50();
    virtual void pad51();
    virtual void set(int);
};

struct Modules {
    char pad[4];
    Module* module;
    char pad8[0x80];
    Other* other;
};

struct Access {
    char pad[0xd8];
    Modules* modules;
};

struct Object {
    char pad[0x60];
    Access* access;
};

extern "C" {
extern const float lbl_27_rodata_8024;
extern const float lbl_27_rodata_8028;
void fn_27_1D8370(void*, const Param*);
void fn_801AAFF0(void*, int);
void* __memcpy(void*, const void*, unsigned long);

void fn_27_3BA478(Object* object, int resource, int team, int parameter) {
    Param p;
    p.resource = resource;
    p.team = team;
    p.teamOwner = team;
    p.teamAnother = team;
    p.index = -1;
    p.owner = -1;
    p.reserved0 = 0;
    p.reserved1 = 0;

    Vec3f position;
    position.m_x = lbl_27_rodata_8024;
    position.m_y = lbl_27_rodata_8024;
    position.m_z = lbl_27_rodata_8024;
    __memcpy(&p.position, &position, sizeof(Vec3f));

    p.facing = lbl_27_rodata_8024;
    p.parameter = parameter;
    p.variant = 0;
    p.situation = 2;
    p.status = 0x80;
    p.reserved2 = 0;
    p.motion = 0x35f;
    p.reserved3 = 0;
    p.flags.first = 1;
    p.flags.second = 1;
    p.flags.third = 0;
    p.flags.fourth = 0;
    p.flags.fifth = 1;
    p.flags.sixth = 0;
    p.flags.seventh = 0;
    p.flags.eighth = 0;
    p.flags.ninth = 0;
    p.flags.tenth = 0;

    fn_27_1D8370(object, &p);

    Module* m = object->access->modules->module;
    void* result = m->get(0);
    if (result)
        fn_801AAFF0(result, 255);

    m = object->access->modules->module;
    m->set(5);

    m = object->access->modules->module;
    m->setFloat(lbl_27_rodata_8028);

    Other* o = object->access->modules->other;
    o->set(1);
}
}
