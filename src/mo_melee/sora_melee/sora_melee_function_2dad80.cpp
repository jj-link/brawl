#include <new>
#include <so/collision/so_collision_attack_module_impl.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_3E748[];
extern char lbl_27_data_46F8[];
extern char lbl_27_data_125F0[];

extern const float lbl_27_rodata_6378;

void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__21soCollisionAttackPartFv(void*);
void __dt__21soCollisionAttackPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
int resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
    void*, int, int, int, int, int, int);
void postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
    void*, int, int);
}

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

struct Obj {
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
    virtual void v10(const soCollisionAttackPart&);
    virtual void v11();
    virtual void v12();
    virtual int v13();
    virtual int v14();
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
    char parts[0x90];
    void* vt2;
    void* calc2;
    Bits bits2;
    char groups[0x78];
    void* absVt;
    char impl[0xA0];
};

struct AbsoluteArrayStorage {
    void* table;
    AbsoluteArrayStorage() : table(lbl_27_data_125F0) {}
};

extern "C" Obj* fn_27_2DAD80(
    Obj* self, soModuleAccesser* accesser, int id, gfTask::Category category,
    soEventObserverRegistrationDesc* desc)
{
    unsigned char* bytes = reinterpret_cast<unsigned char*>(self);
    unsigned char storage[0x1C8];

    {
        new (storage + 0x138) soCollisionAttackPart((soCollision::Category)0, false);
        *(void**)self = lbl_27_data_3E748;
        self->calc = lbl_27_data_3E748 + 0x48;
        self->flags &= 0x01ffffff;
        __construct_array(self->parts, __ct__21soCollisionAttackPartFv,
                          __dt__21soCollisionAttackPartFv, 0x90, 1);

        int d, c, b, a;
        a = self->v28();
        b = self->v27();
        c = self->v13();
        d = self->v14();
        int e = self->v4();
        int count =
            resize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacelbblll(
                &self->calc, 1, e, d, c, b, a);
        for (int i = 0; i < count; i++)
            self->v10(*reinterpret_cast<soCollisionAttackPart*>(storage + 0x138));
        reinterpret_cast<soCollisionAttackPart*>(storage + 0x138)->~soCollisionAttackPart();
    }

    self->vt2 = lbl_27_data_46F8;
    self->calc2 = lbl_27_data_46F8 + 0x48;
    self->bits2.a = 0;
    self->bits2.b = 1;
    self->bits2.c = 0;
    __construct_array(self->groups, __ct__16soCollisionGroupFv, fn_27_37D3C,
                      0x78, 1);
    postInitialize__23soArrayVectorCalculatorFR26soArrayVectorCalcInterfacell(
        &self->calc2, 1, 1);

    float one = lbl_27_rodata_6378;
    soArray<soCollisionAttackAbsolute>* absolutes =
        reinterpret_cast<soArray<soCollisionAttackAbsolute>*>(
            new (bytes + 0x120) AbsoluteArrayStorage);
    *reinterpret_cast<float*>(storage + 0xF4) = one;
    *reinterpret_cast<float*>(storage + 0x28) = one;
    *reinterpret_cast<float*>(storage + 0x94) = one;
    new (&self->impl[0]) soCollisionAttackModuleImpl(
        accesser, id, category, (soArray<soCollisionAttackPart>*)self,
        (soArray<soCollisionGroup>*)&self->vt2, absolutes, desc, true);
    return self;
}
