#pragma force_active on
typedef struct SoFlags
{
    int unk0;
    int unk4;
    unsigned int flags;
} SoFlags;

extern "C" {
void fn_27_19C520(SoFlags *p)
{
    p->flags &= ~0x80000u;
}
}
