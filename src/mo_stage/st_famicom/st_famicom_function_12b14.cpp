#pragma force_active on
extern "C" float fn_68_12B14(void* self, unsigned int index) {
    float* arr = *(float**)((char*)self + 0x520);
    return arr[index];
}
