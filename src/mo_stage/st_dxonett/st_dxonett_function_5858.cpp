#pragma force_active on
struct Object {
    unsigned char padding[8];
    unsigned int flags;
};

extern "C" unsigned int fn_78_5858(const Object* object) {
    return (object->flags >> 19) & 1U;
}
