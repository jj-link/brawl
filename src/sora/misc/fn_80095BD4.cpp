#pragma force_active on
extern "C" int fn_80095BD4(void* obj, unsigned int mask) {
    unsigned int x = (*(unsigned int*)((char*)obj + 0xEC)) & mask;
    return ((0u - x) | x) >> 31;
}
