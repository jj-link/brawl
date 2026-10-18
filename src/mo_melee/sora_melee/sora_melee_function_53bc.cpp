#pragma force_active on
extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
extern void* lbl_27_bss_F0;
}

struct Module;

struct Obj0 {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual int get();
    virtual void call18();
    virtual void call1C();
    virtual void v20();
    virtual void v24();
    virtual void call28();
    virtual int call2C();
};

struct Obj8 {
    char pad[8];
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3C();
    virtual int call40();
    virtual void v44();
    virtual void v48();
    virtual void call4C();
};

struct ArgObj {
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void call28(Module*);
};

struct Modules {
    char pad0[0x10];
    Obj8* m10;
    Obj0* m14;
    char pad18[0x2c];
    Obj0* m44;
    char pad48[0x28];
    ArgObj* m70;
    char pad74[0x1c];
    Obj0* m90;
    char pad94[0x24];
    Obj8* mB8;
};

struct Module {
    char pad[0xd8];
    Modules* modules;
};

struct SelfBase {
    char pad[0x3c];
    virtual void v08();
    virtual void vc();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void callB4();
};

struct Self : SelfBase {
    char pad40[0x20];
    Module* module;
};

extern "C" void fn_27_53BC(Self* self) {
    Module* module = self->module;
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton)
            singleton = fn_27_5BCD0(singleton);
        lbl_27_bss_F0 = singleton;
    }

    unsigned int state = fn_27_5BEA8(lbl_27_bss_F0);
    Obj8* a = module->modules->m10;
    a->call4C();

    if (state == 1) {
        Obj0* b = module->modules->m14;
        b->call28();
    }

    self->callB4();

    if (state == 1) {
        Obj0* c = module->modules->m44;
        if (c->call2C() == 0) {
            Obj8* d = module->modules->mB8;
            if (d->call40() == 0) {
                ArgObj* e = module->modules->m70;
                e->call28(module);
            }
            Obj0* f = module->modules->m14;
            if (f->get() != 5) {
                Obj0* g = module->modules->m90;
                g->call18();
            }
        }
    }

    Obj0* h = module->modules->m90;
    h->call1C();
}
