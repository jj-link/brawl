#pragma force_active on
typedef struct StObj {
    unsigned int w0;
    unsigned int w1;
    unsigned int flags;
} StObj;

extern "C" void fn_66_A640(StObj *p)
{
    p->flags |= 0x00080000;
}
