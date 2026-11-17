#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

struct GlobalObject;
extern "C" {
extern char lbl_27_data_5A208[], lbl_27_data_59448[], lbl_27_data_39430[], lbl_27_data_46F8[], lbl_27_data_1E0A0[], lbl_27_data_1A108[], lbl_27_data_B620[];
extern char lbl_27_bss_384[], lbl_27_bss_444[], lbl_27_bss_598[], lbl_27_bss_5FF4[], lbl_27_bss_63B0[];
extern signed char lbl_27_bss_1088;
extern GlobalObject lbl_27_bss_108C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern float lbl_27_rodata_453C, lbl_27_rodata_4520;
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
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
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, int, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_27_data_B620; }
};
struct Bits { unsigned int a:4, b:2, c:1, rest:25; };
struct HitArray {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual int v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(const soCollisionHitPart&);
    virtual void v11(); virtual void v12(); virtual int v13(); virtual int v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18();
    virtual void v19(); virtual void v20(); virtual void v21(); virtual void v22();
    virtual void v23(); virtual void v24(); virtual void v25(); virtual void v26();
    virtual int v27(); virtual int v28();
    void* calc; unsigned int flags; char parts[0x68];
    void* vt2; void* calc2; Bits bits2; char groups[0x78];
    void* vt3; void* calc3; Bits bits3; char hitgroups[0x38];
    char impl[0x68];
};
struct ArrayOther { void* vt; void* calc; Bits bits; char elements[0xa0]; char impl[1]; };
extern "C" char* fn_27_2774E0(char* self, char* arg) {
    fn_27_262728(self, arg, lbl_27_data_5A208, lbl_27_bss_384, self+0x498, self+0x5ac, lbl_27_bss_598, lbl_27_bss_444);
    char* data = lbl_27_data_59448;
    *(void**)(self+0x3c) = data;
    *(void**)(self+0x40) = data+0x64;
    *(void**)(self+0x48) = data+0x70;
    *(void**)(self+0x54) = data+0x84;
    *(void**)(self+0x64) = data+0xdc;
    gfTask::Category category = (gfTask::Category)(unsigned char)(*(unsigned int*)(self+0x2c) >> 7);
    HitArray* h = (HitArray*)(self+0x35c);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self+0x28);
    {
        soCollisionHitPart part((soCollision::Category)7, 0x3ff);
        *(void**)h = lbl_27_data_39430;
        h->calc = lbl_27_data_39430+0x48;
        h->flags &= 0x01ffffff;
        __construct_array(h->parts, __ct__18soCollisionHitPartFv, __dt__18soCollisionHitPartFv, 0x68, 1);
        int e, d, c, b, a;
        a = h->v28();
        b = h->v27();
        c = h->v13();
        d = h->v14();
        e = h->v4();
        int n = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&h->calc, 1, e, d, c, b, a);
        for (int i=0; i<n; ++i) h->v10(part);
    }
    h->vt2 = lbl_27_data_46F8;
    h->calc2 = lbl_27_data_46F8+0x48;
    h->bits2.a=0; h->bits2.b=1; h->bits2.c=0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&h->calc2, 1, 1);
    h->vt3 = lbl_27_data_1E0A0;
    h->calc3 = lbl_27_data_1E0A0+0x48;
    h->bits3.a=0; h->bits3.b=1; h->bits3.c=0;
    __construct_array(h->hitgroups, __ct__19soCollisionHitGroupFv, __dt__19soCollisionHitGroupFv, 0x38, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&h->calc3, 1, 1);
    new (h->impl) soCollisionHitModuleImpl((soModuleAccesser*)(self+0xa8), id, (gfTask::Category)category,
        (soArray<soCollisionHitPart>*)h, (soArray<soCollisionGroup>*)&h->vt2,
        (soArray<soCollisionHitGroup>*)&h->vt3, desc, true);
    ArrayOther* o = (ArrayOther*)(self+0x500);
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    o->vt = lbl_27_data_1A108;
    o->calc = lbl_27_data_1A108+0x48;
    o->bits.a=0; o->bits.b=1; o->bits.c=0;
    __construct_array(o->elements, fn_27_D3188, fn_27_86D4C, 0xa0, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&o->calc, 1, 1);
    if (!lbl_27_bss_1088) {
        GlobalObject* object = new (&lbl_27_bss_108C) GlobalObject;
        __register_global_object(*object, (void*)fn_27_7DC10, lbl_27_bss_63B0);
        lbl_27_bss_1088 = 1;
    }
    fn_27_26F06C(o->impl, self+0xa8, o, lbl_27_bss_5FF4, &lbl_27_bss_108C, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg+0xc), lbl_27_rodata_453C, lbl_27_rodata_4520);
    return self;
}