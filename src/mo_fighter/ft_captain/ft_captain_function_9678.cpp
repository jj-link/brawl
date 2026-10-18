#pragma force_active on
extern "C" void *fn_100_9678(void *base, int index) {
    return static_cast<char *>(base) + index * 8 + 4;
}
