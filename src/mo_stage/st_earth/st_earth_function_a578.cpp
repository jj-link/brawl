#pragma force_active on
typedef struct {
    unsigned int pad[2];
    unsigned int flags;
} Obj66;

extern "C" {
void fn_66_A578(Obj66 *p)
{
    p->flags |= 0x02000000;
}
}
