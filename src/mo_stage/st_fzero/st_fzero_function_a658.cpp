#pragma force_active on
struct St_fzero_flags {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int c : 28;
};

struct St_fzero {
    int pad[2];
    struct St_fzero_flags flags;
};

extern "C" void fn_61_A658(struct St_fzero *p, unsigned int v)
{
    p->flags.b = v;
}
