#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

struct Entity {
    char pad[0x3F9];
    u8 flags[3];
    char pad2[1];
    u32 unk400;
    u32 unk404;
};

extern "C" {
void fn_50_1A38(Entity* self) {
    u32 lim = 0xF423F;
    u8 five = 5;
    for (int i = 0; i < 3; i++) {
        if (self->flags[i] == 4) {
            self->flags[i] = five;
            self->unk400 += 0x320;
            if (self->unk400 > lim) {
                self->unk400 = lim;
            }
            u32 cur = self->unk400;
            if (self->unk404 < cur) {
                self->unk404 = cur;
            }
        }
    }
}
}
