#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} FnObj;

extern "C" {
int fn_51_679C(FnObj *p)
{
    unsigned int x = p->w;
    return ((int)(((x << 4) | (x >> 28)) & 0xF8000000u)) >> 28;
}
}
