#pragma force_active on

struct Res {
    void *unk0;
    void *unk4;
    void *unk8;
};

struct St {
    Res *m_res;
    void *m_unk4;
};

extern "C" void fn_802ECBC0(void *, void *);
extern "C" void __dl__FPv(void *);
extern char lbl_80454A90[];

extern "C" void *fn_80096048(St *p, int flag) {
    if (p) {
        Res *r = p->m_res;
        p->m_unk4 = lbl_80454A90;
        if (r) {
            if (r->unk8) {
                fn_802ECBC0(r->unk8, r);
            }
            p->m_res = 0;
        }
        if (flag > 0) {
            __dl__FPv(p);
        }
    }
    return p;
}
