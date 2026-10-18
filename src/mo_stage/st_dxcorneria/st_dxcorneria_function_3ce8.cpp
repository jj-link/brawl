#pragma force_active on
struct Obj {
    char pad[0x1048];
    unsigned char flag;
};

extern "C" {
unsigned int fn_82_3CE8(Obj *p)
{
    unsigned int x = p->flag;
    unsigned int r = (1 - x) | (x - 1);
    return r >> 31;
}
}
