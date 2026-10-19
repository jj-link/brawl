#pragma force_active on
extern "C" void fn_90_836C(char* p, unsigned char v, int w, float f) {
    *(unsigned char*)(p + 0x184) = v;
    *(int*)(p + 0x188) = w;
    *(float*)(p + 0x18c) = f;
}
