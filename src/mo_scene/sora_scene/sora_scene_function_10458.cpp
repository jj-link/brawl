#pragma force_active on

struct SubObject {
    virtual void pad0();
    virtual void pad1();
    virtual void pad2();
    virtual void pad3();
    virtual void pad4();
    virtual void pad5();
    virtual void pad6();
    virtual void pad7();
    virtual void pad8();
    virtual void call();
};

struct Scene {
    char pad0[8];
    void* task;
    char padC[4];
    SubObject object;
};

extern "C" {
void exit__6gfTaskFv(void*);
extern void* g_sndSystem;
void fn_80073F84(void*, int);

int fn_1_10458(Scene* self) {
    self->object.call();
    exit__6gfTaskFv(self->task);
    self->task = 0;
    fn_80073F84(g_sndSystem, 0);
    return 0;
}
}
