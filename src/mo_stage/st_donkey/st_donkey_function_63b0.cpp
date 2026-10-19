#pragma force_active on
extern "C" void* fn_50_63B0(void* self, int index) {
    int adjusted = (*(int*)((char*)self + 8) >> 30) + index;
    if (adjusted >= 1) {
        adjusted -= 1;
    }
    return (char*)self + adjusted * 0x90 + 0x0C;
}
