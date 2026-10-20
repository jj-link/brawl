#pragma force_active on
typedef struct St_A4D4
{
    unsigned int pad[2];
    unsigned int flags;
} St_A4D4;

extern "C" void fn_66_A4D4(St_A4D4 *p)
{
    p->flags &= ~0x02000000u;
}
