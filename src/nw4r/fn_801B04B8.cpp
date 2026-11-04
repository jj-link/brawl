#pragma force_active on
extern "C" void* fn_8018F340(void*, unsigned int);
extern "C" void* fn_801923B0(void*);

struct Owner {
    char padding[0xE8];
    int resource;
};
struct Arg {
    Owner* owner;
    unsigned int index;
    char padding[0x28];
    void* result;
};
inline void* const& result_for(Arg* arg) {
    return arg->result;
}
extern "C" void* fn_801B04B8(Arg* arg) {
    void* material;
    if (arg->owner) {
        if (result_for(arg) != 0)
            return arg->result;
        int resource = arg->owner->resource;
        material = fn_8018F340(&resource, arg->index);
        return fn_801923B0(&material);
    }
    return 0;
}