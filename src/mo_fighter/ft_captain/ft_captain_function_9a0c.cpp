#pragma force_active on
extern "C" void *fn_100_9A0C(void *object, int index) {
    void **list = *reinterpret_cast<void ***>(static_cast<char *>(object) + 0xC);
    return list[index];
}
