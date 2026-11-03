#pragma force_active on

struct Object {
    char pad[0x14];
    unsigned short* indices;
    float value;
    char pad1[0x10];
    char sub[4];
    void* entries;
};

extern "C" void fn_801935E4(void* sub, void* out, int index, void* arg4, float value);

extern "C" void* fn_80198F00(Object* obj, void* arg1, int index) {
    unsigned short i = obj->indices[index];
    if (i & 0xC000) {
        *(unsigned char*)arg1 = 0;
        *(unsigned char*)((char*)arg1 + 1) = 0;
        return arg1;
    }
    if (obj->entries != 0) {
        return (char*)obj->entries + i * 0x44;
    }
    float value = obj->value;
    fn_801935E4(obj->sub, arg1, i, obj->entries, value);
    return arg1;
}