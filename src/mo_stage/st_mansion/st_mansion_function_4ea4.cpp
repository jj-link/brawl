#pragma force_active on
struct St_47_4EA4 {
    int pad[2];
    unsigned int flags;
};

extern "C" void fn_47_4EA4(St_47_4EA4 *p)
{
    p->flags &= 0xFDFFFFFFu;
}
