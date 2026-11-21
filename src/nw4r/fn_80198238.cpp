#pragma force_active on
extern "C" void fn_801933CC(void* sub, void* out, int index, float value);

struct Object {
    char pad[0x14];
    unsigned short* indices;
    float value;
    char pad1[0x10];
    char sub[4];
    int field30;
};

extern "C" void* fn_80198238(Object* obj, int* out, int index) {
    unsigned short i = obj->indices[index];
    if (i & 0xC000) {
        *out = 0;
        return out;
    }
    if (obj->field30 != 0) {
        return (void*)(obj->field30 + i * 0x5c);
    }
    float value = obj->value;
    fn_801933CC(obj->sub, out, i, value);
    return out;
}