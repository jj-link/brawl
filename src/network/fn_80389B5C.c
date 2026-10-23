#pragma force_active on
typedef struct Context {
    char pad[0x6A0];
    int order;
} Context;

extern Context *lbl_805A1134;

int fn_80388794(void *, void *, int);
int fn_803899CC(void *, void *);

int fn_80389B5C(const void *arg0, const void *arg1)
{
    void *a = *(void *const *)arg0;
    void *b = *(void *const *)arg1;
    void *p = (char *)lbl_805A1134 + 0x498;
    int diff = fn_80388794(a, p, 0);

    diff -= fn_80388794(b, p, 0);
    if (diff == 0)
        return fn_803899CC(a, b);

    if (lbl_805A1134->order == 0)
        diff = -diff;

    return diff;
}
