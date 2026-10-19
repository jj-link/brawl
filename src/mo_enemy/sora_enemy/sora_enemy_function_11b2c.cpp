#pragma force_active on
typedef unsigned int u32;

struct V3 { float data[3]; };

extern "C" void fn_41_11B2C(V3* dst, const void* src) {
    *dst = *(const V3*)((const char*)src + 0xD0);
}
