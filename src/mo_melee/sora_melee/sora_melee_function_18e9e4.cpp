#pragma force_active on
struct Vec2 {
    float x, y;
    Vec2();
    Vec2(const Vec2&);
};

class Work {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual int get(int);
    virtual void set(int, int);
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void setFloat(float, int);
};

class Ground {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual Vec2 get(int, int, int);
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual float getFloat(int);
};

class Posture {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void set(float);
    virtual void q0();
    virtual void q1();
    virtual void q2();
    virtual void q3();
    virtual void q4();
    virtual void q5();
    virtual void q6();
    virtual void q7();
    virtual void update();
};

struct ActorBase {
    char pad[0x3c];
};

class Actor : public ActorBase {
public:
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void call();
};

struct Modules {
    char pad[12];
    Posture* posture;
    char pad2[0x44];
    Ground* ground;
    char pad3[12];
    Work* work;
};

struct Access {
    char pad[8];
    Actor* actor;
    char pad2[0xcc];
    Modules* modules;
};

extern "C" int randi__Fl(long);
extern "C" void fn_27_89DAC(int, Access*);
extern "C" const int lbl_27_rodata_2600[7];

extern "C" void fn_27_18E9E4(void*, Access* a) {
    if (a->modules->work->get(0x20000001) == -1) {
        int i = randi__Fl(7);
        if (i < 0 || i >= 7)
            i = 0;
        a->modules->work->set(lbl_27_rodata_2600[i], 0x20000001);
    }

    Posture* p = a->modules->posture;
    p->set(-a->modules->ground->getFloat(4));
    a->modules->posture->update();
    a->actor->call();
    fn_27_89DAC(3, a);

    Vec2 v = a->modules->ground->get(4, 0, 0);
    a->modules->work->setFloat(v.x, 0x21000004);
    a->modules->work->setFloat(v.y, 0x21000005);
}
