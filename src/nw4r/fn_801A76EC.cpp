#pragma force_active on
extern "C" void fn_801A76EC(void** self, const float* src) {
    char* obj = (char*)*self;
    if (obj == 0) {
        return;
    }
    *(float*)(obj + 0x74) = src[0];
    float y = src[1];
    *(float*)(obj + 0x78) = y;
    *(float*)(obj + 0x7c) = src[2];
    *(unsigned int*)(obj + 0x70) &= 0xFFFFFFF7;
}
