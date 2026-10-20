#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} S;

extern "C" int fn_48_B60C(S *p)
{
    int v = (int)(((p->flags << 18) | (p->flags >> 14)) & 0xFFC00000u);
    return v >> 23;
}
