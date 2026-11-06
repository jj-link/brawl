#pragma force_active on

extern "C" int fn_27_1DAF80(void*, unsigned int);

extern "C" int fn_121_13F90(void* object, unsigned int flags) {
    if (flags & 6) {
        return 0;
    }
    return fn_27_1DAF80(object, flags);
}