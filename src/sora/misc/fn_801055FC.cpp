#pragma force_active on

struct Obj {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void f34(void*, void*);
    virtual void v12();
    virtual void f3c(void*);

    char pad[0xE0];
    void* fieldE4;
};

struct Outer {
    Obj* object;
    void* data;
};

extern "C" {
void fn_800B5854(void*, int, int, int, int);
void playSE__9sndSystemF5SndIDiiii(void*, int, int, int, int, int);
extern void* g_sndSystem;

void fn_801055FC(Outer* self) {
    char* r31 = (char*)self->data;
    self->object->f3c(*(void**)(r31 + 0x10));
    Obj* p = self->object;
    p->f34(p->fieldE4, *(void**)(r31 + 0x10));
    fn_800B5854(r31, 0, 1, 1, 0);
    playSE__9sndSystemF5SndIDiiii(g_sndSystem, 5, -1, 0, 0, -1);
}
}
