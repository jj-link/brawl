#pragma force_active on
extern "C" int fn_14_4D6C(void* object) {
    if (*(int*)((char*)object + 0x2B0) != 0xD)
        return 2;
    return *(int*)((char*)object + 0x24C4);
}
