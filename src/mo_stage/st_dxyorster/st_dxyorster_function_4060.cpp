#pragma force_active on
extern "C" {
void* fn_76_4060(int* self, int index) {
    int i = (self[2] >> 28) + index;
    if (i >= 6) {
        i -= 6;
    }
    return (char*)self + i * 8 + 12;
}
}
