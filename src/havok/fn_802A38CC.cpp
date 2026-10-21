#pragma force_active on
extern "C" int fn_802A3290(int, int, int);

extern "C" int fn_802A38CC(int arg1, int arg2, int arg3) {
    return fn_802A3290(arg1, arg3, arg2);
}