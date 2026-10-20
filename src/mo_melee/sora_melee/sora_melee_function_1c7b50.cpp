#pragma force_active on
extern "C" void* fn_27_1C7B50(void* self, int idx)
{
    char* p = (char*)self;
    int v = *(int*)(p + 0x18);
    int r = (v >> 25) + idx;
    if (r >= 0x21) {
        r -= 0x21;
    }
    return p + 0x1c + r * 12;
}
