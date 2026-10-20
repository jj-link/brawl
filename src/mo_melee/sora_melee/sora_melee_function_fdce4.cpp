#pragma force_active on
extern "C" void* fn_27_FDCE4(void* p1, int p2) {
    int value = *(int*)((char*)p1 + 0x18);
    int adjusted = (value >> 30) + p2;
    if (adjusted >= 1)
        adjusted -= 1;
    return (char*)p1 + adjusted * 12 + 0x1c;
}
