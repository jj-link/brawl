#pragma force_active on
extern "C" void* fn_8018F340(void*, unsigned int);
struct Owner { char padding[0xE8]; int resource; };
struct Arg { Owner* owner; unsigned int index; char padding[8]; void* result; };
inline void* const& result_for(Arg* arg) { return arg->result; }
extern "C" void* fn_801B015C(Arg* arg) {
    if (arg->owner) {
        if (result_for(arg) != 0)
            return arg->result;
        int resource = arg->owner->resource;
        return (char*)fn_8018F340(&resource, arg->index) + 0x1A4;
    }
    return 0;
}