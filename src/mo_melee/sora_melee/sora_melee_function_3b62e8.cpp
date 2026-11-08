#pragma force_active on
#pragma optimization_level 4

extern "C" {
int fn_27_1DAF80(void*, unsigned int) __attribute__((noreturn));

int fn_27_3B62E8(void* object, unsigned int flags) {
    if (flags & 6) {
        return 0;
    }
    fn_27_1DAF80(object, flags);
}
}
