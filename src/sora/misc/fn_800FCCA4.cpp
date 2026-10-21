extern "C" void fn_800FD96C(int a, int b);

#pragma force_active on
extern "C" void fn_800FCCA4(int base, unsigned int idx)
{
    fn_800FD96C(*(int*)(base + (idx << 2) + 0x1c), 1);
}
