#pragma force_active on
extern "C" void* fn_27_295F94(char* self, int idx) {
    int t = *(int*)(self + 8);
    int r = (t >> 29) + idx;
    if (r >= 2) {
        r = r - 2;
    }
    return self + r * 12 + 12;
}
