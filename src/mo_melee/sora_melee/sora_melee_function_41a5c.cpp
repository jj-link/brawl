#pragma force_active on
extern "C" unsigned int fn_27_41A5C(void* obj) {
    unsigned int val = *(unsigned int*)((char*)obj + 8);
    return (val >> 19) & 1;
}
