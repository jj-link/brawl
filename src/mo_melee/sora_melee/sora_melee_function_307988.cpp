#pragma force_active on

struct V3 {
    float x, y, z;
};

struct Info {
    int a;
    bool b;
    int c;

    Info() : a(0x1f), b(false), c(-1) {}
};

#define V8(n) \
    virtual void n##0(); \
    virtual void n##1(); \
    virtual void n##2(); \
    virtual void n##3(); \
    virtual void n##4(); \
    virtual void n##5(); \
    virtual void n##6(); \
    virtual void n##7();

class soNullable {
public:
    virtual void isNull();
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
    virtual void slot16(int, Info*, int);
    virtual void slot17();
    virtual void slot18();
    virtual int slot19(int);
};

class Status {
public:
    V8(a)
    V8(b)
    virtual int slot16();
};

class Model {
public:
    char pad[8];
    V8(a)
    V8(b)
    V8(c)
    V8(d)
    virtual void q0();
    virtual int q1(int);
    virtual void q2();
    virtual void q3();
    virtual V3 getPos(int, int);
};

class Posture {
public:
    V8(a)
    virtual void q();
    virtual float get();
};

class ResourceId {
public:
    virtual void a();
    virtual void b();
    virtual int get();
};

class Resource {
public:
    virtual void a();
    virtual void b();
    virtual ResourceId* get();
};

struct Modules {
    char p0[4];
    Model* model;
    char p1[4];
    Posture* posture;
    char p2[8];
    Resource* resource;
    char p3[0x38];
    soNullable* hit;
    char p4[0x18];
    Status* status;
};

struct Owner {
    char pad[0x28];
    int id;
};

struct Context {
    char p0[8];
    Owner* owner;
    char p1[0xcc];
    Modules* modules;
};

extern unsigned char lbl_27_bss_7B0C[];
extern const float lbl_27_rodata_6578;

extern "C" int fn_27_30FA2C(void*, int, int, Context*, int);
extern "C" void fn_27_30AD98(int, int, int, int, V3*, int, float);

extern "C" int fn_27_307988(void*, int arg1, Context& ctx, int arg3) {
    Resource* resource;
    unsigned long task;
    int id = -1;
    int status = fn_27_30FA2C(lbl_27_bss_7B0C, 0, 0x118, &ctx, 0);

    V3 pos;
    pos.x = lbl_27_rodata_6578;
    pos.y = lbl_27_rodata_6578;
    pos.z = lbl_27_rodata_6578;

    if (status == ctx.modules->status->slot16()) {
        task = ctx.modules->hit->slot19(0);
        Info info;
        ctx.modules->hit->slot16(0, &info, 0);
        id = info.c;
    } else {
        pos = ctx.modules->model->getPos(
            ctx.modules->model->q1(0x131), 0);
        task = ctx.owner->id;
    }

    resource = ctx.modules->resource;
    float direction = ctx.modules->posture->get();
    fn_27_30AD98(arg1, task, arg3, resource->get()->get(), &pos, id, direction);
    return 1;
}
