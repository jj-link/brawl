#pragma force_active on

struct Array {
    int* data;
    int size;
    unsigned int capacity;
};

struct Object {
    char pad[0x18];
    Array entries;
};

struct Self {
    char pad[8];
    Object* object;
};

extern "C" void fn_8027CE3C(void*, int);

extern "C" void fn_80331770(Self* self, int value) {
    Object* object = self->object;
    if (object->entries.size == (int)(object->entries.capacity & 0x3FFFFFFF))
        fn_8027CE3C(&object->entries, 4);

    object->entries.data[object->entries.size++] = value;
}
