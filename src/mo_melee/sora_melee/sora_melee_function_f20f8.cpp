#pragma force_active on
extern "C" int* fn_27_F20F8(void* p, int i) {
    int n = (*(int*)((char*)p + 0x18) >> 30) + i;
    if (n >= 1)
        n -= 1;
    return (int*)((char*)p + 0x1C + n * 12);
}
