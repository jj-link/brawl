#pragma force_active on
struct St {
    int pad[2];
    unsigned int v;
};

extern "C" {
int fn_54_69D8(struct St *p)
{
    return (int)((p->v << 8) & 0xF8000000u) >> 28;
}
}
