#pragma force_active on
struct Fn27_1A4F20
{
    unsigned char unk[8];
    unsigned int flags;
};

extern "C" void fn_27_1A4F20(Fn27_1A4F20* p)
{
    p->flags |= 0x02000000;
}
