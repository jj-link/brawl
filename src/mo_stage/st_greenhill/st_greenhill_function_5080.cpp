#pragma force_active on
extern "C" void* fn_72_5080(void* self, int index) {
    int flag = ((int*)self)[2];
    int idx = (flag >> 30) + index;
    if (idx >= 1) {
        idx -= 1;
    }
    return (char*)self + 0xC + idx * 0x38;
}
