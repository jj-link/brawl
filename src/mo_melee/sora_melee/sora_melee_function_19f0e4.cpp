#pragma force_active on
typedef unsigned int u32;
typedef int s32;

struct Data {
    unsigned char pad[8];
    u32 value;
};

extern "C" s32 fn_27_19F0E4(const Data* self) {
    return (s32)((self->value << 6) & 0xF0000000u) >> 29;
}
