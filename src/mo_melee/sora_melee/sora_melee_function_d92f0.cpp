#pragma force_active on
struct FnEntry {
    char pad[0x8];
    int flags;
};

extern "C" {
void* fn_27_D92F0(FnEntry* self, int idx)
{
    int sum = (self->flags >> 25) + idx;
    if (sum >= 0x27) {
        sum -= 0x27;
    }
    return (char*)self + sum * 0x30 + 0xc;
}
}
