#pragma force_active on
extern "C" void fn_80197484(void*, int*, unsigned short, void*, float);

struct Entry {
    char data[0x218];
};

struct Object {
    char pad[0x14];
    unsigned short* indices;
    float value;
    char pad1[0x10];
    char sub[4];
    void* field30;
    Entry* entries;
};

extern "C" void* fn_8019C1A8(Object* obj, int* out, int index) {
    unsigned short i = obj->indices[index];
    if (i & 0xC000) {
        *out = 0;
        return out;
    }
    if (obj->entries != 0) {
        return &obj->entries[i];
    }
    float value = obj->value;
    fn_80197484(obj->sub, out, i, obj->field30, value);
    return out;
}
