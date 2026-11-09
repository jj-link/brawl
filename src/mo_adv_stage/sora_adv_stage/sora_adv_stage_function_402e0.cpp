#pragma force_active on

extern "C" int fn_800BA3D8(void*);

struct Entry {
    char pad[0xa8];
    int values[40];
    int count;
    char pad2[4];
};
struct Object {
    char pad[0x970];
    Entry entries[2];
};

extern "C" int fn_40_402E0(Object* base, int value) {
    char* p;
    int i;
    Entry* e = &base->entries[0];
    p = (char*)e;
    for (i = 0; i < 2; i++, p += 0x150, e++) {
        if ((((unsigned int)fn_800BA3D8(p) >> 31) ^ 1) != 0) {
            for (int j = 0; j < e->count; j++) {
                if (value == e->values[j]) return j;
            }
        }
    }
    return -1;
}
