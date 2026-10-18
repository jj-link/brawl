#pragma force_active on
struct Fn114Object {
    unsigned char pad0[0x14];
    int base;
};

struct Fn114Entry {
    unsigned char pad0[0x28];
    unsigned int* values;
};

extern "C" unsigned int fn_114_20C20(
    Fn114Object* object,
    void* unused,
    int index,
    int subindex
) {
    Fn114Entry* entry = reinterpret_cast<Fn114Entry*>(
        reinterpret_cast<unsigned char*>(object) + (index - object->base) * 4
    );
    return entry->values[subindex];
}
