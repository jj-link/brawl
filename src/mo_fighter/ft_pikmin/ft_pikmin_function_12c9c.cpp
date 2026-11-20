#pragma force_active on

struct Vec2 { float x, y; };
inline Vec2 operator+(const Vec2& a, const Vec2& b) {
    Vec2 v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return v;
}
struct Ret { float x, y; Ret(const Ret&); };

struct ObjInterface {
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
    virtual void append(const Vec2*);
};

struct Obj {
    void* vt;
    void* vt2;
    unsigned int flags;
    Vec2 items[1];
};

struct Wrapper {
    int pad;
    Obj obj;
};

struct Posture {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual float facing();
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
    virtual float v22();
};

struct Base { char pad[8]; };
struct Module : Base {
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
    virtual Ret get(int, bool);
};

struct Mid {
    char pad[4];
    Module* module;
    char pad2[4];
    Posture* posture;
};

struct Arg { char pad[0xd8]; Mid* mid; };
struct Self { char pad[4]; void* manager; };

extern "C" {
int fn_113_243CC(void*);
void fn_113_24B10(void*, Obj*);
void* fn_113_11D54(void*, short);
extern char lbl_113_data_6CD4[];
extern const float lbl_113_rodata_38;
float getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(void*, unsigned long, unsigned long);

void fn_113_12C9C(Self* self, Arg* arg) {
    if (fn_113_243CC(self->manager) > 0) {
        int id = 0;
        Ret r = arg->mid->module->get(id, id);
        Vec2 base;
        base.x = r.x;
        base.y = r.y;
        float f31 = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg, 0xfa5, id);
        Vec2 d;
        d.x = getConstantFloat__15soValueAccesserFP16soModuleAccesserUlUl(arg, 0xfa4, id);
        d.y = f31;
        float m = arg->mid->posture->v22();
        d.x = d.x * m;
        d.y = d.y * m;
        if (arg->mid->posture->facing() < lbl_113_rodata_38) {
            d.x = -d.x;
        }
        Wrapper wrapper;
        wrapper.obj.vt = lbl_113_data_6CD4;
        wrapper.obj.vt2 = lbl_113_data_6CD4 + 0x48;
        wrapper.obj.flags &= 0x1ffffff;
        Vec2* p = wrapper.obj.items;
        do { ++p; } while (p < wrapper.obj.items + 1);
        Vec2 v = base + d;
        ((ObjInterface*)&wrapper.obj)->append(&v);
        fn_113_24B10(self->manager, &wrapper.obj);
        fn_113_11D54(&wrapper.obj, 0);
    }
}
}