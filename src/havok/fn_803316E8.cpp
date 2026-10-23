#pragma force_active on
union Word {
    int value;
    float f;
};

struct Entry {
    int a, b;
    Word c;
};

struct Array {
    Entry* data;
    int size;
    unsigned int capacity;
};

struct Object {
    char pad[0x24];
    Array entries;
};

struct Self {
    char pad[8];
    Object* object;
};

extern "C" void fn_8027CE3C(void*, int);

extern "C" void fn_803316E8(Self* self, int a, int b, int c) {
    Object* object = self->object;
    Entry value;
    value.c.value = c;

    if (object->entries.size == (int)(object->entries.capacity & 0x3FFFFFFF))
        fn_8027CE3C(&object->entries, sizeof(Entry));

    int index = object->entries.size;
    Entry* base = object->entries.data;
    object->entries.size = index + 1;

    Entry* entry = base + index;
    entry->a = a;
    entry->b = b;
    entry->c = value.c;
}
