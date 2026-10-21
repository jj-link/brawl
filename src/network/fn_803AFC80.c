#pragma force_active on
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 flags;
    u16 pad2;
    u32 pad4;
    u32 current;
    u32 minimum;
    u32 maximum;
} State;

int fn_803AFC80(State *p)
{
    if (p->minimum == 0) {
        p->flags |= 2;
        p->maximum = p->minimum = p->current;
    } else if (p->current < p->minimum) {
        p->minimum = p->current;
    } else if (p->current > p->maximum) {
        p->maximum = p->current;
    }

    return 0;
}
