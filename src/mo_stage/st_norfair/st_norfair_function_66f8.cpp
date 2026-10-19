#pragma force_active on
extern "C" void* fn_54_66F8(void* self, int index) {
    int flags = *(int*)((char*)self + 8);
    int adjustment = flags >> 29;
    int result;
    if (adjustment < 0)
        result = adjustment + index;
    else
        result = index + adjustment;

    if (result >= 2)
        result -= 2;

    return (char*)self + result * 0x68 + 0x0C;
}
