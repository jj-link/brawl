#pragma force_active on
typedef struct
{
    int pad[2];
    unsigned int flags;
} FnState;

extern "C" int fn_78_586C(FnState *p)
{
    return (int)((p->flags << 8) & 0xF8000000u) >> 28;
}
