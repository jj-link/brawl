#pragma force_active on

struct Owner {
    char padding[0xE8];
    int resource;
};

struct Arg {
    Owner* owner;
    unsigned int index;
    char padding[0x18];
    void* result;
};

inline void* const& result_for(Arg* arg) {
    return arg->result;
}

extern "C" void* fn_8018F340(void*, unsigned int);

extern "C" void* fn_801B02DC(Arg* arg) {
    if (arg->owner) {
        if (result_for(arg) != 0)
            return arg->result;

        int resource = arg->owner->resource;
        char* p = (char*)fn_8018F340(&resource, arg->index);
        int offset = *(int*)(p + 0x38);

        if (offset)
            return p + offset;
        return 0;
    }
    return 0;
}