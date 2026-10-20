#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int flags;
} S;

extern "C" {
int fn_72_5268(S *p)
{
    return (int)((p->flags << 4) & 0xE0000000) >> 30;
}
}
