#pragma force_active on
extern "C" void* fn_27_F20D0(void* p, int index) {
    int offset = *(int*)((char*)p + 0x18) >> 30;
    int adjusted = offset + index;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char*)p + adjusted * 12 + 0x1C;
}
