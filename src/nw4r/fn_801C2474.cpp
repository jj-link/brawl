#pragma force_active on
extern "C" void fn_801C285C(int, int);
extern "C" void fn_801C2968(int, int);
extern "C" void fn_801C2A50(int, int);
extern "C" void fn_8021AEC4(int, int, void (*)(int, int));
struct Obj { char pad[4]; unsigned char a, b; char pad2[6]; int state, next, other; char pad3[0x20]; int id; };
extern "C" void fn_801C2474(Obj *p) {
    if (p->b) return;
    int n = p->next ? p->next : p->other;
    p->next = 0;
    p->other = 0;
    goto dispatch;
done:
    return;
dispatch:
    switch (n) {
    case 0: goto done;
    case 1:
        p->a = 1; p->b = 1; p->state = 1;
        fn_8021AEC4(p->id, 1, fn_801C285C);
        return;
    case 2:
        p->a = 1; p->b = 1; p->state = 3;
        fn_8021AEC4(p->id, 4, fn_801C2968);
        return;
    case 3:
        p->a = 1; p->b = 1; p->state = 5;
        fn_8021AEC4(p->id, 0, fn_801C2A50);
        return;
    }
}