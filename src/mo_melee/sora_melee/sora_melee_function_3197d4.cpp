#pragma force_active on
typedef int s32;

struct Hdr {
    char pad[0x18];
    s32 flags;
};

extern "C" {
void* fn_27_3197D4(Hdr* p, s32 idx) {
    s32 r = (p->flags >> 28) + idx;
    if (r >= 7) {
        r -= 7;
    }
    return (char*)p + (r << 4) + 0x1c;
}
}
