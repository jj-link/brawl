#pragma force_active on
struct Entry {
    char pad0[0xB0];
    float value;
    char padB4[0x110];
    unsigned char marked;
};
struct Context {
    Entry** entries;
    int count;
    char pad8[0x4D];
    unsigned char reverse;
    char pad56[6];
    unsigned char active;
    unsigned char empty;
};
extern const float lbl_805A1CA8;
extern "C" void fn_80095990(Context* self, int* __restrict count) {
    switch (self->reverse) {
    case 0: {
        self->active = 1;
        int remaining = *count;
        for (int i = 0; i < self->count; ++i) {
            if (remaining > 0) {
                Entry* entry = self->entries[i];
                if (lbl_805A1CA8 != entry->value && entry->marked == 0) {
                    --remaining;
                    entry->marked = 1;
                    if (remaining == 0) return;
                }
            }
        }
        if (remaining == *count) self->empty = 1;
    break;
    }
    default: {
        self->active = 1;
        int remaining = *count;
        for (int i = self->count - 1; i >= 0; --i) {
            if (remaining > 0) {
                Entry* entry = self->entries[i];
                if (lbl_805A1CA8 != entry->value && entry->marked == 0) {
                    --remaining;
                    entry->marked = 1;
                    if (remaining == 0) return;
                }
            }
        }
        if (remaining == *count) self->empty = 1;
    }
    }
}
