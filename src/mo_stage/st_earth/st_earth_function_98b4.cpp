#pragma force_active on
struct FnObj98B4 {
    int pad0;
    int pad1;
    unsigned int field;
};

extern "C" int fn_66_98B4(FnObj98B4 *p)
{
    unsigned int x = p->field;
    return ((int)(((x << 2) | (x >> 30)) & 0xE0000000u)) >> 30;
}
