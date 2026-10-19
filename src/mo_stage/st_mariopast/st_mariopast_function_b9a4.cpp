#pragma force_active on
extern "C" void* fn_48_B9A4(void* ptr, int index) {
    int adjusted = (*(int*)((char*)ptr + 8) >> 25) + index;
    if (adjusted < 0x3A) {
    } else {
        adjusted -= 0x3A;
    }
    return (char*)ptr + adjusted * 0x68 + 0xC;
}
