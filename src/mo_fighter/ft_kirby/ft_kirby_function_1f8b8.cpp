#pragma force_active on
struct Data {
    unsigned int words[20];
};

struct Object {
    unsigned int value;
    unsigned int unused[2];
    unsigned int count;
    Data data;
};

extern "C" Object* fn_96_1F8B8(Object* dst, const Object* src) {
    dst->value = src->value;
    dst->count = src->count;
    dst->data = src->data;
    return dst;
}
