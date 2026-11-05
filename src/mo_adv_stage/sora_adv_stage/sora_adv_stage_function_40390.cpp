#pragma force_active on
extern "C" int fn_800BA3D8(void*);
struct Entry { char pad[0xa8]; int values[40]; int count; int value; };
struct Object { char pad[0x970]; Entry entries[2]; };
inline int find(Object* self, int value) {
    char* p;
    int i;
    Entry* e = self->entries;
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
extern "C" int fn_40_40390(Object* self, int index, int value) {
    if (find(self, value) >= 0) return 0;
    for (int i = index - 1; i >= 0; i--) {
        if (value == self->entries[i].value) return 0;
    }
    return 1;
}