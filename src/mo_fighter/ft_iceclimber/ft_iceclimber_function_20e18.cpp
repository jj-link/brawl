#pragma force_active on
#pragma dont_inline on

extern "C" int fn_27_1DAF80(void*, unsigned int);

extern "C" int fn_105_20E18(void* self, unsigned int flags) {
    int result;
    if (flags & 6) {
        result = 0;
    } else {
        result = fn_27_1DAF80(self, flags);
    }
    return result;
}