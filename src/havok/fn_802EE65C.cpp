#pragma force_active on

extern "C" void fn_8027CE3C(void*, int);

struct Self {
    unsigned char pad[0x108];
    int* data;
    int count;
    int capacity;
};

extern "C" void fn_802EE65C(Self* self, int value) {
    if (self->count == (self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->data, 4);
    }
    self->data[self->count++] = value;
}
