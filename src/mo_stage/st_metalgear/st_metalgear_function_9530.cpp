#pragma force_active on
struct Obj {
    unsigned int pad[2];
    unsigned int flags;
};

extern "C" int fn_71_9530(struct Obj *p)
{
    unsigned int x = (p->flags << 2) & 0xE0000000;
    return (int)x >> 30;
}
