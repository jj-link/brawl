#pragma force_active on
typedef struct {
    int pad0;
    int pad1;
    unsigned int flags;
} FlagObj;

extern "C" void fn_62_F018(FlagObj *p)
{
    p->flags |= 0x02000000;
}
