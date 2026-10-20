#pragma force_active on
typedef struct {
    int pad[2];
    unsigned int w;
} FnObj;

extern "C" int fn_51_D798(FnObj *p)
{
    return (int)((p->w << 3) & 0xF0000000u) >> 29;
}
