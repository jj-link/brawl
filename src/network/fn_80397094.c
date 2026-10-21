#pragma force_active on
typedef int s32;

struct Foo {
    char pad[0x14];
    s32 field;
};

s32 fn_80396EEC(s32 a, s32 b, s32 c);

s32 fn_80397094(s32 a, s32 b) {
    void *p = (void *)fn_80396EEC(a, b, 0);
    if (p)
        return ((struct Foo *)p)->field;
    return 0;
}
