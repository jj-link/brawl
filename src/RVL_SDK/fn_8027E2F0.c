#pragma force_active on
int fn_8027E2F0(void* unused, int size) {
    if (size > 16) {
        size = (size + 15) & ~15;
        size += 16;
    } else {
        size += 8;
    }
    return size;
}
