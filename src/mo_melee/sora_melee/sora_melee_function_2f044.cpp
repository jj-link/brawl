#pragma force_active on
typedef unsigned int u32;

extern "C" {
void fn_27_2F044(char* self, float* v) {
    u32 flags = *(u32*)(self + 0x38);
    float y;
    float x = v[0];
    y = v[1];
    *(float*)(self + 0x8) = x;
    *(float*)(self + 0xc) = y;
    *(u32*)(self + 0x38) = flags & ~0x8u;
}
}
