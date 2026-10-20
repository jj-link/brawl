#pragma force_active on
typedef struct {
    unsigned int a : 8;
    unsigned int b : 4;
    unsigned int c : 20;
} Bits;

extern "C" void fn_73_AD28(void *obj, unsigned int val)
{
    Bits *p = (Bits *)((char *)obj + 8);
    p->b = val;
}
