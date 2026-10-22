#pragma force_active on
extern "C" void fn_800969CC(void*, unsigned int, unsigned int);
extern const float lbl_27_rodata_320;

struct Obj {
    virtual void v0();
    virtual Obj* v1(int);
};

struct Pad8 {
    int a;
    int b;
};

struct Self : Pad8 {
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
    virtual unsigned int s56(int);

    char rest[0x24];
    int f30;
    Obj* f34;
};

extern "C" void fn_27_12B80(Self* self, int arg1, float farg0) {
    if (self->f30 != 0) {
        Obj* o = self->f34;
        if (farg0 != *(float*)((char*)o->v1(arg1) + 0x34)) {
            unsigned int t30 = self->s56(arg1);
            *(float*)((char*)self->f34->v1(arg1) + 0x34) = farg0;
            unsigned int r = self->s56(arg1);
            if (r != t30) {
                if (r == 0) {
                    void* a = self->f34->v1(arg1);
                    void* b = self->f34->v1(arg1);
                    void* c = self->f34->v1(arg1);
                    *(float*)((char*)a + 0x18) = lbl_27_rodata_320;
                    *(float*)((char*)b + 0x14) = lbl_27_rodata_320;
                    *(float*)((char*)c + 0x10) = lbl_27_rodata_320;
                }
                if (self->f30 != 0) {
                    void* d = self->f34->v1(arg1);
                    fn_800969CC((void*)self->f30, *(unsigned int*)d, r);
                }
            }
        }
    }
}
