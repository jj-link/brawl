#pragma force_active on
extern "C" int fn_40_42D98(void *self)
{
    int step = *(int *)((char *)self + 0xC18) + 1;
    *(int *)((char *)self + 0xC18) = step;
    if (step >= 2) {
        *(int *)((char *)self + 0xC24) = 2;
        return 4;
    }
    return *(int *)((char *)self + 0x968);
}
