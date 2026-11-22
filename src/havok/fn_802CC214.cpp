#pragma force_active on
struct Src { int f[11]; signed char a; signed char b; };
struct Entry { Src s; int c; };
struct Obj { char _0[0xe90]; int count; char q[0x1694 - 0xe94]; Entry e[1]; };
#define I(o,x) (*(int*)((char*)(o)+(x)))
extern "C" int __cntlzw(unsigned int);
extern "C" void fn_802CC4EC(Obj*, void*, int, int, int, int, int, int, int);
static inline void append(Obj* o, Entry& e, int a, int b, int c, int d) {
    Entry* entry = &o->e[o->count];
    entry->s = e.s;
    entry->c = e.c;
    fn_802CC4EC(o, (char*)o + 0xe94, o->count, a, b, a, b, I(o,0x1c2c), 0);
    if (e.s.a) fn_802CC4EC(o, (char*)o + 0x1294, o->count, c, d, c, d, I(o,0x1c30), 0);
    o->count++;
}
extern "C" void fn_802CC214(Obj* o, Src* src, int a, int b) {
    Entry e;
    int flag;
    e.s.f[6] = 0; flag = 0; e.s.f[7] = 0; e.s.f[8] = 0; e.s.f[9] = 0;
    e.s.a = 0;
    I(o,0x1c10) = 0x80; I(o,0x1c0c) = 0x200; *((char*)o + 0x1c09) = 1;
    e.s.b = 0;
    e.s = *src;
    e.c = 0;
    if (a != b && (signed char)((unsigned int)__cntlzw(e.s.b) >> 5)) flag = 1;
    if (flag) {
        e.c = 2;
        append(o, e, b, a, a, b);
        e.c = 1;
    }
    append(o, e, a, b, a, b);
}