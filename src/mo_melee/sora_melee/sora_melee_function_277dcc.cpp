#include <new>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_27_data_5A1FC[], lbl_27_bss_398[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_27_data_59258[], lbl_27_data_3E748[], lbl_27_data_46F8[], lbl_27_data_125F0[];
extern char lbl_27_data_11E88[], lbl_27_data_B620[];
extern char lbl_27_bss_5FF4[], lbl_27_bss_63B0[], lbl_27_bss_63BC[];
extern signed char lbl_27_bss_5C60, lbl_27_bss_1088;
extern void* lbl_27_bss_5C64;
extern void* lbl_27_bss_108C;
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern const float lbl_27_rodata_4520[];

void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void fn_27_26F06C(void*, void*, void*, void*, void*, soEventObserverRegistrationDesc*);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __ct__21soCollisionAttackPartFv(void*);
void __dt__21soCollisionAttackPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
void fn_27_82914(void*);
void fn_27_7DC10(void*);
void __register_global_object(void*, void*, void*);
}

struct GroupBits { unsigned int top:2, last:2, size:2, full:1, rest:25; };
struct AttackArray {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual bool v4();
    virtual void v5(); virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10(const soCollisionAttackPart&);
    virtual void v11(); virtual void v12();
    virtual int v13();
    virtual bool v14();
    virtual void v15(); virtual void v16(); virtual void v17(); virtual void v18(); virtual void v19();
    virtual void v20(); virtual void v21(); virtual void v22(); virtual void v23(); virtual void v24();
    virtual void v25(); virtual void v26();
    virtual int v27();
    virtual int v28();
    void* calc; unsigned int flags; char parts[0x90];
    void* vt2; void* calc2; GroupBits bits2; char groups[0x78];
    void* vt3; char impl[0xa0];
};
class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_27_data_125F0) {}
};
struct PaddedData {
    char prefix[36];
    float a,b,c;
    char padding[56];
    PaddedData(const float* p) { a=p[1]; b=p[1]; c=p[1]; }
};
struct Global1 {
    void* vtable;
    Global1() { vtable = 0; vtable = lbl_27_data_11E88; }
};
struct Global2 {
    void* vtable;
    Global2() { vtable = 0; vtable = lbl_27_data_B620; }
};

extern "C" void* fn_27_277DCC(char* self, char* arg) {
    const float* rodata = lbl_27_rodata_4520;
    fn_27_262728(self, arg, lbl_27_data_5A1FC, self + 0x47c, lbl_27_bss_398, self + 0x524, lbl_27_bss_598, lbl_27_bss_444);
    *(void**)(self + 0x3c) = lbl_27_data_59258;
    *(void**)(self + 0x40) = lbl_27_data_59258 + 0x64;
    *(void**)(self + 0x48) = lbl_27_data_59258 + 0x70;
    *(void**)(self + 0x54) = lbl_27_data_59258 + 0x84;
    *(void**)(self + 0x64) = lbl_27_data_59258 + 0xdc;
    gfTask::Category category = (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    AttackArray* h = (AttackArray*)(self + 0x358);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self + 0x28);
    {
        soCollisionAttackPart part((soCollision::Category)6, false);
        *(void**)h = lbl_27_data_3E748;
        h->calc = lbl_27_data_3E748 + 0x48;
        h->flags &= 0x01FFFFFF;
        __construct_array((char*)h + 0xc, __ct__21soCollisionAttackPartFv, __dt__21soCollisionAttackPartFv, 0x90, 1);
        int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&h->calc, 1,
            h->v4(), h->v14(), h->v13(), h->v27(), h->v28());
        for (int i = 0; i < count; i++) h->v10(part);
    }
    h->vt2 = lbl_27_data_46F8;
    h->calc2 = lbl_27_data_46F8 + 0x48;
    h->bits2.top = 0; h->bits2.last = 0; h->bits2.size = 1; h->bits2.full = 0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc2, 1, 1);
    PaddedData data(rodata);
    soArray<soCollisionAttackAbsolute>* absolutes = (soArray<soCollisionAttackAbsolute>*)new (&h->vt3) AbsoluteArrayStorage;
    new (h->impl) soCollisionAttackModuleImpl((soModuleAccesser*)(self + 0xa8), id, category,
        (soArray<soCollisionAttackPart>*)h,
        (soArray<soCollisionGroup>*)&h->vt2,
        absolutes, desc, true);
    void** global1;
    soEventObserverRegistrationDesc* desc2 = lbl_27_data_54C60;
    if (lbl_27_bss_5C60 == 0) {
        Global1* obj = new (&lbl_27_bss_5C64) Global1;
        __register_global_object(obj, (void*)fn_27_82914, lbl_27_bss_63BC);
        lbl_27_bss_5C60 = 1;
    }
    global1 = &lbl_27_bss_5C64;
    if (lbl_27_bss_1088 == 0) {
        Global2* obj = new (&lbl_27_bss_108C) Global2;
        __register_global_object(obj, (void*)fn_27_7DC10, lbl_27_bss_63B0);
        lbl_27_bss_1088 = 1;
    }
    fn_27_26F06C(self + 0x524, self + 0xa8, global1, lbl_27_bss_5FF4, &lbl_27_bss_108C, desc2);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xc), rodata[7], rodata[0]);
    return self;
}