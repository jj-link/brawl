#pragma force_active on
extern "C" int fn_27_D19B4(void* ptr) {
    int val = *(int*)((char*)ptr + 8);
    return (val >> 16) & 1;
}