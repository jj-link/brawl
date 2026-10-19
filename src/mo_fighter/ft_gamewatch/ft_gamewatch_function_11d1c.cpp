#pragma force_active on
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
    virtual float getFloat(int);
    virtual void setFloat(int, float);
};

struct MotionBase {
    char pad[8];
};

class Motion : public MotionBase {
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
    virtual void reset(int);
};

struct Modules {
    char pad0[0x38];
    Motion* motion;
    char pad1[0x28];
    Work* work;
};

struct Accesser {
    char pad[0xd8];
    Modules* modules;
};

extern "C" const float lbl_107_rodata_40[];

extern "C" void fn_107_11D1C(void*, Accesser* accesser) {
    Work* work = accesser->modules->work;
    float value = work->getFloat(0x21000004);
    if (lbl_107_rodata_40[0] != value) {
        accesser->modules->motion->reset(0);
        value = lbl_107_rodata_40[0];
    }
    work->setFloat(0x21000004, value);
}
