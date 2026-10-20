#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} S;

extern "C" {
int fn_48_BB88(S *p)
{
    int v = (int)(((p->w >> 19) & 0x7F) << 25);
    return v >> 26;
}
}
