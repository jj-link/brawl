extern "C" int fn_27_1DAF80(int, unsigned int);

#pragma force_active on
#pragma dont_inline on
extern "C" int fn_27_330A34(int object, unsigned int flags) {
    if (!(flags & 6)) {
        return fn_27_1DAF80(object, flags);
    }
    return 0;
}
#pragma dont_inline reset
