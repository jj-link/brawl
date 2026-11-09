#pragma force_active on
extern "C" int fn_800B5854(void*, int, int, int, int);
extern unsigned char lbl_10_rodata_4E0[];
extern unsigned char lbl_10_rodata_4E8[];
struct Sub {
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3();
    virtual void f4(); virtual void f5(); virtual void f6(); virtual void f7();
    virtual void f8(); virtual void f9(); virtual void f10();
    virtual void f11(int, int); virtual void f12(); virtual void f13(int);
    virtual void f14(); virtual void f15();
    char pad[0xe4 - 4]; int m_e4;
};
struct Inner { char pad[0x10]; int m_10; };
struct GameInfo { char pad[4]; unsigned char m_4; };
struct GameGlobal { char pad[0x10]; GameInfo* m_10; };
extern GameGlobal* g_GameGlobal;
struct Self {
    char pad0[0x6c]; Sub* m_6c;
    char pad1[0x140 - 0x70]; void* m_140;
    char pad2[0x3c4 - 0x144]; Inner* m_3c4;
    char pad3[0x5e8 - 0x3c8]; int m_5e8;
};
extern "C" void fn_10_EFA8(Self* self, int flag) {
    Inner* p = self->m_3c4;
    self->m_6c->f13(p->m_10);
    if (flag != 0) {
        self->m_6c->f11(self->m_6c->m_e4, p->m_10);
        fn_800B5854(p, ((unsigned int)(1 - flag) | (unsigned int)(flag - 1)) >> 31, 0x11, 1, 0);
    }
    unsigned char c5 = lbl_10_rodata_4E0[flag];
    GameInfo* gi = g_GameGlobal->m_10;
    void* q = self->m_140;
    unsigned char st = gi->m_4;
    int r0;
    int r6;
    if ((int)st >= 0 && (int)st < 4) { r0 = 1; } else { r0 = 0; }
    if (r0 != 0) { r6 = 0; } else {
        if ((int)st >= 4 && (int)st < 12) { r0 = 1; } else { r0 = 0; }
        if (r0 != 0) { r6 = 1; } else {
            if ((int)st >= 12 && (int)st < 16) { r0 = 1; } else { r0 = 0; }
            r6 = 3;
            if (r0 != 0) { r6 = 2; }
        }
    }
    unsigned char m;
    int r6b;
    if (c5 <= 1) {
        m = lbl_10_rodata_4E8[r6 * 2];
        r6b = (c5 - 1) == 0;
    } else {
        r6b = 1;
        m = (r6 * 2 + lbl_10_rodata_4E8)[1];
    }
    fn_800B5854(q, m, 0x18, r6b, 0);
    self->m_5e8 = flag;
}