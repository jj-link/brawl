#pragma force_active on
extern void fn_801EC184(unsigned int, unsigned int);
extern void fn_801EC514(unsigned int, unsigned int);

void fn_803D05C4(unsigned long long args)
{
    fn_801EC184((unsigned int)args, (unsigned int)(args >> 32));
    fn_801EC514((unsigned int)args, (unsigned int)(args >> 32) + 0x30);
}
