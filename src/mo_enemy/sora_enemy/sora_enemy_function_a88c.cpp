#pragma force_active on
typedef unsigned long u32;
typedef int s32;

struct Vec3f { float x, y, z; };
struct soModuleAccesser;

struct soValueAccesser {
    s32 getValueInt(soModuleAccesser*, u32, u32);
};

struct B {
    u32 a;
    u32 b;
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
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual Vec3f v36(s32, s32);
};

struct Holder {
    u32 x;
    B* mod;
};

class Enemy {
public:
    Vec3f getCenterPos();
};

Vec3f Enemy::getCenterPos() {
    Holder* h = *(Holder**)((char*)this + 0x1b4);
    B* m = h->mod;
    u32 unused;
    s32 v = ((soValueAccesser*)((char*)this + 0xdc))->getValueInt((soModuleAccesser*)0x59e6, 0, unused);
    return m->v36(v, 0);
}
