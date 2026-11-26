#include <types.h>
#pragma force_active on

class Class_1250 {
public:
    virtual void fn_27_13C90();
    virtual void fn_27_14068();
    virtual void fn_27_140C0();
    virtual void fn_27_1412C(int a, void* b);
    virtual void fn_27_14134();
    virtual void fn_27_14370();
    virtual void fn_27_14A28();
    virtual void fn_27_14A30();
    virtual void fn_27_14A38();
    virtual void fn_27_14A48();
    virtual void fn_27_14A68();
    virtual void fn_27_14AD8();
    virtual void fn_27_14A60();
    virtual void fn_27_14D08();
    virtual void fn_27_14EDC();
    virtual void fn_27_14D00();
    virtual int fn_27_14B80();
    virtual void fn_27_14B88();
};

struct Class_90D8_base { char pad[0x8]; };
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
    virtual int fn_27_7B22C(void* a);
};

class soStopModuleImpl {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int slot3();
    virtual int slot4(int a);
    virtual void cancelHitStop(int a, int b);
    virtual void setOtherStop();
    virtual void cancelOtherStop();
    virtual void setLinkStop();
    virtual void isStop();
    virtual void isSpecialStop();
    virtual void isHit();
    virtual void isDamage();
    virtual void update();
    virtual void slot14();
    virtual void getHitStopRealFrame();
    virtual void setHitStopFrame();
    virtual int setHitStopFrameFix(int a);
};

class Class_4328 {
public:
    virtual void fn_27_48BE8();
    virtual void fn_27_48DA8();
    virtual void fn_27_48E2C();
    virtual void fn_27_48ED0();
    virtual void fn_27_48F28(int a, void* b, float c);
    virtual void fn_27_48D24();
    virtual void fn_27_48F34(int a, void* b, int c, float d);
    virtual void fn_27_48FB0();
    virtual void fn_27_4902C();
    virtual void fn_27_49094();
    virtual void fn_27_490DC();
    virtual void fn_27_49190();
    virtual void fn_27_49238();
    virtual void fn_27_49290();
    virtual void fn_27_492F8();
    virtual void fn_27_4938C();
    virtual void fn_27_493C0();
    virtual void fn_27_493F4();
};

class soPostureModuleImpl {
public:
    virtual void isNull();
    virtual ~soPostureModuleImpl();
    virtual int* fn_27_2362C(int a);
    virtual void fn_27_236B0();
    virtual void fn_27_25088();
    virtual void fn_27_23E84();
    virtual void fn_27_25184();
    virtual void fn_27_2370C();
    virtual void fn_27_23728();
    virtual void fn_27_23E28();
    virtual void fn_27_23CC0();
    virtual void fn_27_25068();
    virtual void fn_27_23A9C();
    virtual void fn_27_23B18();
    virtual void fn_27_250FC();
    virtual void fn_27_250A4();
    virtual void fn_27_23BF8();
    virtual void fn_27_251B8();
};

class soNullable {
public:
    virtual void isNull();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
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
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19(int a, int b);
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual void slot28();
    virtual void slot29();
    virtual void slot30();
    virtual void slot31();
    virtual void slot32();
    virtual void slot33();
    virtual void slot34();
    virtual void slot35();
    virtual void slot36();
    virtual void slot37();
    virtual void slot38();
    virtual void slot39();
    virtual void slot40();
    virtual void slot41();
    virtual void slot42();
    virtual void slot43(float a);
    virtual float slot44();
};

struct Class_2C0_base { char pad[0x4]; };
class Class_2C0 : public Class_2C0_base {
public:
    virtual void fn_27_5378();
    virtual void fn_27_6CA4();
    virtual void fn_27_6C80();
    virtual void fn_27_6C5C();
    virtual void fn_27_6C54();
    virtual float fn_27_6C34(void* a, int b, int c);
    virtual int fn_27_6C18(void* a, int b, int c);
};

class Class_16D80 {
public:
    virtual void fn_27_B21D0();
    virtual void fn_27_B4674();
    virtual void fn_27_B2228();
    virtual void fn_27_B2248();
    virtual void fn_27_B2304();
    virtual void fn_27_B2348();
    virtual void fn_27_B238C();
    virtual void fn_27_B242C();
    virtual void fn_27_B24B0();
    virtual void fn_27_B2530();
    virtual void fn_27_B2668();
    virtual void fn_27_B48D0();
    virtual void fn_27_B2728(int a, u8 b, int c);
    virtual void fn_27_B2888();
    virtual void fn_27_B294C();
    virtual void fn_27_B2A10();
    virtual void fn_27_B2A24();
    virtual void fn_27_B2A58();
};

extern "C" {
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_5BCD0(void*);
unsigned int fn_27_5BEA8(void*);
unsigned int fn_27_5BE80(void*);
void fn_27_2B561C(void*, void*, int);
void fn_27_553C(void*);
void fn_27_289564(void*);
int randi__Fl(long);
extern void* lbl_27_bss_F0;
extern const float lbl_27_rodata_4610;
extern const float lbl_27_rodata_4614;
}

extern char lbl_27_bss_71C8[];

