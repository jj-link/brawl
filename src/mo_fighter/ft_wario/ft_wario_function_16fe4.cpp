#include <so/so_module_accesser.h>

#pragma force_active on

struct Vec2Words {
    float x;
    float y;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
extern const unsigned char lbl_110_data_5EF0[];
extern const unsigned char lbl_110_data_212C[];
float fn_110_1526C(Vec2Words*);
void fn_110_1619C(void*, soModuleAccesser*);
}

struct AttackCallView {
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual void a3();
    virtual void a4();
    virtual void f7(unsigned long);
    virtual void a6();
    virtual void a7();
    virtual void f10(int, int);
    virtual void a9();
    virtual void a10();
    virtual void a11();
    virtual void a12();
    virtual void a13();
    virtual int f16(int, bool, float);
    virtual void a15();
    virtual void a16();
    virtual void a17();
    virtual void a18();
    virtual void a19();
    virtual void a20();
    virtual void a21();
    virtual void a22();
    virtual void a23();
    virtual void a24();
    virtual void a25();
    virtual void a26();
    virtual void a27();
    virtual void a28();
    virtual void a29();
    virtual void a30();
    virtual void a31();
    virtual void a32();
    virtual void a33();
    virtual void a34();
    virtual void a35();
    virtual void a36();
    virtual void a37();
    virtual void a38();
    virtual void a39();
    virtual void a40();
    virtual void a41();
    virtual void a42();
    virtual void a43();
    virtual void a44();
    virtual void a45();
    virtual void a46();
    virtual void a47();
    virtual void f50(float);
};

inline int attackTest(AttackCallView* attack, int zero, float value) {
    return attack->f16(zero, zero, value);
}

struct WorkCallView {
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual void b8();
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual void b15();
    virtual void b16();
    virtual int f19(unsigned long);
    virtual void f20(unsigned long);
    virtual void f21(unsigned long);
};

struct KineticCallView {
    virtual void k0();
    virtual void k1();
    virtual void k2();
    virtual void k3();
    virtual void k4();
    virtual void k5();
    virtual void k6();
    virtual void k7();
    virtual void k8();
    virtual void k9();
    virtual void k10();
    virtual void k11();
    virtual void k12();
    virtual Vec2Words f15(short&);
};

struct WarioEnumLayout {
    char pad0[0x1C];
    AttackCallView* attack;
    char pad1[0x44];
    WorkCallView* work;
    char pad2[0x14];
    KineticCallView* kinetic;
};

struct WarioParam {
    float pad0[3];
    float start;
    float pad1[8];
    float scale;
    float end;
};

struct WarioView {
    unsigned char prefix[0x2980];
    const WarioParam* param;
};

extern "C" void fn_110_16FE4(void* arg0, soModuleAccesser* arg1) {
    const WarioEnumLayout* en =
        reinterpret_cast<const WarioEnumLayout*>(arg1->m_enumerationStart);
    WorkCallView* work = en->work;
    KineticCallView* kinetic = en->kinetic;
    AttackCallView* attack = en->attack;
    const WarioParam* param = reinterpret_cast<WarioView*>(
        __dynamic_cast(arg1->m_stageObject, 0x3C,
                       lbl_110_data_5EF0, lbl_110_data_212C, 1))->param;

    short flag = 1;
    Vec2Words vector = kinetic->f15(flag);
    float length = fn_110_1526C(&vector);
    int zero = 0;

    if (length <= param->end) {
        if (attackTest(attack, zero, length)) {
            attack->f7(0);
            work->f20(0x2200000A);
        }
    } else {
        float t = (length - param->end) / (param->start - param->end);
        float scaled = param->scale * t;

        if (attackTest(attack, zero, t)) {
            attack->f50(scaled);
        } else if (work->f19(0x2200000A)) {
            attack->f10(0, 0);
            attack->f50(scaled);
            work->f21(0x2200000A);
        }
    }

    fn_110_1619C(arg0, arg1);
}
