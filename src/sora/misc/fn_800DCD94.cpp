#pragma force_active on
extern "C" {
unsigned int fn_800DCD94(void* p) {
    int* obj = *(int**)((char*)p + 0x74);
    unsigned int x = *(int*)((char*)obj + 0x110);
    unsigned int r = (1 - x) | (x - 1);
    return r >> 31;
}
}
