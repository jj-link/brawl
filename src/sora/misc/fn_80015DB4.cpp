#pragma force_active on
extern "C" void* fn_80015E34(void*, int, int, int, int*, unsigned short);

extern "C" void* fn_80015DB4(void* arg0, int arg1, int arg2, int arg3, unsigned short arg4) {
    int sp8;
    return fn_80015E34(arg0, arg1, arg2, arg3, &sp8, arg4);
}
