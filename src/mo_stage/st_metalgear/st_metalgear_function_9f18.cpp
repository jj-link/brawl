#pragma force_active on
extern "C" void* fn_71_9F18(void* self, int index) {
    int adjustment = *(int*)((char*)self + 8) >> 30;
    int adjusted = adjustment + index;
    if (adjusted >= 1) {
        adjusted -= 1;
    }
    return (char*)self + adjusted * 0xA0 + 0xC;
}
