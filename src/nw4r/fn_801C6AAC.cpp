#pragma force_active on

extern "C" int fn_801C0A68(int arg0, int arg1);

extern "C" int fn_801C6AAC(int arg0, int arg1) {
    if (!arg1)
        return arg0;
    return fn_801C0A68(arg0 + 8, arg1);
}
