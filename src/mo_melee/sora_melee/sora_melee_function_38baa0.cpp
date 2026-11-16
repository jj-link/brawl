#include <new>
#include <so/so_array.h>
#include <so/so_array_vector_calculator.h>
#include <so/work/so_general_work.h>
#pragma force_active on
#pragma use_simple_stdpnew on

extern "C" char lbl_27_data_12998[];
struct GlobalObject {
    void* vtable;
    GlobalObject() { vtable = 0; vtable = lbl_27_data_12998; }
};

class ObjVt {
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
    virtual void v10(void* p);
    virtual void v11();
    virtual void v12();
    virtual s32 v13();
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
    virtual s32 v27();
    virtual s32 v28();
    void* calc;
    u32 flags;
};

struct MainObject {
    char pad[0x7c];
    ObjVt* arrayPtr;
    ObjVt array;
};

extern "C" {
extern char lbl_27_data_20950[];
extern char lbl_27_data_1D4E8[];
extern char lbl_27_data_3C578[];
extern char lbl_27_data_3ED00[];
extern char lbl_27_data_8E80[];
extern char lbl_27_data_9959C[];
extern char lbl_27_data_12998[];
extern signed char lbl_27_bss_76B4;
extern GlobalObject lbl_27_bss_76B8;
extern char lbl_27_bss_8858[];
void fn_27_82B54(void*, short);
void fn_27_AB128(void*);
void fn_27_AB18C(void*, short);
void fn_27_D2A0C(void*);
void* fn_27_AB510(void*, int);
void fn_27_AB15C(void*, void*);
void __construct_array(void*, void*, void*, unsigned long, int);
void* __register_global_object(GlobalObject&, void*, void*);
void fn_27_73930(void*, void*, void*, void*, void*, void*, void*, void*, int, int);
}

extern "C" void* fn_27_38BAA0(void* arg0, void* arg1, s32 arg2, void* arg3) {
    u32 sp10[8];
    char* self = (char*)arg0;
    char* a;
    u32 bits;

    *(void**)(self + 0x4) = 0;
    *(void**)(self + 0x0) = lbl_27_data_20950;
    *(s32*)(self + 0x8) = arg2;
    *(s32*)(self + 0xC) = 9;
    if (arg2 == 0) {
        *(s32*)(self + 0xC) = 0;
    }
    a = self + 0x14;

    bits = *(u32*)(a + 0x8);
    *(void**)a = lbl_27_data_1D4E8;
    *(void**)(a + 0x4) = lbl_27_data_1D4E8 + 0x48;
    *(u32*)(a + 0x8) = bits & 0x01FFFFFF;
    __construct_array(a + 0xC, (void*)fn_27_AB128, (void*)fn_27_AB18C, 0x14, 1);

    bits = *(u32*)(a + 0x28);
    *(void**)(a + 0x20) = lbl_27_data_3C578;
    *(void**)(a + 0x24) = lbl_27_data_3C578 + 0x48;
    *(u32*)(a + 0x28) = bits & 0x003FFFFF;
    __construct_array(a + 0x2C, (void*)fn_27_D2A0C, (void*)fn_27_AB510, 0x10, 2);

    *(void**)(a + 0x50) = a;
    *(void**)(a + 0x4C) = lbl_27_data_8E80;
    *(s32*)(a + 0x54) = 0;
    *(s32*)(a + 0x60) = 0;
    *(s32*)(a + 0x58) = -1;
    *(s32*)(a + 0x5C) = -1;
    for (int j = 0; j < 1; ++j) {
        fn_27_AB15C(sp10, j == 0 ? a + 0x20 : 0);
        ((ObjVt*)a)->v10(sp10);
        fn_27_AB18C(sp10, -1);
    }

    MainObject* obj = (MainObject*)self;
    ObjVt* o = &obj->array;
    obj->arrayPtr = o;
    *(void**)o = lbl_27_data_3ED00;
    o->calc = lbl_27_data_3ED00 + 0x48;
    o->flags &= 0x01FFFFFF;

    s32 size = soArrayVectorCalculator::resize(*(soArrayVectorCalcInterface*)&o->calc, 1, o->v4(), o->v14(), o->v13(), o->v27(), o->v28());

    for (s32 i = 0; i < size; i++) {
        o->v10(lbl_27_data_9959C);
    }
    ((ObjVt*)(self + 0x80))->v13();

    if (lbl_27_bss_76B4 == 0) {
        GlobalObject* object = new (&lbl_27_bss_76B8) GlobalObject;
        __register_global_object(*object, (void*)fn_27_82B54, lbl_27_bss_8858);
        lbl_27_bss_76B4 = 1;
    }

    fn_27_73930(self + 0x90, arg1, self, &lbl_27_bss_76B8, &g_soGeneralWork, self + 0x60, self + 0x7C, arg3, 0, 1);
    return arg0;
}
