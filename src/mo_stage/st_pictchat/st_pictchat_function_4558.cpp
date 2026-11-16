#include <new>
#include <types.h>
#include <so/so_array.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_group.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on
#pragma use_simple_stdpnew on

class soEventObserverRegistrationDesc;

extern "C" char lbl_73_data_48D0[];

struct GroupBits {
    unsigned int top : 2;
    unsigned int last : 2;
    unsigned int size : 2;
    unsigned int full : 1;
    unsigned int rest : 25;
};

class AttackArray {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual bool v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10(const soCollisionAttackPart&);
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
    char parts[0x120];
    void* vt2;
    void* calc2;
    GroupBits bits2;
    char groups[0x78];
    void* vt3;
    char impl[0xa0];
};

class AbsoluteArrayStorage {
    void* table;
public:
    AbsoluteArrayStorage() : table(lbl_73_data_48D0) {}
};

struct PaddedData {
    char prefix[36];
    float a, b, c;
    char padding[56];
    PaddedData(const float* p) {
        a = p[4];
        b = p[4];
        c = p[4];
    }
};

extern "C" {
extern char lbl_73_data_4E08[];
extern char lbl_73_data_17C8[];
extern char lbl_73_data_4130[];
extern char lbl_73_data_4228[];
extern char lbl_27_bss_398[];
extern char lbl_27_bss_3DC[];
extern char lbl_27_bss_598[];
extern char lbl_27_bss_444[];
extern const float lbl_73_rodata_78[];
extern soEventObserverRegistrationDesc* lbl_27_data_54C60;

void fn_27_262728(void*, void*, void*, void*, void*, void*, void*, void*);
void fn_27_26320C(void*);
void fn_27_2632F4(void*, int, float, float);
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void fn_73_9C84(void*);
void __dt__21soCollisionAttackPartFv(void*);
void __ct__16soCollisionGroupFv(void*);
void fn_27_37D3C(void*);
}

extern "C" void* fn_73_4558(void* arg0, void* arg1) {
    const float* rodata = lbl_73_rodata_78;
    fn_27_262728(arg0, arg1, lbl_73_data_4E08, (char*)arg0 + 0x50C,
                 lbl_27_bss_398, lbl_27_bss_3DC, lbl_27_bss_598, lbl_27_bss_444);
    *(void**)((char*)arg0 + 0x3C) = lbl_73_data_17C8;
    *(void**)((char*)arg0 + 0x40) = lbl_73_data_17C8 + 0x64;
    *(void**)((char*)arg0 + 0x48) = lbl_73_data_17C8 + 0x70;
    *(void**)((char*)arg0 + 0x54) = lbl_73_data_17C8 + 0x84;
    *(void**)((char*)arg0 + 0x64) = lbl_73_data_17C8 + 0xDC;
    gfTask::Category category = (gfTask::Category)(u8)(*(u32*)((char*)arg0 + 0x2C) >> 7);
    AttackArray* h = (AttackArray*)((char*)arg0 + 0x358);
    soEventObserverRegistrationDesc* desc = lbl_27_data_54C60;
    int taskId = *(int*)((char*)arg0 + 0x28);
    {
        soCollisionAttackPart part((soCollision::Category)6, false);
        *(void**)h = lbl_73_data_4130;
        h->calc = lbl_73_data_4130 + 0x48;
        h->flags &= 0x3FFFFF;
        __construct_array(h->parts, fn_73_9C84, __dt__21soCollisionAttackPartFv, 0x90, 2);
        int count = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&h->calc, 2,
            h->v4(), h->v14(), h->v13(), h->v27(), h->v28());
        for (int i = 0; i < count; i++) h->v10(part);
    }
    h->vt2 = lbl_73_data_4228;
    h->calc2 = lbl_73_data_4228 + 0x48;
    h->bits2.top = 0;
    h->bits2.last = 0;
    h->bits2.size = 1;
    h->bits2.full = 0;
    __construct_array(h->groups, __ct__16soCollisionGroupFv, fn_27_37D3C, 0x78, 1);
    soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&h->calc2, 1, 1);
    PaddedData data(rodata);
    soArray<soCollisionAttackAbsolute>* absolutes = (soArray<soCollisionAttackAbsolute>*)new (&h->vt3) AbsoluteArrayStorage;
    new (h->impl) soCollisionAttackModuleImpl((soModuleAccesser*)((char*)arg0 + 0xA8), taskId, category,
        (soArray<soCollisionAttackPart>*)h,
        (soArray<soCollisionGroup>*)&h->vt2,
        absolutes, desc, true);
    fn_27_26320C(arg0);
    fn_27_2632F4(arg0, *(int*)((char*)arg1 + 0xC), rodata[10], rodata[0]);
    *(int*)((char*)arg0 + 0x5AC) = 0;
    *(int*)((char*)arg0 + 0x5B0) = 0;
    *(int*)((char*)arg0 + 0x5B4) = 0;
    *(int*)((char*)arg0 + 0x5B8) = 0;
    return arg0;
}