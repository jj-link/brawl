#include <new>
#include <types.h>
#include <so/collision/so_collision_attack_part.h>
#include <so/collision/so_collision_group.h>
#include <so/collision/so_collision_attack_module_impl.h>
#include <so/so_array_vector_calculator.h>

#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" {
extern char lbl_73_data_4DF8[];
extern char lbl_73_data_15F8[];
extern char lbl_73_data_4038[];
extern char lbl_73_data_4228[];
extern char lbl_73_data_48D0[];
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

struct Bits {
    unsigned int a : 4;
    unsigned int b : 2;
    unsigned int c : 1;
    unsigned int rest : 25;
};

struct AttackArray {
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
    char parts[0x90];
    void* vt2;
    void* calc2;
    Bits bits2;
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
    float a;
    float b;
    float c;
    char padding[56];

    PaddedData(const float* p) {
        a = p[4];
        b = p[4];
        c = p[4];
    }
};

extern "C" void* fn_73_47FC(char* self, void* arg) {
    const float* rodata = lbl_73_rodata_78;
    gfTask::Category category;
    AttackArray* array;
    soEventObserverRegistrationDesc* desc;
    int id;

    fn_27_262728(
        self,
        arg,
        lbl_73_data_4DF8,
        self + 0x47c,
        lbl_27_bss_398,
        lbl_27_bss_3DC,
        lbl_27_bss_598,
        lbl_27_bss_444);

    *(void**)(self + 0x3c) = lbl_73_data_15F8;
    *(void**)(self + 0x40) = lbl_73_data_15F8 + 0x64;
    *(void**)(self + 0x48) = lbl_73_data_15F8 + 0x70;
    *(void**)(self + 0x54) = lbl_73_data_15F8 + 0x84;
    *(void**)(self + 0x64) = lbl_73_data_15F8 + 0xdc;

    id = *(int*)(self + 0x28);
    category = (gfTask::Category)(u8)(*(u32*)(self + 0x2c) >> 7);
    array = (AttackArray*)(self + 0x358);
    desc = lbl_27_data_54C60;

    {
        soCollisionAttackPart part((soCollision::Category)6, false);

        *(void**)array = lbl_73_data_4038;
        array->calc = lbl_73_data_4038 + 0x48;
        array->flags &= 0x01ffffff;

        __construct_array(
            array->parts,
            fn_73_9C84,
            __dt__21soCollisionAttackPartFv,
            0x90,
            1);

        int count = soArrayVectorCalculator::resize(
            *(soArrayVectorCalcInterface*)&array->calc,
            1,
            array->v4(),
            array->v14(),
            array->v13(),
            array->v27(),
            array->v28());

        for (int i = 0; i < count; i++) {
            array->v10(part);
        }
    }

    array->vt2 = lbl_73_data_4228;
    array->calc2 = lbl_73_data_4228 + 0x48;
    array->bits2.a = 0;
    array->bits2.b = 1;
    array->bits2.c = 0;

    __construct_array(
        array->groups,
        __ct__16soCollisionGroupFv,
        fn_27_37D3C,
        0x78,
        1);

    soArrayVectorCalculator::postInitialize(
        *(soArrayVectorCalcInterface*)&array->calc2, 1, 1);

    PaddedData data(rodata);

    soArray<soCollisionAttackAbsolute>* absolutes =
        (soArray<soCollisionAttackAbsolute>*)new (&array->vt3) AbsoluteArrayStorage;

    new (array->impl) soCollisionAttackModuleImpl(
        (soModuleAccesser*)(self + 0xa8),
        id,
        category,
        (soArray<soCollisionAttackPart>*)array,
        (soArray<soCollisionGroup>*)&array->vt2,
        absolutes,
        desc,
        true);

    fn_27_26320C(self);
    fn_27_2632F4(self, *(int*)((char*)arg + 0xc), rodata[10], rodata[0]);

    *(int*)(self + 0x51c) = 0;
    *(int*)(self + 0x520) = 0;
    *(int*)(self + 0x524) = 0;
    *(int*)(self + 0x528) = 0;

    return self;
}
