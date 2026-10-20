#pragma force_active on
struct Pair {
    unsigned int y, z;
};

struct Triple {
    unsigned int x;
    Pair yz;
};

struct Data {
    unsigned char padding[0x4F8];
    Triple values[1];
};

struct Object {
    Data* data;
};

extern "C" void fn_27_112AC8(Object* object, int index, Triple* output)
{
    *output = object->data->values[index];
}
