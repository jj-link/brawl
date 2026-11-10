#pragma force_active on
struct Vec2 { float x, y; };
struct Ret { float x, y, z; Ret(const Ret&); };
struct Obj;
struct ObjVtable { char pad[0x30]; void (*append)(Obj*, const Vec2*); };
struct Obj { ObjVtable* vt; void* vt2; unsigned int flags; Vec2 items[1]; };
struct ObjInterface {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void append(const Vec2*);
};
struct Wrapper { Obj obj; };
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
    virtual Ret get(int, int);
};
struct Modules { char pad[4]; Module* module; };
struct Accesser { char pad[0xd8]; Modules* modules; };
struct Self { char pad[4]; void* manager; };
extern "C" int fn_113_243CC(void*);
extern "C" void fn_113_24B10(void*, Obj*);
extern "C" void* fn_113_11D54(void*, short);
extern "C" void* fn_113_B7F0(Vec2*, const Ret*);
extern "C" char lbl_113_data_6CD4[];
extern "C" void fn_113_11B28(Self* self, Accesser* arg) {
    if (fn_113_243CC(self->manager) > 0) {
        Wrapper wrapper;
        Vec2 v8;
        wrapper.obj.vt = (ObjVtable*)lbl_113_data_6CD4;
        wrapper.obj.vt2 = lbl_113_data_6CD4 + 0x48;
        wrapper.obj.flags &= 0x1ffffff;
        Vec2* p = wrapper.obj.items;
        do { ++p; } while (p < wrapper.obj.items + 1);
        Ret r10 = arg->modules->module->get(0x29, 0);
        Vec2* q = (Vec2*)fn_113_B7F0(&v8, &r10);
        ((ObjInterface*)&wrapper.obj)->append(q);
        fn_113_24B10(self->manager, &wrapper.obj);
        fn_113_11D54(&wrapper.obj, 0);
    }
}