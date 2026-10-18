#pragma force_active on
struct Fn114Object {
    unsigned char pad[0x14];
    int start;
};

struct Fn114Entry {
    unsigned char pad[0x20];
    unsigned int* values;
};

extern "C" unsigned int fn_114_1C240(Fn114Object* object, unsigned int unused, int index, unsigned int subindex) {
    Fn114Entry* entry = (Fn114Entry*)((char*)object + (index - object->start) * 4);
    return entry->values[subindex];
}
