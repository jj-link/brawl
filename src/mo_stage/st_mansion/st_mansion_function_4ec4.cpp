#pragma force_active on
extern "C" void* fn_47_4EC4(void* object, int index) {
    int state = ((int*)object)[2] >> 30;
    int adjusted = state + index;
    if (adjusted >= 1) {
        adjusted--;
    }
    return (char*)object + adjusted * 0x90 + 0x0C;
}
