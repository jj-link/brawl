#pragma force_active on
extern "C" int fn_40_24968(void* self) {
    int* ptr = (int*)((char*)self + 8);
    return (*ptr >> 25) & 1;
}
