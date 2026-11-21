#pragma force_active on
extern "C" void fn_8019564C(void*, void*, unsigned int, void*, float);

struct Object {
    char pad[0x14];
    unsigned short* indices;
    float value;
    char pad1[0x10];
    char sub[4];
    char* field30;
};

extern "C" int* fn_8019B74C(Object* obj, int* out, int index) {
    unsigned short i = obj->indices[index];
    if ((i & 0xC000) != 0) {
        out[0] = 0;
        return out;
    }
    if (obj->field30) {
        return (int*)(obj->field30 + (int)i * 0x4C);
    }
    fn_8019564C((char*)obj + 0x2C, out, i, obj->field30, obj->value);
    return out;
}
