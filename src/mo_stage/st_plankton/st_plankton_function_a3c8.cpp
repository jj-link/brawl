#pragma force_active on
typedef unsigned int u32;

class Obj {
public:
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
    virtual u32* get(u32 x);
};

extern "C" void fn_74_A3C8(Obj* self, u32 unused, u32 arg) {
    u32* src = (u32*)self->get(unused);
    u32* dst = (u32*)self->get(arg);
    dst[0] = src[0];
    dst[1] = src[1];
}
