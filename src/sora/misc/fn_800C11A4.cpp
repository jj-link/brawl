#pragma force_active on
struct Entry {
    int a, b, c, d;
};

struct Object {
    char pad[0x11C];
    Entry entries[16];
    int count;
};

extern "C" int fn_800C11A4(Object* p, const Entry* src) {
    if (p->count >= 16) {
        return 0;
    }
    p->entries[p->count++] = *src;
    return 1;
}
