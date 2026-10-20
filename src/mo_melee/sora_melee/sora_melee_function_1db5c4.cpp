#pragma force_active on
struct MotionModule;
struct WorkModule;

struct MotionModule {
    char padding[8];
    virtual void f00(); virtual void f01(); virtual void f02();
    virtual void f03(); virtual void f04(); virtual void f05();
    virtual void f06(); virtual void f07(); virtual void f08();
    virtual void f09(); virtual void f10(); virtual void f11();
    virtual void f12(); virtual void f13(); virtual void f14();
    virtual void f15(); virtual void f16(); virtual void f17();
    virtual void f18();
    virtual void reset(int, int, int);
};
struct WorkModule {
    virtual void f0(); virtual void f1(); virtual void f2();
    virtual void f3(); virtual void f4();
    virtual void clear(int, int);
};

struct Modules {
    char padding0[0x10];
    MotionModule* motion;
    char padding1[0x50];
    WorkModule* work;
};

struct Fighter {
    char padding[0xd8];
    Modules* modules;
};

struct State {
    char padding0[0x60];
    Fighter* fighter;
    char padding1[0x44];
    int counter;
};

extern "C" void fn_27_1DB5C4(State* state) {
    Fighter* fighter = state->fighter;
    int previousCounter = state->counter++;

    MotionModule* motion = fighter->modules->motion;
    motion->reset(0, 0, previousCounter);
    WorkModule* work = fighter->modules->work;
    work->clear(0x10000003, 0x10000004);
}
