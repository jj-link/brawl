#pragma force_active on
extern "C" {

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;

class Class_CD28 {
public:
    virtual void fn_96_28D0();
    virtual void fn_96_2331C();
    virtual void fn_96_23D84();
    virtual void fn_96_23D7C();
    virtual void fn_96_23D74();
    virtual void fn_96_23D6C();
    virtual void fn_96_23D64();
    virtual void fn_96_23D5C();
    virtual void fn_96_23D54();
    virtual void fn_96_23D4C();
    virtual void fn_96_23D44();
    virtual void fn_96_23D3C();
    virtual void fn_96_23D34();
    virtual void fn_96_23D2C();
    virtual void fn_96_23CDC();
    virtual void fn_96_23D24();
    virtual void fn_96_23D14();
    virtual void fn_96_23D04();
    virtual void fn_96_23CF4();
    virtual void fn_96_23CE4();
};

struct Status {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int check();
};

struct Posture {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual float getValue();
};

struct Work {
    virtual void w0();
    virtual void w1();
    virtual void w2();
    virtual void w3();
    virtual void w4();
    virtual void w5();
    virtual void w6();
    virtual void w7();
    virtual void w8();
    virtual void w9();
    virtual void w10();
    virtual void w11();
    virtual void w12();
    virtual void w13();
    virtual void w14();
    virtual void w15();
    virtual void w16();
    virtual int isFlag(u32);
    virtual void onFlag(u32);
    virtual void offFlag(u32);
};

struct Link {
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual void l3();
    virtual void l4();
    virtual void l5();
    virtual void l6();
    virtual void l7();
    virtual void l8();
    virtual void l9();
    virtual void l10();
    virtual void l11();
    virtual void l12();
    virtual void l13();
    virtual void l14();
    virtual void set(u32, void*);
};

struct Kinetic {
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void* get(u32);
};

struct ModelPrefix {
    u32 pad[2];
};

struct Model : ModelPrefix {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void rotate(u32, float);
};

struct GroundPrefix {
    u32 pad[2];
};

struct GroundModule : GroundPrefix {
    virtual void g0();
    virtual void g1();
    virtual void g2();
    virtual void g3();
    virtual void g4();
    virtual void g5();
    virtual void g6();
    virtual void g7();
    virtual void g8();
    virtual void g9();
    virtual void g10();
    virtual void g11();
    virtual void g12();
    virtual void g13();
    virtual void g14();
    virtual void g15();
    virtual void g16();
    virtual void g17();
    virtual void g18();
    virtual void g19();
    virtual void g20();
    virtual void g21();
    virtual void g22();
    virtual void g23();
    virtual void g24();
    virtual void g25();
    virtual void g26();
    virtual void g27();
    virtual void g28();
    virtual void g29();
    virtual void g30();
    virtual void g31();
    virtual void g32();
    virtual void g33();
    virtual void g34();
    virtual void g35();
    virtual void g36();
    virtual void g37();
    virtual void g38();
    virtual void g39();
    virtual void g40();
    virtual void g41();
    virtual void g42();
    virtual void g43();
    virtual void g44();
    virtual void g45();
    virtual void g46();
    virtual void g47();
    virtual void g48();
    virtual void g49();
    virtual void g50();
    virtual void g51();
    virtual void g52();
    virtual void g53();
    virtual void g54();
    virtual int check(u32, u32);
};

struct Modules {
    u32 pad0;
    Model* model;
    u32 pad1;
    Posture* posture;
    GroundModule* ground;
    u32 pad2[16];
    Link* link;
    u32 pad3[3];
    Work* work;
    u32 pad4[2];
    Status* status;
    u32 pad5[2];
    Kinetic* kinetic;
};

struct Accesser {
    u8 pad[0xD8];
    Modules* modules;
};

struct LocalEvent {
    u32 id;
    u8 flag;
};

struct ObjectFlags {
    u8 enabled : 1;
    u8 remaining : 7;
};

extern const float lbl_96_rodata_5B4;
extern const float lbl_96_rodata_5B8;
extern const char lbl_96_data_CEF4[];
extern const char lbl_96_data_5E00[];

void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_96_2D960(void*, void*);

void fn_96_2D5C4(void* arg0, Accesser* arg1) {
    switch (arg1->modules->status->check()) {
    case 0:
        goto body;
    default:
        goto done;
    }

body:
    if (arg1->modules->posture->getValue() == lbl_96_rodata_5B4) {
        arg1->modules->model->rotate(1, lbl_96_rodata_5B8);
    }

    if (arg1->modules->work->isFlag(0x22000000) != 0) {
        if (arg1->modules->ground->check(4, 0) != 0) {
            arg1->modules->work->offFlag(0x22000000);

            LocalEvent event;
            event.id = 0x455;
            event.flag = 0;
            arg1->modules->link->set(1, &event);

            void* object = arg1->modules->kinetic->get(0);
            object = __dynamic_cast(
                object, 0, lbl_96_data_CEF4, lbl_96_data_5E00, 1);
            ((ObjectFlags*)((u8*)object + 5))->enabled = 0;

            arg1->modules->work->onFlag(0x22000002);
        }
    }

    if (arg1->modules->work->isFlag(0x22000002) != 0) {
        fn_96_2D960(arg0, arg1);
        arg1->modules->work->offFlag(0x22000002);
        arg1->modules->work->onFlag(0x22000003);
    }

done:
    ;
}

}
