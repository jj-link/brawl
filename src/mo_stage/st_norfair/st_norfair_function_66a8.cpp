#pragma force_active on
typedef unsigned int u32;

typedef struct {
    u32 w0;
    u32 w1;
    struct {
        u32 hi : 3;
        u32 mid : 3;
        u32 lo : 26;
    } f;
} St;

extern "C" {
void fn_54_66A8(St *p, u32 v)
{
    p->f.mid = v;
}
}
