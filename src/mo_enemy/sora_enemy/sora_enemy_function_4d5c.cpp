#include <so/so_module_accesser.h>

#pragma force_active on

typedef unsigned long u32;

class Obj {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual u32 s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10(int, u32);
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual u32 s14();
    virtual void s15();
    virtual void s16();
    virtual void s17(u32);
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual void s26();
    virtual void s27();
    virtual void s28();
    virtual void s29();
    virtual void s30();
    virtual void s31();
    virtual void s32();
    virtual void s33();
    virtual void s34();
    virtual void s35();
    virtual void s36();
    virtual void s37();
    virtual void s38();
    virtual void s39();
    virtual void s40();
    virtual void s41();
    virtual void s42();
    virtual void s43();
    virtual void s44();
    virtual void s45();
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual void s54();
    virtual void s55();
    virtual void s56();
    virtual void s57();
    virtual void s58();
    virtual void s59();
    virtual void s60();
    virtual void s61();
    virtual void s62();
    virtual void s63();
    virtual void s64();
    virtual void s65();
    virtual void s66();
    virtual void s67();
    virtual void s68();
    virtual void s69();
    virtual void s70();
    virtual void s71();
    virtual void s72();
    virtual void s73();
    virtual void s74();
    virtual void s75();
    virtual void s76();
    virtual void s77();
    virtual void s78();
    virtual void s79();
    virtual void s80();
    virtual void s81();
    virtual void s82();
    virtual void s83();
    virtual void s84();
    virtual void s85();
    virtual void s86();
    virtual void s87();
    virtual u32 s88();
};

struct Table {
    char pad0[4];
    soModelModule* m4;
    char pad1[0x38];
    Obj* m40;
    char pad2[0x10];
    Obj* m54;
};

struct Holder {
    char pad[0x1b4];
    Table* t;
};

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
void fn_41_27A60(void*);
void fn_41_4C20(void*, Vec3f*);
int getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(void*, u32, u32);
extern const char lbl_41_data_6F0[];
extern const char lbl_41_data_14B8[];
}

extern "C" void fn_41_4D5C(char* self) {
    soModelModule* mod;
    u32 res;

    if (((Holder*)self)->t->m40->s5() == 1) {
        res = ((Holder*)self)->t->m54->s88();
        mod = ((Holder*)self)->t->m4;
        Vec3f buf = mod->getNodeGlobalPosition(
            getValueInt__15soValueAccesserFP16soModuleAccesserUlUl(
                self + 0xdc, 0x59e6, 0),
            false);

        if (res == 1) {
            ((Holder*)self)->t->m40->s16();
        }

        if (((Holder*)self)->t->m40->s14() == 1) {
            ((Holder*)self)->t->m40->s17(res);
        } else {
            ((Holder*)self)->t->m40->s10(1, res);
        }

        fn_41_4C20(self, &buf);
        fn_41_27A60(__dynamic_cast(
            ((Holder*)self)->t->m54, 0, lbl_41_data_6F0,
            lbl_41_data_14B8, (short)1));
    }
}
