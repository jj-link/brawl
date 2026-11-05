#pragma force_active on
extern "C" void fn_8027CE3C(void*, int);

struct Self {
    char pad[0x1cc];
    void** data;
    int count;
    int capacity;
};

static inline int find(Self* self) {
    for (int i = 0; i < self->count; i++) {
        if (self->data[i] == 0)
            return i;
    }
    return -1;
}

extern "C" void fn_802E18B0(Self* self, void* obj) {
    int i = find(self);
    if (i >= 0) {
        self->data[i] = obj;
    } else {
        if ((int)*(unsigned int*)&self->count == (self->capacity & 0x3fffffff))
            fn_8027CE3C(&self->data, 4);
        self->data[self->count++] = obj;
    }
}
