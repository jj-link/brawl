#pragma force_active on
extern "C" float fn_80179564(void* self) {
    char* p = static_cast<char*>(self);
    float t = *(float*)(p + 0x30) * *(float*)(p + 0x38);
    float* q = *(float**)(p + 0xc8);
    return t * q[22];
}
