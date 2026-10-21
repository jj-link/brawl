#pragma force_active on
typedef unsigned int u32;

struct Range { u32 first, last; };

struct Entry {
    unsigned char pad[0xFC];
    u32 count;
    u32 ranges[0x40][2];
};

struct Menu {
    unsigned char pad0[0x67C];
    u32 current;
    unsigned char pad1[0xC];
    int index;
    unsigned char pad2[0x1C];
    Entry* entries;
};

extern "C" void fn_2_21578(Menu* self, int forward) {
    for (int i = 0; i < self->entries[self->index].count / 2; ++i) {
        if (self->entries[self->index].ranges[i][0] <= self->current &&
            self->entries[self->index].ranges[i][1] >= self->current) {
            if (forward) {
                if (self->current == self->entries[self->index].ranges[i][1]) {
                    if (i * 2 + 2 == self->entries[self->index].count)
                        self->current = self->entries[self->index].ranges[0][0];
                    else
                        self->current = self->entries[self->index].ranges[i][2];
                } else {
                    self->current++;
                }
            } else {
                if (self->current == self->entries[self->index].ranges[i][0]) {
                    if (i == 0)
                        self->current = (&self->entries[self->index].count)[self->entries[self->index].count];
                    else
                        self->current = self->entries[self->index].ranges[i][-1];
                } else {
                    self->current--;
                }
            }
            return;
        }
    }
}
