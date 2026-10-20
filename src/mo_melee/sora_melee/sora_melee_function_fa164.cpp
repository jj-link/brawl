#pragma force_active on
extern "C" int* fn_27_FA164(int* p, int i) {
    int n = p[6] >> 30;
    int sum = n + i;
    if (sum >= 1)
        sum--;
    return (int*)((char*)p + sum * 12 + 28);
}
