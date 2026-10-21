#pragma force_active on
struct IfInner {
    virtual void s00();
    virtual void s04();
    virtual void s08();
    virtual void s0C();
    virtual void s10();
    virtual void s14();
    virtual void s18();
    virtual void s1C();
    virtual void s20();
    virtual void s24();
    virtual void s28();
    virtual void v34(int a, int b);
    virtual void v38();
    virtual void v3C(int a);
    unsigned char pad[0xE0];
    int f_e4;
};

struct IfMngr {
    unsigned char pad[0x14];
    IfInner* sub14;
};

extern "C" IfMngr* g_IfMngr;

struct FtSelf {
    unsigned char pad[0x48];
    int f48;
    unsigned char pad2[0x59 - 0x4C];
    unsigned char flag59;
};

extern "C" void fn_103_10EF0(FtSelf* self, unsigned int mode) {
    if (mode == 1 && self->flag59 == 0) {
        IfInner* in = g_IfMngr->sub14;
        in->v34(in->f_e4, self->f48);
        self->flag59 = 1;
    } else if (mode == 0 && self->flag59 == 1) {
        int arg = self->f48;
        IfInner* in = g_IfMngr->sub14;
        if (in != 0) {
            in->v3C(arg);
        }
        self->flag59 = 0;
    }
}
