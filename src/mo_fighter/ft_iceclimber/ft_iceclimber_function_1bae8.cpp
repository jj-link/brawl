#pragma force_active on
#pragma dont_inline on
extern "C" {
int fn_27_1DAF80(void*);

int fn_105_1BAE8(void* arg0, unsigned int flags) {
    if (flags & 6) {
        return 0;
    }
    return fn_27_1DAF80(arg0);
}
}
#pragma dont_inline reset