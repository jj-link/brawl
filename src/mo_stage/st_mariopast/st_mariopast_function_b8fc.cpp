#pragma force_active on
extern "C" {
typedef struct { int pad[2]; unsigned int w; } S;
int fn_48_B8FC(S *p)
{
    int v = (int)((p->w >> 10) << 24);
    return v >> 25;
}
}
