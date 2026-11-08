#pragma force_active on
#include <types.h>

struct ObjA {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual int s4(int);
};

struct ObjB {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual void s22();
    virtual void s23();
    virtual void s24();
    virtual void s25();
    virtual int s26(int);
    virtual void* s27(int, int);
};

struct ObjC {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3(int, void*);
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
};

struct ObjD {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9(int, void*, int, int, int);
};

struct GfTaskBase { char pad[0x3c]; };
struct GfTaskObj : public GfTaskBase {
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual void s9();
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual void s16();
    virtual void s17();
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
    virtual int s40();
};

struct Item {
    char pad0[4];
    unsigned int id;
    char pad8[4];
    unsigned char kind;
};

struct Mod {
    char pad1[0x64];
    ObjA* objA;
    char pad2[0x8];
    ObjC* objC;
    char pad3[0x1c];
    ObjB* objB;
    char pad4[0x14];
    ObjD* objD;
};

struct Ctx {
    char pad1[0x8];
    GfTaskObj* gfTask;
    char pad2[0xcc];
    Mod* mod;
};

extern "C" void* getInstance__9itManagerFv();
extern "C" void* fn_27_2A88C4(void*, unsigned int);
extern "C" int fn_27_28DCF8(void*);

extern "C" int fn_27_3962BC(void* unused, Ctx* c) {
    Mod* mod = c->mod;
    ObjD* objD = mod->objD;
    ObjC* objC = mod->objC;
    ObjB* objB = mod->objB;
    int val = mod->objA->s4(0x20000008);
    int count = objB->s26(val);
    int hits = 0;
    int stage = c->gfTask->s40();
    int r24 = 0x196;
    if (stage == 0x20) {
        r24 = 6;
    }

    for (int i = 0; i < count && hits < 4; i++) {
        Item* item = (Item*)objB->s27(val, i);
        if (item->kind == 3) {
            void* result = fn_27_2A88C4(getInstance__9itManagerFv(), item->id);
            if (result != 0 && fn_27_28DCF8(result) != 0) {
                switch (((GfTaskObj*)result)->s40()) {
                case 0:
                case 13:
                case 20:
                case 27:
                case 29:
                    objD->s9(r24, result, hits + 3, 0, 0);
                    break;
                default:
                    objD->s9(r24, result, hits + 3, 0, 1);
                    break;
                }
                hits++;
                if (c->mod->objC->s16() != 0x112) {
                    if (c->mod->objC->s16() != 0x117) {
                        if (c->mod->objC->s16() != 0x192) {
                            if (c->mod->objC->s16() != 0x193) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
    }

    if (hits > 0) {
        if (stage == 5) {
            objC->s3(0x1a3, c);
        } else {
            objC->s3(0x127, c);
        }
        return 1;
    }
    return 0;
}
