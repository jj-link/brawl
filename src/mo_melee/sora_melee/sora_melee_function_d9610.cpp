#pragma force_active on
struct Entry { unsigned char pad[12]; };

extern "C" Entry* fn_27_D9610(Entry* base, int index) {
    int encoded = *(int*)((char*)base + 8);
    int value = (encoded >> 23) + index;
    if (value >= 0x92)
        value -= 0x92;
    return (Entry*)((char*)base + value * 0x30 + 12);
}
