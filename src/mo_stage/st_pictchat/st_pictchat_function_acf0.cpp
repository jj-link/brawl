#pragma force_active on
struct FnSrc73 {
    int pad[2];
    unsigned int flags;
};

extern "C" {
int fn_73_ACF0(FnSrc73 *p)
{
    unsigned int x = p->flags;
    return ((int)(((x << 8) | (x >> 24)) & 0xF8000000u)) >> 28;
}
}
