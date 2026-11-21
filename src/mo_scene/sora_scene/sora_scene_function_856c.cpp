#include <cm/cm_camera_controller.h>
#pragma force_active on

typedef unsigned char u8;

struct A { int x[0x24]; };
struct B { int x[0xa1]; };
struct G8 { u8 a, b, c, pad; int w; A m; B n; };
struct Global { int x[2]; G8* data; };

struct Stage {
    char pad[0x57];
    u8 a, b;
    char pad59[4];
    u8 flag7 : 1;
    u8 flagRest : 7;
};

struct Manager { Stage* p[14]; };
struct Obj54 { char pad[0x50]; Stage* stage; };
struct Obj48 { char pad[0x3c]; void* vt; };
struct Link68 { char pad[0x48]; Stage* p[7]; };
struct Link44 { char pad[0x74]; Stage* p[7]; void* other; };
struct Link48 { char pad[0x58]; Stage* p[7]; };
struct LinkB0 { char pad[0x10]; Obj54* p[7]; Link68* a; void* b; };
struct Link54 { char pad[0xcc]; Stage* a; Stage* b; char padD4[0x128]; Stage* c; };

struct Scene {
    char pad[8];
    Stage* p[8];
    Stage* q;
    Stage* r;
    Stage* s;
    Stage* t;
    Stage* u;
    Stage* v;
    char pad40[4];
    Link44* a;
    Link48* b;
    char pad4c[8];
    Link54* c;
    char pad58[8];
    Obj48* d;
    void* e;
    Link68* f;
    Obj54* g[7];
    char pad88[0x28];
    LinkB0* h;
    char padb4[0x24];
    u8 flags;
};

