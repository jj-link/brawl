#pragma force_active on
extern "C" void* fn_72_51E0(void* object, int index) {
    int adjustment = *(int*)((char*)object + 8) >> 30;
    int adjusted = adjustment + index;

    if (adjusted >= 1) {
        adjusted -= 1;
    }

    return (char*)object + adjusted * 0x78 + 0x0C;
}
