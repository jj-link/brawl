#pragma force_active on
typedef unsigned int u32;

struct ObjPad {
    u32 pad0;
    u32 pad1;
};

class Obj : public ObjPad {
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
    virtual void f58(u32 a, u32 b);
    virtual void vdummy();
    virtual u32 f60(u32 a, u32 b);
};

extern "C" u32 fn_93_B198(Obj* self, u32 a, u32 b) {
    u32 result = self->f60(a, b);
    if (result == 1) {
        self->f58(a, b);
    }
    return result;
}
