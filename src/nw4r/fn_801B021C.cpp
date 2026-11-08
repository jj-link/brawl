#pragma force_active on
extern "C" void* fn_8018F340(void*, unsigned int);

struct Owner {
    char padding[0xE8];
    int resource;
};

struct Arg {
    Owner* owner;
    unsigned int index;
    char padding[0x10];
    void* result;
};

inline void* const& result_for(Arg* arg) {
    return arg->result;
}

extern "C" void* fn_801B021C(Arg* arg) {
    if (arg->owner) {
        if (result_for(arg) != 0)
            return arg->result;

        int resource = arg->owner->resource;
        char* p = (char*)fn_8018F340(&resource, arg->index);
        return p + 0x14;
    }

    return 0;
}
