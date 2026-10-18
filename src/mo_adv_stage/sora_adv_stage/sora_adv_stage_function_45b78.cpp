#pragma force_active on
extern "C" {
void fn_800C2BB4(void *a, void *b);

struct Obj {
    char pad[0x108];
    void *f108;
};

void fn_40_45B78(void *a, Obj *b)
{
    void *x;
    *(void **)a = 0;
    x = b->f108;
    b->f108 = 0;
    fn_800C2BB4(a, x);
}
}
