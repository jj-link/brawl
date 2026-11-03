#include <new>
class soCollisionAttackModule;
#include <so/collision/so_collision_hit_module_impl.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_39430[], lbl_27_data_46F8[], lbl_27_data_1E0A0[];
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__18soCollisionHitPartFv(void*);
void __dt__18soCollisionHitPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void __ct__19soCollisionHitGroupFv(void*);
void __dt__19soCollisionHitGroupFv(void*);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(void*, int, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(void*, int, int);
}
struct Bits { unsigned int a:4, b:2, c:1, rest:25; };
struct Obj {
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
extern "C" Obj* fn_27_349E18(Obj* self, soModuleAccesser* accesser, int id, gfTask::Category category, soEventObserverRegistrationDesc* desc) {
    {
        soCollisionHitPart part((soCollision::Category)0, 0x3ff);
        *(void**)self = lbl_27_data_39430;
        self->calc = lbl_27_data_39430 + 0x48;
        self->flags &= 0x01ffffff;
        __construct_array(self->parts, __ct__18soCollisionHitPartFv, __dt__18soCollisionHitPartFv, 0x68, 1);
        int d, c, b, a;
        a = self->v28();
        b = self->v27();
        c = self->v13();
        d = self->v14();
        int e = self->v4();
        int count = resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(&self->calc, 1, e, d, c, b, a);
        for (int i = 0; i < count; i++) self->v10(part);
    }
    self->vt2 = lbl_27_data_46F8;
    self->calc2 = lbl_27_data_46F8 + 0x48;
    self->bits2.a = 0; self->bits2.b = 1; self->bits2.c = 0;
    __construct_array(self->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc2, 1, 1);
    self->vt3 = lbl_27_data_1E0A0;
    self->calc3 = lbl_27_data_1E0A0 + 0x48;
    self->bits3.a = 0; self->bits3.b = 1; self->bits3.c = 0;
    __construct_array(self->hitgroups, __ct__19soCollisionHitGroupFv, __dt__19soCollisionHitGroupFv, 0x38, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(&self->calc3, 1, 1);
    new (self->impl) soCollisionHitModuleImpl(accesser, id, category,
        (soArray<soCollisionHitPart>*)self, (soArray<soCollisionGroup>*)&self->vt2,
        (soArray<soCollisionHitGroup>*)&self->vt3, desc, true);
    return self;
}