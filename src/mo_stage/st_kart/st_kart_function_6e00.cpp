#pragma force_active on
extern "C" void* fn_49_6E00(void* object, int index) {
    int adjusted = (*(int*)((char*)object + 8) >> 30) + index;
    if (adjusted >= 1) {
        adjusted -= 1;
    }
    return (char*)object + adjusted * 0x78 + 0xC;
}
