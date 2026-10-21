#pragma force_active on
extern "C" int fn_801C2EF0(int* a) {
    int b = a[1];
    return *(int*)(b + 8) + b;
}
