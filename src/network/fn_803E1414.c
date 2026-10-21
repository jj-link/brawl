#pragma force_active on
extern void* fn_803E12B4(int, int, int, int, int);

void* fn_803E1414(int arg0, int arg1, int arg2, int arg3) {
    void* result = fn_803E12B4(arg0, arg1, arg2 != 0, 0, arg3);

    if (result != 0) {
        return result;
    }
    return 0;
}
