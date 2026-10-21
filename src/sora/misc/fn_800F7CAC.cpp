#pragma force_active on
extern "C" int fn_800F7CAC(void* self)
{
    int ret = 0;
    int v = ((int*)self)[0x88 / 4];
    if (v != 0 && v != 8) {
        ret = 1;
    }
    return ret;
}
