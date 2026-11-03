#pragma force_active on

extern "C" void fn_8027CE3C(void*, int);

struct Obj {
    unsigned char pad[0xC];
    void* owner;
};

struct Self {
    unsigned char pad[0x60];
    Obj** data;
    int count;
    int capacity;
};

extern "C" void fn_802EA1F8(Self* self, Obj* obj) {
    if (self->count == (self->capacity & 0x3FFFFFFF)) {
        fn_8027CE3C(&self->data, 4);
    }
    self->data[self->count++] = obj;
    obj->owner = self;
}
