#pragma force_active on
extern "C" int fn_27_1DAF80(void*, unsigned int);

extern "C" int fn_114_18D78(void* object, unsigned int flags) {
    int result;
    if (flags & 2) {
        result = 0;
    } else {
        result = fn_27_1DAF80(object, flags);
    }
    return result;
}