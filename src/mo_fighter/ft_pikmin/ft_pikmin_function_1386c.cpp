#pragma force_active on
struct Vec2 { float x, y; };
struct Ret { float x, y; Ret(const Ret&); };

struct Base { char pad[8]; };
struct Module : Base {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13(); virtual void v14(); virtual void v15();
    virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(); virtual void v25(); virtual void v26(); virtual void v27();
    virtual void v28(); virtual void v29(); virtual void v30(); virtual void v31();
    virtual void v32(); virtual void v33(); virtual void v34(); virtual void v35();
    virtual Ret get(int, bool);
};

struct ObjInterface {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9();
    virtual void append(const Vec2*);
};

struct Obj { char pad[0x60]; };
struct Wrapper { int pad; Obj obj; };

class TargetList {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int size();
};

struct Mid { char pad[4]; Module* module; };
struct Arg { char pad[0xd8]; Mid* mid; };
struct Self { char pad[4]; void* manager; };

extern "C" {
int fn_113_243CC(void*);
TargetList* fn_113_24550(void*);
void fn_113_13958(Obj*, int);
void fn_113_24B10(void*, Obj*);
void fn_113_11D54(Obj*, short);
}

extern "C" void fn_113_1386C(Self* self, Arg* arg) {
    int mode = 0;
    if (fn_113_243CC(self->manager) > 0) {
        Wrapper wrapper;
        Ret r = arg->mid->module->get(mode, mode);
        Vec2 v;
        v.x = r.x;
        v.y = r.y;
        TargetList* list = fn_113_24550(self->manager);
        fn_113_13958(&wrapper.obj, 0);
        for (int i = 0; i < list->size(); ++i) {
            ((ObjInterface*)&wrapper.obj)->append(&v);
        }
        fn_113_24B10(self->manager, &wrapper.obj);
        fn_113_11D54(&wrapper.obj, 0);
    }
}