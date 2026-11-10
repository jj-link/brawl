#include <types.h>
#pragma force_active on

extern "C" {
extern const char lbl_94_data_4794[], lbl_94_data_5010[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
int fn_27_111364(void*);
void fn_27_2F36CC(void*, int, int, int, float);
}

#define V8(n) \
    virtual void n##0(); virtual void n##1(); \
    virtual void n##2(); virtual void n##3(); \
    virtual void n##4(); virtual void n##5(); \
    virtual void n##6(); virtual void n##7();

class Resource {
public:
    V8(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual float b4(unsigned int);
};

class FinalObj;

class ModObj {
public:
    char pad[8];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual FinalObj* m4();
};

class FinalObj {
public:
    V8(a)
    virtual void b0();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual int b7();
};

class Fighter {
public:
    char pad0[0x28];
    unsigned int taskId;
    char pad2c[0x10];
    V8(a) V8(b) V8(c) V8(d) V8(e) V8(f) V8(g) V8(h) V8(i) V8(j)
    V8(k) V8(l) V8(m) V8(n) V8(o) V8(p) V8(q) V8(r) V8(s) V8(t)
    V8(u) V8(v) V8(w)
    virtual void x0();
    virtual void* x1();
};

struct Modules {
    ModObj* modobj;
    char pad[0x60];
    Resource* resource;
};

struct Accesser {
    char pad[8];
    void* stageObject;
    char pad0c[0xcc];
    Modules* modules;
};

extern "C" int fn_94_9BC4(void* arg0, Accesser* arg1) {
    Fighter* fighter = static_cast<Fighter*>(__dynamic_cast(
        arg1->stageObject, 0x3c, lbl_94_data_4794, lbl_94_data_5010, 1));
    Modules* modules = arg1->modules;
    ModObj* modobj = modules->modobj;
    unsigned int taskId = fighter->taskId;
    float value = modules->resource->b4(0x21000004);
    void* owner = fighter->x1();
    int ownerId = fn_27_111364(owner);
    FinalObj* t = modobj->m4();
    int r5 = t->b7();
    fn_27_2F36CC(arg0, taskId, r5, ownerId, value);
    return 1;
}
#undef V8