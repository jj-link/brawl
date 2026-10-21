#pragma force_active on

extern "C" void fn_27_1DA030(void*);
extern float lbl_27_rodata_6558;

struct MotionRequest {
    int id;
    float frame;
    float rate;
    unsigned char a, b, c, d;
};

class WorkModule {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual int get(int) = 0;
    virtual void set(int, int) = 0;
};

class MotionModule {
public:
    virtual void v0() = 0;
    virtual void v1() = 0;
    virtual void v2() = 0;
    virtual void v3() = 0;
    virtual void v4() = 0;
    virtual void v5() = 0;
    virtual void v6() = 0;
    virtual void v7() = 0;
    virtual void v8() = 0;
    virtual void v9() = 0;
    virtual void v10() = 0;
    virtual void v11() = 0;
    virtual float frame() = 0;
    virtual void v13() = 0;
    virtual void v14() = 0;
    virtual void v15() = 0;
    virtual void v16() = 0;
    virtual void v17() = 0;
    virtual void v18() = 0;
    virtual void v19() = 0;
    virtual void v20() = 0;
    virtual void v21() = 0;
    virtual void v22() = 0;
    virtual void v23() = 0;
    virtual void v24() = 0;
    virtual void v25() = 0;
    virtual void v26() = 0;
    virtual void v27() = 0;
    virtual void v28() = 0;
    virtual void v29() = 0;
    virtual void apply(MotionRequest*) = 0;
};

struct Modules {
    char pad0[8];
    MotionModule* motion;
    char padC[0x58];
    WorkModule* work;
};

struct Owner {
    char pad[0xD8];
    Modules* modules;
};

struct Fighter {
    char pad[0x60];
    Owner* owner;
};

extern "C" void fn_27_303DC4(Fighter* self) {
    fn_27_1DA030(self);
    int id = self->owner->modules->work->get(0x10000005);
    if (id != -1) {
        float frame = self->owner->modules->motion->frame();
        MotionRequest request;
        request.id = id;
        request.frame = frame;
        request.rate = lbl_27_rodata_6558;
        request.a = 0;
        request.b = 0;
        request.c = 1;
        request.d = 0;
        self->owner->modules->motion->apply(&request);
        self->owner->modules->work->set(-1, 0x10000005);
    }
}
