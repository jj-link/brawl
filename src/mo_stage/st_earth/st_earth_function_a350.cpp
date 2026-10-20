#pragma force_active on
struct fn_66_A350_obj {
    int pad[2];
    unsigned int flags;
};

extern "C" {
int fn_66_A350(fn_66_A350_obj *p)
{
    return (int)((p->flags << 2) & 0xE0000000) >> 30;
}
}
