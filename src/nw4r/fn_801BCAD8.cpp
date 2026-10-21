#pragma force_active on
extern "C" void fn_801BCAD8(void* obj, int value) {
    *(int*)((char*)obj + 0x6C) = value;
    *(unsigned char*)((char*)obj + 0x66) = ((unsigned)((-value) & ~value)) >> 31;
}
