#pragma force_active on
struct FnStruct {
    unsigned int w0;
    unsigned int w1;
    unsigned int flags;
};

extern "C" void fn_78_5784(FnStruct *p)
{
    p->flags |= 0x02000000;
}
