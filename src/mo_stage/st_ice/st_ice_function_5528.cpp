#pragma force_active on
extern "C" float fn_62_5528(const void* self, unsigned int index) {
    float* arr = *(float**)((char*)self + 0x5ac);
    return arr[index];
}
