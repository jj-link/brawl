#pragma force_active on
extern "C" {
extern char lbl_27_data_907A8[];
extern char lbl_27_data_248[];
extern const char lbl_27_rodata_7AD8[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

struct Vec3 { float x, y, z; Vec3() {} Vec3(float a, float b, float c) : x(a), y(b), z(c) {} Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {} };

struct A {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void set(int, unsigned long);
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual float get(unsigned long);
};

struct P {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual Vec3 get();
};

struct E {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void emit(unsigned long, const Vec3&, const Vec3&, int, int, float);
};

struct Info { float a; char pad[0x24]; float b; float c; };
struct Mod { char pad[0x1fe4]; Info* info; };
struct D { char pad0[0xc]; P* p; char pad1[0x54]; A* a; char pad2[0x20]; E* e; };
struct Obj { char pad[8]; void* m; char pad2[0xcc]; D* d; };

extern "C" void fn_27_363EB0(void*, Obj* obj) {
    const float* k = (const float*)lbl_27_rodata_7AD8;
    D* d = obj->d;
    A* a = d->a;
    P* p = d->p;
    float t = a->get(0x21000001);
    Info* info = ((Mod*)__dynamic_cast(obj->m, 0x3c, lbl_27_data_907A8, lbl_27_data_248, 1))->info;
    float r = t / info->a;
    if (!(r > k[0])) {
        if (r < k[1]) r = k[1];
    }
    E* e = obj->d->e;
    e->emit(0x1b000e, p->get(), Vec3(k[3], k[3], k[3]), 0, -1, k[4]);
    a->set((int)(info->b + info->c * t), 0x20000001);
}
