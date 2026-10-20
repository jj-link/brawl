#pragma force_active on
extern "C" void fn_61_A7D8(void* p) {
    unsigned int value = *(unsigned int*)((char*)p + 8);
    value |= 0x00080000u;
    *(unsigned int*)((char*)p + 8) = value;
}
