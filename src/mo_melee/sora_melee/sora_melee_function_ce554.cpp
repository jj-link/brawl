#pragma force_active on
extern "C" unsigned int fn_27_CE554(void *obj)
{
    union {
        unsigned int v;
        struct {
            unsigned int x : 15;
            unsigned int y : 1;
            unsigned int z : 16;
        } f;
    } u;
    u.v = *(unsigned int *)((char *)obj + 8);
    return u.f.y;
}
