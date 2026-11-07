#include <types.h>
#pragma force_active on

class Class_90D8_base { public: char pad[8]; };
class Class_90D8 : public Class_90D8_base {
public:
    virtual void fn_27_7B274();
    virtual void fn_27_7AC18();
    virtual void fn_27_7AC28();
    virtual void fn_27_7AB50();
    virtual void fn_27_7B2EC();
    virtual void fn_27_7AB10();
    virtual void fn_27_7AD2C();
    virtual void fn_27_7AEDC();
    virtual void fn_27_7B22C();
    virtual void fn_27_7AC38(void*);
    virtual int fn_27_7ADE8();
};
class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void* slot4(unsigned int);
    virtual void slot5(void*, int, int, int);
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual int slot16();
    virtual int slot17(unsigned int);
    virtual void slot18();
    virtual void slot19();
    virtual void slot20(int, unsigned int);
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual Class_90D8* slot28();
};
extern "C" {
extern void* lbl_27_bss_F0;
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_5CA4(void*);
void fn_27_28A4F8(void*);
void fn_27_289FB4(unsigned char* obj) {
    fn_27_5CA4(obj);
    int flag = (*(Object_vptr_0**)(*(unsigned char**)(obj + 0x1a4) + 0x70))->slot16() == 0;
    if (lbl_27_bss_F0 == 0) {
        void* singleton = __nw__FUlQ25Heaps8HeapType(0x4c, 2);
        if (singleton != 0)
            singleton = fn_27_5BCD0(singleton);
        lbl_27_bss_F0 = singleton;
    }
    int active = 0;
    if (fn_27_5BE80(lbl_27_bss_F0) == 1 && flag == 0)
        active = 1;
    if (active) {
        Object_vptr_0* work = (Object_vptr_0*)(obj + 0x2aac);
        if (((Object_vptr_0*)(obj + 0x3a68))->slot28()->fn_27_7ADE8()) {
            if (!work->slot17(0x1200000d)) {
                work->slot20(1, 0x1200000d);
                void* value = work->slot4(0x10000019);
                if (value)
                    ((Object_vptr_0*)(obj + 0x25a0))->slot5(value, 0, 0, 0);
            }
        } else {
            work->slot20(0, 0x1200000d);
        }
    }
    (*(Class_90D8**)(obj + 0x8d0))->fn_27_7AC38(obj);
    if (active)
        fn_27_28A4F8(obj);
}
}