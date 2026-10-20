#pragma force_active on
extern "C" void* fn_27_1D45C(void* p, int i) {
    int n = *(int*)((char*)p + 8) >> 30;
    int index = n + i;
    if (index < 1)
        index = index;
    else
        index -= 1;
    return (char*)p + index * 12 + 12;
}
