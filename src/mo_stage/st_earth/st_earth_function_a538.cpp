#pragma force_active on
struct FnState {
    int pad[2];
    unsigned int f : 2;
};

extern "C" void fn_66_A538(struct FnState *s, unsigned int v)
{
    s->f = v;
}
