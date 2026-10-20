#pragma force_active on
typedef struct {
    unsigned int a;
    unsigned int b;
    unsigned int c;
} FnObj;

extern "C" int fn_67_5290(FnObj *p)
{
    return (int)((p->c << 8 | p->c >> 24) & 0xF8000000) >> 28;
}
