#pragma force_active on
extern "C" char* fn_8004DA14(void* p, int index, int value) {
    if (value == 0x78) {
        if (index < 4) {
            return *(char**)((char*)p + 4) + index * 2;
        }
        return 0;
    }
    return *(char**)((char*)p + 0x28) + value * 0x124 + 0xEE;
}
