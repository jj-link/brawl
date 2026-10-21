#pragma force_active on
struct Entry {
    unsigned char pad[8];
    void (*callback)(Entry*);
};

struct Object {
    unsigned char pad[12];
    Entry** entries;
    int unk10;
    int count;
};

extern "C" void fn_8027D438(void*);

extern "C" void fn_80331E64(Object* self) {
    int i = 0;
    for (; i <= self->count; ++i) {
        if (self->entries[i] != 0)
            break;
    }

    while ((signed char)((i <= self->count) & 0xff)) {
        void (*callback)(Entry*) =
            self->entries[i + self->count + 1]->callback;
        if (callback != 0)
            callback(self->entries[i]);

        for (++i; i <= self->count; ++i) {
            if (self->entries[i] != 0)
                break;
        }
    }

    fn_8027D438(&self->entries);
}
