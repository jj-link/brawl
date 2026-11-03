#pragma force_active on

extern "C" void fn_8027CE3C(void*, int);

struct Self;

struct Object {
    unsigned char pad[0x58];
    Self* owner;
    unsigned char pad5C[0x34];
    short index;
};

struct Self {
    unsigned char pad[0x38];
    Object** data;
    int count;
    int capacity;
};

extern "C" void fn_802E9DFC(Self* self, Object* obj) {
    obj->owner = self;
    obj->index = self->count;
    if (self->count == (self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->data, 4);
    }
    self->data[self->count++] = obj;
}
