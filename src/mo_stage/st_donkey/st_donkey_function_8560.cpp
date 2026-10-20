#pragma force_active on
typedef unsigned int u32;

struct Data {
    u32 a;
    u32 b;
};

struct Obj {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
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
    virtual Data* getData(void* p);
};

extern "C" {
void fn_50_8560(Obj* self, void* p0, void* p1) {
    Data* src = self->getData(p0);
    Data* dst = self->getData(p1);
    dst->a = src->a;
    dst->b = src->b;
}
}
