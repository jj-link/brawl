#pragma force_active on
struct St {
    int pad[2];
    unsigned int v;
};

extern "C" {
int fn_61_E788(struct St *s)
{
    int r = (int)((s->v << 6) & 0xF0000000);
    return r >> 29;
}
}
