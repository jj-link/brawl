#pragma force_active on
struct S {
    int pad[2];
    int top : 6;
    int mid : 6;
    int low : 20;
};

extern "C" {
int fn_48_B9F8(struct S *p)
{
    return p->mid;
}
}
