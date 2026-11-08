#pragma force_active on

extern "C" {
bool fn_27_2BA2E8(void* self, void* obj);
void* getInstance__16CameraControllerFv();
}
extern float lbl_27_rodata_467C;
extern float lbl_27_rodata_4680;

struct Vec3f { float x; float y; float z; };

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int slot4(unsigned long);
    virtual void slot5(int, unsigned long);
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
    virtual int slot17(unsigned long);
};

struct Object_vptr_4_base { char pad[0x4]; };
class Object_vptr_4 : public Object_vptr_4_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual int slot6(void*, int, int);
};

extern Object_vptr_4 lbl_27_bss_71C8;

template <int N> struct VtPad { char pad[N]; };
template <> struct VtPad<0> { };

template <int N>
class VtT : public VtPad<N> {
public:
    virtual void s0();
    virtual void s1();
    virtual void* s2(int);
    virtual void s3(int, void*);
    virtual Vec3f s4();
    virtual void s5();
    virtual void s6();
    virtual void s7();
    virtual void s8();
    virtual int s9(int);
    virtual void s10();
    virtual void s11();
    virtual void s12();
    virtual void s13();
    virtual void s14();
    virtual void s15();
    virtual int s16();
    virtual void s17();
    virtual void s18();
    virtual void s19();
    virtual void s20();
    virtual void s21();
    virtual float s22();
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
    virtual void s45(int);
    virtual void s46();
    virtual void s47();
    virtual void s48();
    virtual void s49();
    virtual void s50();
    virtual void s51();
    virtual void s52();
    virtual void s53();
    virtual float s54();
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
    virtual void s88();
    virtual void s89();
    virtual void s90();
    virtual void s91();
    virtual void s92();
    virtual void s93();
    virtual void s94();
    virtual void s95();
    virtual void s96();
    virtual void s97();
    virtual void s98();
    virtual void s99();
    virtual void s100();
    virtual void s101();
    virtual void s102();
    virtual void s103();
    virtual void s104();
    virtual void s105();
    virtual void s106();
    virtual void s107();
    virtual void s108();
    virtual void s109();
    virtual void s110();
    virtual void s111();
    virtual void s112();
    virtual void s113();
    virtual void s114();
    virtual void s115();
    virtual void s116();
    virtual void s117();
    virtual void s118();
    virtual void s119();
    virtual void s120();
    virtual void s121();
    virtual void s122();
    virtual void s123();
    virtual void s124();
    virtual void s125();
    virtual void s126();
    virtual void s127();
    virtual void s128();
    virtual void s129();
    virtual void s130();
    virtual void s131();
    virtual void s132();
    virtual void s133();
    virtual void s134();
    virtual void s135(int);
};

class VtJ {
public:
    virtual void s0();
    virtual void s1();
    virtual void s2();
    virtual void s3();
    virtual void s4();
    virtual void s5();
    virtual void s6();
    virtual void s7(int);
    virtual void s8();
    virtual unsigned int s9();
};

