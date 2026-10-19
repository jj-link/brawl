#pragma force_active on
struct Fn62Owner {
    int pad[2];
    int count;
};

extern "C" {
void* fn_62_F048(Fn62Owner* self, int index) {
    int n = (self->count >> 30) + index;
    if (n >= 1) {
        n -= 1;
    }
    return (char*)self + n * 0x90 + 0xc;
}
}
