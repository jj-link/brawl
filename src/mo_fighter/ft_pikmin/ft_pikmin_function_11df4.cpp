#pragma force_active on
struct PikminThing {
    int pad[2];
    int flags;
};

extern "C" int fn_113_11DF4(PikminThing *p)
{
    return p->flags >> 30;
}
