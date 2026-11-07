#pragma force_active on
#pragma optimization_level 1
extern "C" int fn_27_1DAF80(void*, unsigned int);

extern "C" int fn_116_23A40(void* object, unsigned int flags) {
    if (flags & 6)
        return 0;
    return fn_27_1DAF80(object, flags);
}