inline void process_289924(int tC, void* self) {
    int tN;
    char* cs = (char*)self;
    int tD;
    int tE;
    int tF;
    int tG;
    int tH;
    int tI;
    int d;
    int var;
    int* flags;
    int v;
    float a;
    float w;

    if ((*(Class_1250**)(*(char**)(cs + 0x1A4) + 0x70))->fn_27_14B80() == 0) {
        fn_27_553C(self);
        return;
    }
    if (((Class_90D8*)*(char**)(cs + 0x8D0))->fn_27_7B22C(self) == 0) {
        return;
    }
    soStopModuleImpl* m = (soStopModuleImpl*)(cs + 0x2AAC);
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BEA8(lbl_27_bss_F0) == 1) {
        fn_27_2B561C(cs + 0x3474, cs + 0xCC, 1);
    }
    if (lbl_27_bss_F0 == 0) {
        void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
        if (p != 0) {
            p = fn_27_5BCD0(p);
        }
        lbl_27_bss_F0 = p;
    }
    if (fn_27_5BE80(lbl_27_bss_F0) != 1) {
        goto L_E00;
    }
    tC = m->slot4(0x1000000B);
    if (tC > 0) {
        m->cancelHitStop(--tC, 0x1000000B);
        if (tC == 0) {
            m->cancelHitStop(1, 0x10000004);
            ((Class_4328*)(cs + 0x33D0))->fn_27_48F34(5, cs + 0xCC, 2, lbl_27_rodata_4610);
            ((Class_4328*)(cs + 0x33D0))->fn_27_48F28(5, cs + 0xCC, lbl_27_rodata_4614);
        }
    }
    tC = m->slot4(0x1000000C);
    if (tC > 0) {
        m->cancelHitStop(--tC, 0x1000000C);
        if (tC == 0) {
            m->cancelHitStop(2, 0x10000004);
            ((Class_4328*)(cs + 0x33D0))->fn_27_48F34(5, cs + 0xCC, 2, lbl_27_rodata_4610);
            ((Class_4328*)(cs + 0x33D0))->fn_27_48F28(5, cs + 0xCC, lbl_27_rodata_4614);
        }
    }
    tD = m->slot4(0x1000001C) + 1;
    if (tD > 0) {
        m->cancelHitStop(tD, 0x1000001C);
    }
    if (m->setHitStopFrameFix(0x12000005) == 0) {
        goto L_E00;
    }
    tE = m->slot4(0x10000017);
    m->cancelHitStop(++tE, 0x10000017);
    flags = ((soPostureModuleImpl*)(cs + 0x297C))->fn_27_2362C(8);
    if (!(*flags & 0x4000)) {
        ((Class_4328*)(cs + 0x33D0))->fn_27_48F34(4, cs + 0xCC, 1, lbl_27_rodata_4610);
    }
    if ((*(Class_1250**)(*(char**)(cs + 0x1A4) + 0x70))->fn_27_14B80() != 5) {
        goto L_E00;
    }
    v = *((soPostureModuleImpl*)(cs + 0x297C))->fn_27_2362C(8);
    var = ((v & 0x100000) | (v & 0xF)) != 0;
    if (*(int*)(cs + 0x8C0) == 0x57) {
        var = 0;
    }
    if (var) {
        a = ((soNullable*)(cs + 0x15C0))->slot44();
        w = ((Class_2C0*)lbl_27_bss_71C8)->fn_27_6C34(cs + 0xCC, 0xD62, 0);
        ((soNullable*)(cs + 0x15C0))->slot43(a * w);
    }
    if ((*((soPostureModuleImpl*)(cs + 0x297C))->fn_27_2362C(8)) & 0x815D01) {
        goto L_E00;
    }
    if (tE < ((Class_2C0*)lbl_27_bss_71C8)->fn_27_6C18(cs + 0xCC, 0x59DA, 0)) {
        if (tE <= 1) {
            goto L_E00;
        }
        tI = ((Class_2C0*)lbl_27_bss_71C8)->fn_27_6C18(cs + 0xCC, 0x59DB, 0);
        if (randi__Fl(100) >= tI) {
            goto L_E00;
        }
    }
    ((Class_1250*)(cs + 0x2C34))->fn_27_1412C(6, cs + 0xCC);
    return;

L_E00:
    fn_27_553C(self);
    if ((*(u8*)(cs + 0x2C) >> 6) & 1) {
        fn_27_289564(self);
        if (lbl_27_bss_F0 == 0) {
            void* p = __nw__FUlQ25Heaps8HeapType(0x4C, 2);
            if (p != 0) {
                p = fn_27_5BCD0(p);
            }
            lbl_27_bss_F0 = p;
        }
        if (fn_27_5BE80(lbl_27_bss_F0) == 1) {
            tF = m->slot4(0x1000000A);
            if (tF > 0) {
                m->cancelHitStop(--tF, 0x1000000A);
                if ((*(Class_1250**)(*(char**)(cs + 0x1A4) + 0x70))->fn_27_14B80() != 2) {
                    tH = ((Class_2C0*)lbl_27_bss_71C8)->fn_27_6C18(cs + 0xCC, 0x59DD, 0);
                    tI = ((Class_2C0*)lbl_27_bss_71C8)->fn_27_6C18(cs + 0xCC, 0x59DC, 0);
                    d = tF - (tI - tH);
                    if (tF == 0) {
                        ((soNullable*)(cs + 0x19CC))->slot19(0, 0);
                        d = 0;
                    }
                    if (d == 0 && ((soStopModuleImpl*)(cs + 0x3AB4))->slot3() > 2) {
                        ((Class_16D80*)(cs + 0x3A68))->fn_27_B2728(2, *(u8*)(cs + 0x3C68), -1);
                    }
                }
            }
        }
    }
}

extern "C" void fn_27_289924(void* self) {
    process_289924(0, self);
}
