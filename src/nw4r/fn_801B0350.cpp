#pragma force_active on
extern "C" void* fn_8018F340(void*, unsigned int);

struct Owner {
    char padding[0xE8];
    int resource;
};

struct Arg {
    Owner* owner;
    unsigned int index;
    char padding[0x1C];
    void* result;
    char tail[0x20];
};

inline void* const& result_for(Arg* arg) {
    return arg->result;
}

extern "C" void* fn_801B0350(Arg* arg) {
    if (arg->owner) {
        if (result_for(arg) != 0)
            return arg->result;

        int resource = arg->owner->resource;
        char* p = (char*)fn_8018F340(&resource, arg->index);
        int offset = *(int*)(p + 0x38);
        char* result;

        if (offset)
            result = p + offset;
        else
            result = 0;

        return result + 0x20;
    }

    return 0;
}
