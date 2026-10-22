#pragma force_active on
extern void OSReport(const char* fmt, ...);
extern char lbl_804914D0[];
extern char lbl_80491500[];

typedef struct Vt { int a; int (*f)(void*, int, int); } Vt;
typedef struct Obj { char pad[0x104]; Vt* vt; } Obj;

int fn_8038FE28(Obj* o, int a, int b, int n) {
    int r;
    int (*f)(void*, int, int) = o->vt->f;
    r = 0;
    if (f == 0) {
        OSReport(lbl_80491500);
    } else if (n & 0xF) {
        OSReport(lbl_804914D0);
    } else {
        while (n != 0) {
            f(o, a, b);
            b += 0x10;
            a += 0x10;
            n -= 0x10;
        }
        r = 1;
    }
    return r;
}
