#pragma force_active on
extern "C" float fn_50_5B64(void* obj, unsigned int index) {
    float* floats = *(float**)((char*)obj + 0x520);
    return floats[index];
}
