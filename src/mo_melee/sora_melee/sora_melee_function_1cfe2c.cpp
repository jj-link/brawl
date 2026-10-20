#pragma force_active on
typedef unsigned char u8;

namespace {
struct Elem12 {
    u8 pad[12];
};
}

extern "C" void* fn_27_1CFE2C(u8* base, int index)
{
    return base + index * 12 + 12;
}
