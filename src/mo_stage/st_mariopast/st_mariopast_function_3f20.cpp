#pragma force_active on
extern "C" {
void* fn_48_3F20(void* self, int idx) {
    char* p = (char*)self;
    int n = *(int*)(p + 8) >> 28;
    int i = n + idx;
    if (i >= 6) {
        i -= 6;
    }
    return p + (i << 3) + 12;
}
}
