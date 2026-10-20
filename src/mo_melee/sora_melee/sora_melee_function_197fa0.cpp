#pragma force_active on
extern "C" unsigned int fn_27_197FA0(void* obj) {
    unsigned int val = *(unsigned int*)((unsigned char*)obj + 0x8);
    return (val >> 25) & 1;
}
