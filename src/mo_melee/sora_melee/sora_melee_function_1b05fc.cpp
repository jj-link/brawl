#pragma force_active on
extern "C" void* fn_27_1B05FC(void* p, int i) {
    int n = *(int*)((char*)p + 8) >> 30;
    int index = n + i;
    if (index >= 1)
        index = index - 1;
    return (char*)p + index * 0x34 + 0xC;
}
