#pragma force_active on
struct Inner {
    unsigned int pad;
    void *value;
};

struct Object {
    Inner *inner;
    unsigned char state;
};

extern "C" void *fn_113_2359C(Object *object)
{
    if (object->state == 1)
        return 0;
    return object->inner->value;
}
