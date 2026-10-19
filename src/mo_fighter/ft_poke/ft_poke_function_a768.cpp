#pragma force_active on
typedef unsigned int u32;

class Pad {
public:
    int pad0;
    int pad1;
};

class Obj : public Pad {
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
    virtual void action(u32 a, u32 b);
    virtual void v21();
    virtual u32 query();
};

extern "C" u32 fn_116_A768(Obj* self, u32 a, u32 b) {
    u32 result = self->query();
    if (result == 1) {
        self->action(a, b);
    }
    return result;
}
