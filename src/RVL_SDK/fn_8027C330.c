#pragma force_active on

void fn_8027CE3C(void*, int);

struct Self {
    unsigned char pad[0x14];
    int* data;
    int count;
    int capacity;
};

void fn_8027C330(struct Self* self, int value) {
    if (self->count == (self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->data, 4);
    }
    self->data[self->count++] = value;
}
