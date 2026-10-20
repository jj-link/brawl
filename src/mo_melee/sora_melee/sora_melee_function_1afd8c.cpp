#pragma force_active on
extern "C" void* fn_27_1AFD8C(char* self, int i)
{
    int idx = (*(int*)(self + 8) >> 22) + i;
    if (idx >= 0x124) {
        idx -= 0x124;
    }
    return self + idx * 4 + 0xc;
}
