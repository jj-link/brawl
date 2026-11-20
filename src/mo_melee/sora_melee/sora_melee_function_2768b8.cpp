#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

struct GlobalObject;
extern "C" {
extern char lbl_27_data_39430[], lbl_27_data_46F8[], lbl_27_data_1E0A0[];
extern char lbl_27_data_1A108[], lbl_27_data_59A38[], lbl_27_data_5A22C[];
extern char lbl_27_data_B620[];
extern char lbl_27_bss_384[], lbl_27_bss_444[], lbl_27_bss_598[];
extern char lbl_27_bss_5FF4[], lbl_27_bss_63B0[];
extern signed char lbl_27_bss_1088;
extern GlobalObject lbl_27_bss_108C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern float lbl_27_rodata_453C, lbl_27_rodata_4520;

void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, void*);
void fn_27_7DC10(void*);
void __register_global_object(GlobalObject&, void*, void*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__18soCollisionHitPartFv(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
void fn_27_D3188(void*);
void fn_27_86D4C(void*);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, int, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, int, int);
}

struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_27_data_B620; }
};

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

struct Array {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual int v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const soCollisionHitPart&);
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual bool v14();
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
    virtual int v27();
    virtual int v28();

    void* calc;
    unsigned int flags;
    char parts[0x68];
    void* vt2;
    void* calc2;
    Bits bits2;
    char groups[0x78];
    void* vt3;
    void* calc3;
    Bits bits3;
    char hitgroups[0x38];
    char impl[0x68];
};

struct Obj {
    char pad0[0x28];
    int id;
    unsigned int flags;
    char pad30[0xc];
    void* vt;
    void* vt2;
    char pad44[4];
    void* vt3;
    char pad4c[8];
    void* vt4;
    char pad58[0xc];
    void* vt5;
    char pad68[0x2f4];
    Array array;
    char extra[0x1c];
};

extern "C" char* fn_27_2768B8(char* self, char* arg) {
    Obj* obj = (Obj*)self;
    fn_27_262728(self, arg, lbl_27_data_5A22C, lbl_27_bss_384,
                 (char*)self + 0x498, (char*)self + 0x5ac,
                 lbl_27_bss_598, lbl_27_bss_444);

    obj->vt = lbl_27_data_59A38;
    obj->vt2 = lbl_27_data_59A38 + 0x64;
    obj->vt3 = lbl_27_data_59A38 + 0x70;
    obj->vt4 = lbl_27_data_59A38 + 0x84;
    obj->vt5 = lbl_27_data_59A38 + 0xdc;

    int w, z, y, x, i;
    unsigned char category = (unsigned char)(obj->flags >> 7);
    Array* a = &obj->array;
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = obj->id;

    {
        soCollisionHitPart part((soCollision::Category)1, 0x3ff);
        *(void**)a = lbl_27_data_39430;
        a->calc = lbl_27_data_39430 + 0x48;
        a->flags &= 0x01ffffff;
        __construct_array(a->parts, __ct__18soCollisionHitPartFv,
                          __dt__18soCollisionHitPartFv, 0x68, 1);

        x = a->v28();
        y = a->v27();
        z = a->v13();
        w = a->v14();
        w = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
            &a->calc, 1, a->v4(), w, z, y, x);
        for (i = 0; i < w; i++) {
            a->v10(part);
        }
    }

    a->vt2 = lbl_27_data_46F8;
    a->calc2 = lbl_27_data_46F8 + 0x48;
    a->bits2.a = 0;
    a->bits2.b = 1;
    a->bits2.c = 0;
    __construct_array(a->groups, __ct__16soCollisionGroupFv,
                      fn_27_37D3C, 0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &a->calc2, 1, 1);

    a->vt3 = lbl_27_data_1E0A0;
    a->calc3 = lbl_27_data_1E0A0 + 0x48;
    a->bits3.a = 0;
    a->bits3.b = 1;
    a->bits3.c = 0;
    __construct_array(a->hitgroups, __ct__19soCollisionHitGroupFv,
                      __dt__19soCollisionHitGroupFv, 0x38, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &a->calc3, 1, 1);

    new (a->impl) soCollisionHitModuleImpl(
        (soModuleAccesser*)(self + 0xa8), id,
        (gfTask::Category)category, (soArray<soCollisionHitPart>*)a,
        (soArray<soCollisionGroup>*)&a->vt2,
        (soArray<soCollisionHitGroup>*)&a->vt3, desc, true);

    {
        char* p = (char*)self + 0x500;
        soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
        *(void**)p = lbl_27_data_1A108;
        *(void**)(p + 4) = lbl_27_data_1A108 + 0x48;
        ((Bits*)(p + 8))->a = 0;
        ((Bits*)(p + 8))->b = 1;
        ((Bits*)(p + 8))->c = 0;
        __construct_array(p + 12, fn_27_D3188, fn_27_86D4C, 0xa0, 1);
        postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
            p + 4, 1, 1);

        if (!lbl_27_bss_1088) {
            GlobalObject* object = new (&lbl_27_bss_108C) GlobalObject;
            __register_global_object(*object, (void*)fn_27_7DC10,
                                     lbl_27_bss_63B0);
            lbl_27_bss_1088 = 1;
        }

        fn_27_26F06C(p + 0xac, (char*)self + 0xa8, p, lbl_27_bss_5FF4,
                     &lbl_27_bss_108C, desc2);
    }

    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xc),
                 lbl_27_rodata_453C, lbl_27_rodata_4520);
    return self;
}
