#pragma force_active on
struct Obj { char pad[0xA0]; int a0; char pad2[0x4C]; int f0; };
struct gfTask { char pad[0x40]; int s; int c; };
extern "C" {
void exit__6gfTaskFv(gfTask*);
Obj* fn_80030548(int);
int fn_800305B0(int);
void fn_800307B4();
int fn_80030DEC(Obj*, int);
int fn_80030F2C(Obj*);
void fn_8004EEC8(int, int);
}
extern int g_GameGlobal;
extern int lbl_8059CE48;
extern int lbl_805A00F0;
extern Obj* lbl_805A00F8;
extern int lbl_805A00FC;

extern "C" void fn_8005A238(gfTask* t) {
    if (lbl_805A00FC) {
        if (lbl_805A00F8) { fn_800307B4(); lbl_805A00F8 = 0; }
        lbl_805A00F0 = 0;
        exit__6gfTaskFv(t);
        return;
    }
    switch (t->s) {
    case 0: {
        if (!fn_800305B0(0)) { t->s = 3; return; }
        lbl_805A00F8 = fn_80030548(lbl_8059CE48);
        if (!lbl_805A00F8) { t->s = 3; return; }
        int r = fn_80030DEC(lbl_805A00F8, 0);
        if (!r) { t->s = 3; return; }
        fn_8004EEC8(g_GameGlobal, r);
        if (!fn_80030F2C(lbl_805A00F8)) { t->s = 3; return; }
        t->s = 1; t->c = 0;
        break;
    }
    case 1:
        t->c++;
        if (!lbl_805A00F8->f0) t->s = 2;
        break;
    case 2:
        switch (lbl_805A00F8->a0) {
        case 3:
        default: t->s = 3; break;
        case 1: t->s = 3; break;
        case 2: t->s = 3; break;
        case 0: t->s = 3; break;
        }
        break;
    case 3:
        if (lbl_805A00F8) { fn_800307B4(); lbl_805A00F8 = 0; }
        exit__6gfTaskFv(t);
        break;
    }
}