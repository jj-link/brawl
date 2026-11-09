#include <types.h>
#include <new>
#include <so/so_array.h>
#pragma force_active on
#pragma use_simple_stdpnew on
extern "C" {
void __construct_array(void*, void (*)(void*), void (*)(void*), unsigned long, int);
void __register_global_object(void*, void*, void*);
void fn_27_5C7AC(void*, s32, void*, void*, void*, s32);
void fn_27_D3188(void*);
void fn_27_86D4C(void*);
void fn_27_7DE60(void*);
void fn_27_7DC10(void*);
extern void* __vt__10soNullable[];
extern char lbl_27_data_1A108[], lbl_27_data_B620[], lbl_27_data_B6E0[], lbl_27_data_B750[];
extern signed char lbl_27_bss_1088, lbl_27_bss_7F14;
extern char lbl_27_bss_7ED8[], lbl_27_bss_7F08[];
}
struct Obj { void* vt; u8 flag; void* p; };
extern "C" Obj lbl_27_bss_7F18;
struct GlobalObject {
    void* vt;
    GlobalObject() { vt = 0; vt = lbl_27_data_B620; }
};
extern "C" GlobalObject lbl_27_bss_108C;
struct Bits { unsigned int a:4, b:2, c:1, rest:25; };
struct Storage {
    void* vt;
    void* calc;
    Bits bits;
    char elements[0xa0];
    Storage() {
        vt = lbl_27_data_1A108;
        calc = lbl_27_data_1A108 + 0x48;
        bits.a = 0; bits.b = 1; bits.c = 0;
        __construct_array(elements, fn_27_D3188, fn_27_86D4C, 0xa0, 1);
        soArrayVectorCalculator::postInitialize(*(soArrayVectorCalcInterface*)&calc, 1, 1);
    }
};
extern "C" void* fn_27_34A058(void* self, s32 arg1, s32 arg2) {
    Storage* s = new (self) Storage;
    if (!lbl_27_bss_7F14) {
        lbl_27_bss_7F18.vt = __vt__10soNullable;
        lbl_27_bss_7F18.p = lbl_27_data_B750;
        lbl_27_bss_7F18.vt = lbl_27_data_B750 + 8;
        lbl_27_bss_7F18.flag = 0;
        lbl_27_bss_7F18.p = lbl_27_data_B6E0;
        lbl_27_bss_7F18.vt = lbl_27_data_B6E0 + 8;
        __register_global_object(&lbl_27_bss_7F18, (void*)fn_27_7DE60, lbl_27_bss_7F08);
        lbl_27_bss_7F14 = 1;
    }
    Obj* o = &lbl_27_bss_7F18;
    if (!lbl_27_bss_1088) {
        GlobalObject* p = new (&lbl_27_bss_108C) GlobalObject;
        __register_global_object(p, (void*)fn_27_7DC10, lbl_27_bss_7ED8);
        lbl_27_bss_1088 = 1;
    }
    fn_27_5C7AC((char*)self + 0xac, arg1, s, o, &lbl_27_bss_108C, arg2);
    return self;
}