extern "C" void fn_27_28A4F8(char* self) {
    Object_vptr_0* work = (Object_vptr_0*)(self + 0x2AAC);
    void* e;
    int r27, r31, r29, r3, r4v, v, code, r29b, arg4;
    unsigned int cur;
    unsigned int* st;
    unsigned int t;
    unsigned char b;
    float f31, tt, rv;
    void* cc;
    float* ccf;

    r27 = ((VtT<0>*)(self + 0x2C34))->s16();
    *(unsigned char*)(self + 0x3D25) = 0;
    r31 = work->slot4(0x10000009);
    if (r31 <= 0) goto L790;
    r29 = work->slot17(0x12000006);
    if (r29 == 0) goto L634;
    st = (unsigned int*)((VtT<0>*)(self + 0x297C))->s2(8);
    if (*st & 0x4C00) goto L634;
    r3 = fn_27_2BA2E8(self + 0x3474, (void*)*(unsigned int*)(self + 0x60));
    if (r3 != 0) {
        e = *(void**)((char*)*(void**)(self + 0x1A4) + 0x70);
        if (((VtT<0>*)e)->s16() == 2) v = 1;
        else v = ((VtT<0>*)(self + 0x27A8))->s9(3);
        r3 = (v == 0);
    }
    if (r3 == 0) r3 = work->slot17(0x1200000C);
    r29 = r3;

L634:
    r4v = r27 - 2;
    r3 = 1;
    if ((unsigned int)r4v <= 5U && ((1 << r4v) & 0x31)) r3 = 0;
    if (r3 != 0) {
        if (((Object_vptr_4*)&lbl_27_bss_71C8)->slot6(self + 0xCC, 0x5B6F, 0) == 1) {
            if (r31 < ((Object_vptr_4*)&lbl_27_bss_71C8)->slot6(self + 0xCC, 0x59D9, 0)) goto L6D8;
        }
    }
    if (work->slot17(0x1200000A) == 0) goto L740;

L6D8:
    b = *(unsigned char*)(self + 0x3D24);
    r27 = (b != 0);
    if (r29 == 0) {
        if (work->slot17(0x1200000A) == 0) {
            *(unsigned char*)(self + 0x3D24) = 1;
            goto L728;
        }
    }
    *(unsigned char*)(self + 0x3D25) = 1;

L728:
    ((VtT<0x3C>*)self)->s135(r27);

L740:
    if (r29 == 0) goto L790;
    work->slot5(r31 - 1, 0x10000009);
    if (r31 - 1 > 0) goto L790;
    ((VtT<0>*)(self + 0x2C34))->s3(6, self + 0xCC);
    return;

L790:
    st = (unsigned int*)((VtT<0>*)(self + 0x297C))->s2(8);
    if ((*st & 0x0C00) == 0) return;
    st = (unsigned int*)((VtT<0>*)(self + 0x297C))->s2(8);
    t = *st;
    if (((t & 0x08000000) | (t & 0x4000)) != 0) return;
    e = *(void**)((char*)*(void**)(self + 0x1A4) + 0x70);
    if (((VtT<0>*)e)->s16() == 2) v = 1;
    else v = ((VtT<0>*)(self + 0x27A8))->s9(3);
    if (v != 0) return;
    e = *(void**)((char*)*(void**)(self + 0x1A4) + 0x70);
    if (((VtT<0>*)e)->s16() == 6) return;
    if (*(unsigned char*)(self + 0x3D26) != 0) return;

    r27 = 1;
    cc = getInstance__16CameraControllerFv();
    if (cc != 0) {
        const Vec3f& pos = ((VtT<0>*)(self + 0xDB4))->s4();
        *(float*)&pos.x = pos.x + *(float*)(self + 0x28BC);
        *(float*)&pos.y = pos.y + *(float*)(self + 0x28C0);
        f31 = ((VtT<0>*)(self + 0xDB4))->s22();
        rv = ((VtT<8>*)(self + 0xA04))->s54();
        tt = *(float*)(self + 0x28C8) * rv;
        tt = tt * f31;
        tt = lbl_27_rodata_4680 * tt;
        f31 = lbl_27_rodata_467C + tt;
        cc = getInstance__16CameraControllerFv();
        ccf = (float*)cc;
        if (pos.x + f31 < ccf[0x148 / 4]) goto L934;
        if (pos.x - f31 > ccf[0x14C / 4]) goto L934;
        if (pos.y - f31 > ccf[0x150 / 4]) goto L934;
        if (!(pos.y + f31 < ccf[0x154 / 4])) goto L938;
L934:
        r27 = 0;
L938:;
    }

    cur = ((VtJ*)(self + 0x27FC))->s9();
    if ((unsigned int)r27 == cur) return;
    code = *(int*)(self + 0x8C0);
    r29b = 0;
    switch (code) {
    case 0x67:
    case 0x6A:
        r29b = 1;
        break;
    }
    ((VtJ*)(self + 0x27FC))->s7(r27);
    if (r27 != 0) arg4 = *(unsigned char*)(self + 0x3D27);
    else arg4 = r29b;
    ((VtT<0>*)(self + 0x38CC))->s45(arg4);
}
