#pragma force_active on

struct Obj { char pad[0xA0]; int a0; char pad2[0x4C]; int f0; };
struct gfTask { char pad[0x40]; int s; int c; unsigned char flag; char pad2[3]; Obj* p; };

extern "C" {
void exit__6gfTaskFv(gfTask*);
Obj* fn_80030548(int);
int fn_800305B0(int);
void fn_800307B4();
int fn_80030DEC(Obj*, int);
int fn_80030F2C(Obj*);
int fn_80030F38(Obj*, int);
void fn_8004EEC8(int, int);
void fn_8004F168(int, int);
}
extern int g_GameGlobal;
extern int lbl_805A0468;

extern "C" void fn_8015B87C(gfTask* t) {
    switch (t->s) {
    case 0: {
        if (!fn_800305B0(0)) { t->s = 6; return; }
        Obj* o = fn_80030548(0xC);
        t->p = o;
        if (!o) { t->s = 6; return; }
        int r = fn_80030DEC(o, 0);
        if (!r) { t->s = 6; return; }
        fn_8004EEC8(g_GameGlobal, r);
        if (!fn_80030F2C(t->p)) { t->s = 6; return; }
        t->s = 1; t->c = 0;
        return;
    }
    case 1:
        t->c++;
        if (!t->p->f0) t->s = 2;
        return;
    case 2:
        if (!t->p->a0) {
            if (t->flag) t->s = 6;
            else t->s = 3;
        } else {
            t->s = 6;
        }
        return;
    case 3: {
        if (!fn_800305B0(1)) { t->s = 6; return; }
        int r = fn_80030DEC(t->p, 1);
        if (!r) { t->s = 6; return; }
        fn_8004F168(g_GameGlobal, r);
        if (!fn_80030F38(t->p, 0)) { t->s = 6; return; }
        t->s = 4; t->c = 0;
        return;
    }
    case 4:
        t->c++;
        if (!t->p->f0) t->s = 5;
        return;
    case 5:
        t->s = 6;
        return;
    case 6:
        if (t->p) { fn_800307B4(); t->p = 0; }
        exit__6gfTaskFv(t);
        lbl_805A0468 = 0;
        return;
    }
}
