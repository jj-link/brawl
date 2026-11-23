#pragma force_active on
extern "C" int fn_800BA3D8(void*);
inline bool active(void* p) { return fn_800BA3D8(p) >= 0; }
struct Entry {
    char pad[0xA8];
    int values[10];
    int count;
    char tail[4];
};
struct Object {
    char pad[0xBC];
    Entry entries[2];
};
extern "C" int fn_29_F18(Object* self) {
    int mask = 0;
    for (int i = 0; i < 2; ++i) {
        if (active(&self->entries[i])) {
            for (int j = 0; j < self->entries[i].count; ++j)
                mask |= 1 << self->entries[i].values[j];
        }
    }
    for (int i = 0, bit = 1; i < 10; ++i, bit <<= 1) {
        if (!(mask & bit)) return i;
    }
    return -1;
}
