#pragma force_active on
extern "C" {
typedef struct {
    int pad[2];
    unsigned int flags;
} FnObj;

int fn_73_AB90(FnObj *p)
{
    return (int)((p->flags << 6) & 0xF0000000) >> 29;
}
}
