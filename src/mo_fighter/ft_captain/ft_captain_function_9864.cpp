#pragma force_active on
extern "C" int fn_100_9864(void* this_ptr, int mask, int index) {
    int* array = *(int**)((char*)this_ptr + 0x1C);
    return (array[index] & mask) != 0;
}
