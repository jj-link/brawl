#pragma force_active on
extern "C" int fn_27_1DAF80(void*, unsigned int);

#pragma optimize_for_size on
extern "C" int fn_27_3B0CB0(void* self, unsigned int flags)
{
    int result;
    if (flags & 6) {
        result = 0;
    } else {
        result = fn_27_1DAF80(self, flags);
    }
    return result;
}
