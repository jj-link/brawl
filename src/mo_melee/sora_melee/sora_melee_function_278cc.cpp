#pragma force_active on
struct Data {
    unsigned char pad[0x72];
    unsigned char flags;
};

struct Result {
    void* unused;
    Data* data;
};

struct Interface {
    virtual void unused();
    virtual Result* get();
};

struct Object {
    unsigned char pad[0x28];
    Interface* interface;
};

union Bits {
    unsigned int raw;
    struct {
        unsigned int unused : 30;
        unsigned int second : 1;
        unsigned int first : 1;
    } fields;
};

extern "C" bool fn_27_278CC(Object* __restrict object) {
    unsigned int flags = object->interface->get()->data->flags;
    Bits bits;
    bits.raw = (flags >> 2) & 1;
    bits.fields.second = (flags >> 1) & 1;
    return bits.fields.second;
}
