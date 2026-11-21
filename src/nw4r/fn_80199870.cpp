#pragma force_active on
extern "C" void fn_80193A74(void* sub, void* out, int index, float value);

struct Object {
    char pad[0x14];
    unsigned short* indices;
    float value;
    char pad1[0x10];
    char sub[4];
    void* entries;
};

extern "C" void* fn_80199870(Object* obj, int* out, int index) {
    int i = obj->indices[index];
    if (i & 0xC000) {
        *out = 0;
        return out;
    }
    if (obj->entries != 0) {
        return (char*)obj->entries + i * 0xE8;
    }
    float value = obj->value;
    fn_80193A74(obj->sub, out, i, value);
    return out;
}
