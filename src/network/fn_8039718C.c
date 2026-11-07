#pragma force_active on
typedef int (*Callback)(void *, int, int *);

typedef struct A {
    char pad[0x14];
    int f14;
} A;

typedef struct B {
    int pad[7];
    Callback fn;
    int pad2;
    int f24;
    int f28;
} B;

extern void *fn_80396EEC(void *a, void *b, int c);

int fn_8039718C(void *arg0, B *arg1, int arg2, int arg3) {
    int args[4];
    int a;
    int b;
    int result = -1;
    B *out;
    A *p;
    int v;

    if (fn_80396EEC(arg0, arg1, 0) != 0) {
        p = fn_80396EEC(arg0, arg1, 0);
        if (p != 0) {
            v = p->f14;
        } else {
            v = 0;
        }
        if (v != 0 && arg1->fn != 0) {
            args[0] = arg2;
            args[1] = arg1->f24;
            args[2] = arg1->f28;
            args[3] = arg3;
            result = arg1->fn(arg1, 1, args);
            b = args[2];
            a = args[1];
            out = fn_80396EEC(arg0, arg1, 0);
            if (out != 0) {
                out->f24 = a;
                out->f28 = b;
            }
        }
    }
    return result;
}
