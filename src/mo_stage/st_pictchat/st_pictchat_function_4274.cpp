#include <new>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
extern char lbl_73_data_4E18[], lbl_27_bss_398[], lbl_27_bss_3DC[], lbl_27_bss_598[], lbl_27_bss_444[];
extern char lbl_73_data_1998[], lbl_73_data_43F8[], lbl_73_data_4228[], lbl_73_data_48D0[];
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;
extern const float lbl_73_rodata_78[];
void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_73_9C84(void*);
void __dt__21soCollisionAttackPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
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
    void* calc; unsigned int flags; char parts[0x360];
    void* vt2; void* calc2; GroupBits bits2; char groups[0x78];
    void* vt3; char impl[0xa0];
};
class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_73_data_48D0) {}
};
struct PaddedData {
    char prefix[36];
    float a,b,c;
    char padding[56];
    PaddedData(const float* p) { a=p[4]; b=p[4]; c=p[4]; }
};
extern "C" void* fn_73_4274(char* self, char* arg) {
    const float* rodata = lbl_73_rodata_78;
    fn_27_262728(self, arg, lbl_73_data_4E18, self + 0x74c, lbl_27_bss_398, lbl_27_bss_3DC, lbl_27_bss_598, lbl_27_bss_444);
    *(void**)(self + 0x3c) = lbl_73_data_1998;
    *(void**)(self + 0x40) = lbl_73_data_1998 + 0x64;
    *(void**)(self + 0x48) = lbl_73_data_1998 + 0x70;
    *(void**)(self + 0x54) = lbl_73_data_1998 + 0x84;
    *(void**)(self + 0x64) = lbl_73_data_1998 + 0xdc;
    gfTask::Category category = (gfTask::Category)(unsigned char)(*(unsigned int*)(self + 0x2c) >> 7);
    AttackArray* h = (AttackArray*)(self + 0x358);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int id = *(int*)(self + 0x28);
    {
        soCollisionAttackPart part((soCollision::Category)6, false);
        *(void**)h = lbl_73_data_43F8;
        h->calc = lbl_73_data_43F8 + 0x48;
        h->flags &= 0x7FFFF;
        __construct_array((char*)h + 0xc, fn_73_9C84, __dt__21soCollisionAttackPartFv, 0x90, 6);
        int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&h->calc, 6,
            h->v4(), h->v14(), h->v13(), h->v27(), h->v28());
        for (int i = 0; i < count; i++) h->v10(part);
    }
    h->vt2 = lbl_73_data_4228;
    h->calc2 = lbl_73_data_4228 + 0x48;
    h->bits2.top = 0; h->bits2.last = 0; h->bits2.size = 1; h->bits2.full = 0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc2, 1, 1);
    PaddedData data(rodata);
    soArray<soCollisionAttackAbsolute>* absolutes = (soArray<soCollisionAttackAbsolute>*)new (&h->vt3) AbsoluteArrayStorage;
    new (h->impl) soCollisionAttackModuleImpl((soModuleAccesser*)(self + 0xa8), id, category,
        (soArray<soCollisionAttackPart>*)h,
        (soArray<soCollisionGroup>*)&h->vt2,
        absolutes, desc, true);
    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)(arg + 0xc), rodata[10], rodata[0]);
    *(int*)(self + 0x7ec) = 0;
    *(int*)(self + 0x7f0) = 0;
    *(int*)(self + 0x7f4) = 0;
    *(int*)(self + 0x7f8) = 0;
    return self;
}