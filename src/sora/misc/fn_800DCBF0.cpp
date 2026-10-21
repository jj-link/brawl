#pragma force_active on
extern "C" int fn_800DCBF0(void* self) {
    void* ptr = *(void**)((char*)self + 0xB0);
    if (ptr == 0) return 0;
    if (*(int*)((char*)ptr + 0x104) != 3) return 1;
    int ret = 3;
    if (*(unsigned char*)((char*)ptr + 0x100)) ret = 2;
    return ret;
}
