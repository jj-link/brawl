#pragma force_active on
extern "C" void* fn_27_16990C(void* p1, void* p2);

class VBase {
public:
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
    virtual void v21(int, void*);
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
    virtual void v36();
    virtual void v37();
    virtual bool v38();
};

struct A {
    char pad0[8];
    VBase* obj;
    char pad1[0x70];
    VBase* b;
};

struct Outer {
    char pad[0xd8];
    A* a;
};

extern "C" void fn_27_192A04(void* p1, void* p2) {
    Outer* o = (Outer*)p2;
    fn_27_16990C(p1, p2);
    VBase* obj = o->a->obj;
    if (obj->v38()) {
        o->a->b->v21(0x13, p2);
        obj->v34();
    }
}
