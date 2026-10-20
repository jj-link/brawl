#pragma force_active on
extern "C" int* fn_27_1BF100(void* self, int index) {
    int value = *reinterpret_cast<int*>(reinterpret_cast<char*>(self) + 0x18);
    int slot = (value >> 26) + index;
    if (slot < 0x11)
        goto done;
    slot -= 0x11;
done:
    return reinterpret_cast<int*>(reinterpret_cast<char*>(self) + slot * 0xC + 0x1C);
}
