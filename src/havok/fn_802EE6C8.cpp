#pragma force_active on

struct Obj {
    char pad[0x108];
    unsigned int *list;
    int count;
};

inline int find(Obj *self, unsigned int key) {
    for (int i = 0; i < self->count; ++i) {
        unsigned int v = self->list[i];
        if (v == key)
            return i;
    }
    return -1;
}

extern "C" void fn_802EE6C8(Obj *self, unsigned int key) {
    self->list[find(self, key)] = 0;
}
