#pragma force_active on
#pragma peephole on

extern "C" int fn_27_1DAF80(void*, unsigned int);

inline bool koopa_flags_block_call(unsigned int flags) {
    return (flags & 6) != 0;
}

extern "C" int fn_102_1BC78(void* object, unsigned int flags) {
    int result;
    if (koopa_flags_block_call(flags)) {
        result = 0;
    } else {
        result = fn_27_1DAF80(object, flags);
    }
    return result;
}
