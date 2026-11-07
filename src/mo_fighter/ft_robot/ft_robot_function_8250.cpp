#pragma force_active on
struct Obj {
    virtual int s0(); virtual int sx1(); virtual int s2(); virtual Obj* s3(int,bool,bool);
    virtual int s4(); virtual int s5(); virtual int s6(); virtual int s7();
    virtual int s8(); virtual int s9(); virtual int s10(); virtual int s11();
    virtual int s12(); virtual void s13(Obj*); virtual int s14(); virtual int s15();
    virtual void s16(int,int); virtual int s17(int); virtual int s18(); virtual void s19(int,int);
    virtual int s20(int); virtual int s21(); virtual int s22(); virtual int s23();
    virtual int s24(); virtual int s25(); virtual int s26(); virtual int s27();
    virtual int s28(); virtual int s29(); virtual int s30(); virtual int s31();
    virtual int s32(); virtual int s33(); virtual int s34(); virtual int s35();
    virtual int s36(); virtual int s37(); virtual int s38(); virtual int s39();
    virtual int s40(); virtual int s41(); virtual int s42(); virtual int s43();
    virtual int s44(); virtual int s45(); virtual int s46(); virtual int s47();
    virtual int s48(); virtual int s49(); virtual int s50(); virtual int s51();
    virtual int s52(); virtual int s53(); virtual int s54(); virtual int s55();
    virtual void s56(int,int);
};
struct Mods {
    char p[0x20]; Obj* a20; char q[0x38]; Obj* a5c; char s[4]; Obj* a64; char r[0x1c]; Obj* a84;
};
struct Acc { char p[0xd8]; Mods* m; };
extern "C" void fn_27_13138C(void*, int, int, void*, void*);
extern "C" void fn_120_8250(void* a, int k, int b, void* c, Acc* d) {
    if (d->m->a64->s17(0x12000042)) {
        Obj* o = d->m->a84;
        d->m->a20->s19(2, 0);
        if (k == 0xbd) goto yes;
        if (k < 0xbd) {
            if (k < 0x5f) {
                if (k < 0x4a) {
                    if (k >= 0x3d) goto yes;
                    goto no;
                }
                if (k >= 0x5c) goto yes;
                goto no;
            }
            if (k >= 0x71) goto no;
            if (k >= 0x6e) goto yes;
            goto no;
        }
        if (k < 0xe6) {
            if (k >= 0xdc) goto no;
            if (k >= 0xcc) goto yes;
            goto no;
        }
        if (k >= 0xf1) goto no;
    yes:
        o->s16(3, 0);
        d->m->a5c->s56(2, 8);
        goto end;
    no:
        if (o->s20(3)) {
            bool z = false;
            Obj* s = o->s3(3, z, z);
            if (!s->s0()) o->s13(s);
        }
    }
end:
    fn_27_13138C(a, k, b, c, d);
}