extern "C" {
extern Global* g_GameGlobal;
extern Manager* g_stLoaderManager;
extern void* g_ftManager;
extern void* g_gfApplication;
extern G8 lbl_1_bss_90;
extern char lbl_1_data_1E00[];
extern char lbl_1_data_1F88[];

void fn_1_139E0(void*);
void fn_1_1A4DC(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_255420(void*);
void fn_27_2554C0(void*, int);
void fn_8004E858(void*);
void fn_80016900(void*, int, int);
void fn_27_109148(void*, int);
void fn_27_23BB10(Stage*);
void* fn_27_2454E0(void*);
void fn_27_1F1844(int);
LinkB0* fn_27_27CBE0();
void* fn_27_244240(void*);
void* fn_27_246E74(void*, int);
void fn_27_241E30(void*, void*);
void* fn_27_24FCC4(void*);
}

inline void copyGameData(G8* dst, const G8* src) {
    u8* d = (u8*)dst;
    const u8* s = (const u8*)src;
    u8 value = *s++;
    *d++ = value;
    value = *s++;
    *d++ = value;
    value = *s;
    *d = value;
    dst->m = src->m;
    dst->n = src->n;
}

static inline Obj48* makeD() {
    Obj48* q = (Obj48*)__nw__FUlQ25Heaps8HeapType(0x48, 2);
    if (q) {
        fn_27_241E30(q, lbl_1_data_1F88);
        q->vt = lbl_1_data_1E00;
    }
    return q;
}

extern "C" void fn_1_856C(Scene* self) {
    fn_1_139E0(self);

    G8* dst = &lbl_1_bss_90;
    const G8* src = g_GameGlobal->data;
    copyGameData(dst, src);

    void* x = __nw__FUlQ25Heaps8HeapType(0x48, 2);
    if (x) {
        x = fn_27_255420(x);
    }
    self->e = x;
    fn_27_2554C0(x, (((u8*)&lbl_1_bss_90)[0x8a] >> 6) & 1);
    fn_8004E858(g_GameGlobal);
    fn_80016900(g_gfApplication, 0, 0);
    fn_1_1A4DC(self);

    self->p[0] = g_stLoaderManager->p[0];
    self->p[1] = g_stLoaderManager->p[1];
    self->p[2] = g_stLoaderManager->p[2];
    self->p[3] = g_stLoaderManager->p[3];
    self->p[4] = g_stLoaderManager->p[4];
    self->p[5] = g_stLoaderManager->p[5];
    self->p[6] = g_stLoaderManager->p[6];
    self->p[7] = g_stLoaderManager->p[7];
    self->t = g_stLoaderManager->p[8];
    self->r = g_stLoaderManager->p[9];
    self->s = g_stLoaderManager->p[10];
    self->q = g_stLoaderManager->p[11];
    self->u = g_stLoaderManager->p[12];
    self->v = g_stLoaderManager->p[13];
    fn_27_109148(g_ftManager, 0);

    for (int i = 0; i < 7; ++i) {
        if (self->p[i]) {
            self->p[i]->a = 2;
        }
        if (self->p[i]) {
            self->p[i]->b = 0;
        }
        if (self->p[i]) {
            fn_27_23BB10(self->p[i]);
        }
        if (self->p[i]) {
            self->p[i]->flag7 = 0;
        }
        if (self->p[i]) {
            Obj54* p = (Obj54*)__nw__FUlQ25Heaps8HeapType(0x54, 2);
            if (p) {
                p = (Obj54*)fn_27_2454E0(p);
            }
            self->g[i] = p;
            if (p) {
                p->stage = self->p[i];
            }
        }
    }

    fn_27_1F1844(0);
    CameraController::getInstance()->changeInput((CameraController::Kind)2);
    self->h = fn_27_27CBE0();

    Link44* a = (Link44*)__nw__FUlQ25Heaps8HeapType(0x1b8, 2);
    if (a) {
        a = (Link44*)fn_27_244240(a);
    }
    self->a = a;

    Link48* b = (Link48*)__nw__FUlQ25Heaps8HeapType(0x104, 2);
    if (b) {
        b = (Link48*)fn_27_246E74(b, 0);
    }
    self->b = b;

    self->d = makeD();

    Link54* c = (Link54*)__nw__FUlQ25Heaps8HeapType(0x200, 2);
    if (c) {
        c = (Link54*)fn_27_24FCC4(c);
    }
    self->c = c;

    if (self->f) {
        Link68* dest = self->f;
        dest->p[0] = self->p[0];
        dest->p[1] = self->p[1];
        dest->p[2] = self->p[2];
        dest->p[3] = self->p[3];
        dest->p[4] = self->p[4];
        dest->p[5] = self->p[5];
        dest->p[6] = self->p[6];
    }

    if (self->a) {
        self->a->other = self->b;
    }
    if (self->a) {
        Link44* dest = self->a;
        dest->p[0] = self->p[0];
        dest->p[1] = self->p[1];
        dest->p[2] = self->p[2];
        dest->p[3] = self->p[3];
        dest->p[4] = self->p[4];
        dest->p[5] = self->p[5];
        dest->p[6] = self->p[6];
    }

    if (self->b) {
        Link48* dest = self->b;
        dest->p[0] = self->p[0];
        dest->p[1] = self->p[1];
        dest->p[2] = self->p[2];
        dest->p[3] = self->p[3];
        dest->p[4] = self->p[4];
        dest->p[5] = self->p[5];
        dest->p[6] = self->p[6];
    }

    if (self->h) {
        self->h->b = self->c;
    }
    if (self->h) {
        self->h->a = self->f;
    }
    if (self->h) {
        LinkB0* dest = self->h;
        dest->p[0] = self->g[0];
        dest->p[1] = self->g[1];
        dest->p[2] = self->g[2];
        dest->p[3] = self->g[3];
        dest->p[4] = self->g[4];
        dest->p[5] = self->g[5];
        dest->p[6] = self->g[6];
    }

    Link54* last = self->c;
    last->a = self->p[0];
    last->b = self->p[7];
    last->c = self->q;
    self->flags &= ~6;
}
