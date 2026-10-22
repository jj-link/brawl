#pragma force_active on
extern "C" {
struct Obj { int p0; int p1; void** vt; int c; int d; };
struct A { int x[0x24]; };
struct B { int x[0xa1]; };
struct G8 { unsigned char a,b,c; char z; int w4; A m; B n; };
struct Glob { int a; int b; G8* c8; char pad[0x34]; void* d40; };
struct Sw { char pad[0x18]; int u18; char pad2[0x8]; unsigned char f24; };
struct Owner { char pad[0x1ac]; struct Ow2* o; };
struct Ow2 { char pad[0x1cf0]; int v; char pad2[0x1c]; int w; };
extern Glob* g_GameGlobal;
void fn_80153488(void*);
void fn_80153498(void*, int);
void fn_80153504(void*, int);
Obj* fn_80153818(void*, int);
Sw* getInstance__8ipSwitchFv();
void fn_8004B278(int, int, int);
G8* fn_8004B0EC(int);
void* fn_8004B1D0(int);
void* memcpy(void*, const void*, unsigned long);
struct Dtor { int p0; int p1; virtual void d(int); };

void fn_7_AC0(Owner* self) {
    char buf[0x10];
    int v = self->o->v;
    fn_80153488(buf);
    fn_80153504(buf, v);
    Obj* o = fn_80153818(buf, 0x2b);
    if (o) {
        int c = o->c + 0x34;
        int d = o->d;
        Sw* sw = getInstance__8ipSwitchFv();
        int h = sw->u18;
        fn_8004B278(h, c, d);
        G8* dst = g_GameGlobal->c8;
        G8* src = fn_8004B0EC(h);
        dst->a = src->a; dst->b = src->b; dst->c = src->c;
        dst->m = src->m;
        dst->n = src->n;
        if (fn_8004B1D0(h)) {
            void* t = g_GameGlobal->d40;
            memcpy(t, fn_8004B1D0(h), 0x470);
        }
        sw->f24 |= 0x80;
        *(int*)((char*)self->o + 0x1d10) = 0;
    } else {
        *(int*)((char*)self->o + 0x1d10) = 1;
    }
    if (o) ((Dtor*)o)->d(1);
    fn_80153498(buf, -1);
}
}
