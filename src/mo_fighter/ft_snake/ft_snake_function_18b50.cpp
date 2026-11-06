#pragma force_active on
#pragma function_align 4
extern "C" int fn_27_1DAF80(void*, unsigned int);

extern "C" int fn_122_18B50(void* object, unsigned int flags) {
    if (flags & 6) {
        return 0;
    }
    return fn_27_1DAF80(object, flags);
}
