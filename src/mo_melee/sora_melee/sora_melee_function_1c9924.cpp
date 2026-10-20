#pragma force_active on
extern "C" void* fn_27_1C9924(char* self, int idx)
{
    int v = *(int*)(self + 0x18) >> 28;
    int i = v + idx;
    if (i >= 4) {
        i -= 4;
    }
    return self + i * 12 + 0x1c;
}
