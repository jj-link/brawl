#include <types.h>
#include <ft/ft_common_data_accesser.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
void* __dynamic_cast(void*, long, const void*, const void*, short);
unsigned int fn_27_14DC0C(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_1DF5F8(void*, int, void*, void*, int);
unsigned int fn_27_111E30(void*);
void fn_27_1E1B14(void*, void*, int, void*, int, int, float*, unsigned int,
                  int, int, int, int, int, int, int, int, int, int);
extern char lbl_27_data_2C0C0[];
extern char lbl_27_data_CBA0[];
extern float lbl_27_rodata_25D0;
}

class Hobj {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual int s20();
};

struct StageBase {
    char pad[0x28];
    void* f28;
    char pad2[0x10];
};

class Stage : public StageBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4();
    virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9();
    virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14();
    virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24();
    virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29();
    virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34();
    virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39();
    virtual int s40();
    virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45();
    virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50();
    virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55();
    virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60();
    virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65();
    virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70();
    virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75();
    virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80();
    virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85();
    virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90();
    virtual void s91(); virtual void s92(); virtual void s93(); virtual void s94(); virtual void s95();
    virtual void s96(); virtual void s97(); virtual void s98(); virtual void s99(); virtual void s100();
    virtual void s101(); virtual void s102(); virtual void s103(); virtual void s104(); virtual void s105();
    virtual void s106(); virtual void s107(); virtual void s108(); virtual void s109(); virtual void s110();
    virtual void s111(); virtual void s112(); virtual void s113(); virtual void s114(); virtual void s115();
    virtual void s116(); virtual void s117(); virtual void s118(); virtual void s119(); virtual void s120();
    virtual void s121(); virtual void s122(); virtual void s123(); virtual void s124(); virtual void s125();
    virtual void s126();
    virtual void s127(int);
    char pad3[0x88 - 0x40];
    Hobj sub;
};

class Vt0 {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual int s4(int);
    virtual void s5(); virtual void s6(); virtual void s7();
    virtual int s8();
    virtual void s9();
    virtual int s10();
    virtual void s11(); virtual void s12();
    virtual void s13(void*);
    virtual void s14();
    virtual int s15();
};

struct CBase { char pad[8]; };
class CObj : public CBase {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void* s4();
};

struct CList {
    char* base;
    unsigned int count;
};

struct BObj {
    CObj* c;          // 0x00
    char pad0[0x60];
    Vt0* f64;         // 0x64
    char pad1[0x1c];
    Vt0* f84;         // 0x84
    char pad2[0x38];
    int fc0;          // 0xc0
};

struct Self {
    char pad0[8];
    Stage* a;         // 0x08
    char pad1[0xcc];
    BObj* b;          // 0xd8
};

struct DfArgs {
    int* p;
    int a;
    int b;
    int c;
};

extern "C" void fn_27_18DAE4(void* unused, Self* self, int arg2, unsigned int arg3) {
    if (arg2 != -1) {
        float fv[3];
        DfArgs args;
        Vt0* r31;
        Stage* t;
        int kind;
        unsigned int r;
        char* ptr;
        unsigned int v26;
        int v25;
        int v24;
        int v23;
        int v22;

        kind = self->a->s40();
        r = fn_27_14DC0C(__dynamic_cast(self->b->c->s4(), 0, lbl_27_data_2C0C0, lbl_27_data_CBA0, 1));
        if (r != 0xffff) {
            ptr = 0;
            ftData* data = g_ftCommonDataAccesser.getData((ftKind)kind);
            CList* list = *(CList**)((char*)data + 0x64);
            if (list != 0 && arg3 < list->count) {
                ptr = list->base + arg3 * 0x38;
            }

            args.c = kind;
            args.b = 0;
            int value = self->b->fc0;
            args.p = &args.b;
            args.a = value;
            r31 = self->b->f84;

            t = (Stage*)__nw__FUlQ25Heaps8HeapType(0x16c8, 0x1f);
            if (t != 0) {
                t = (Stage*)fn_27_1DF5F8(t, arg2, &args, ptr, 1);
            }
            t->s127(1);

            v26 = 0xffff;
            v24 = -1;
            v25 = v26;
            v23 = 0;
            v22 = 1;

            switch (kind) {
            case 0x16: {
                Vt0* d = (Vt0*)self->b->c->s4();
                v25 = d->s10();
                Vt0* e = (Vt0*)self->b->c->s4();
                v26 = e->s8();
                v24 = 0;
                Vt0* f = self->b->f64;
                int g = f->s4(0x10000000);
                if (fn_27_111E30(g_ftManager->getOwner(g)) == 1) {
                    v22 = 0;
                }
                break;
            }
            case 0x0c: {
                Vt0* d = (Vt0*)self->b->c->s4();
                v25 = d->s15();
                Vt0* e = (Vt0*)self->b->c->s4();
                v26 = e->s8();
                break;
            }
            case 0x19: {
                Vt0* f = self->b->f64;
                int g = f->s4(0x10000000);
                if (fn_27_111E30(g_ftManager->getOwner(g)) == 1) {
                    v23 = 1;
                    Vt0* d = (Vt0*)self->b->c->s4();
                    v26 = d->s8();
                    v22 = 0;
                }
                break;
            }
            }

            fv[0] = lbl_27_rodata_25D0;
            fv[1] = lbl_27_rodata_25D0;
            fv[2] = lbl_27_rodata_25D0;
            fn_27_1E1B14(t, self->a->f28, r, ptr, v22, 0, fv, v26, v25, 0, 1, 0, v24, v23, 0, 2, 0, 0);

            if (t->sub.s20() != 0) {
                r31->s13(&t->sub);
            }
        }
    }
}
