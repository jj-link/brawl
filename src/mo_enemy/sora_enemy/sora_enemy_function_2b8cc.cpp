#pragma force_active on
typedef unsigned char u8;

struct Flags {
    u8 pad[0x50];
    u8 f : 1;
};

extern "C" {
void fn_41_2B8CC(void* p, unsigned int v) {
    Flags* s = (Flags*)p;
    s->f = v;
}
}
