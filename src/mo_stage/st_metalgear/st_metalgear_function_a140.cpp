#pragma force_active on
struct Ent {
    char pad[8];
    int flags;
};

extern "C" char* fn_71_A140(Ent* self, int index) {
    int shifted = self->flags >> 30;
    int idx = shifted + index;
    if (idx >= 1) {
        idx -= 1;
    }
    return (char*)self + idx * 0x68 + 0xc;
}
