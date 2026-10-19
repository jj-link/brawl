#pragma force_active on
extern "C" void* fn_63_B23C(void* obj, int index) {
    int s = *(int*)((char*)obj + 8) >> 28;
    int r = s + index;
    if (r < 6) {
    } else {
        r = r - 6;
    }
    return (char*)obj + r * 8 + 12;
}
