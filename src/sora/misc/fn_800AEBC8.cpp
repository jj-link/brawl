#pragma force_active on
extern "C" int fn_800AE5E0(void*, void*, void*, void*);
extern "C" int fn_800AE8E0(void*, void*, void*, void*);

extern "C" int fn_800AEBC8(void* arg0, void* arg1, void* arg2, void* arg3, void* arg4) {
    if (fn_800AE5E0(arg0, arg1, arg2, arg3) != 0) {
        return 1;
    }
    if (arg4 != 0 && fn_800AE5E0(arg2, arg3, arg0, arg1) != 0) {
        return 1;
    }
    if (fn_800AE8E0(arg0, arg1, arg2, arg3) != 0) {
        return 1;
    }
    return 0;
}
