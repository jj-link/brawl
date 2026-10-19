#include <types.h>
#pragma force_active on

struct Result {
    u32 value;
};

struct Base {
    virtual void pad();
    virtual Result* f(u32);
};

extern "C" Result* fn_27_91638(Base* object, Result* destination, u32 argument) {
    Result* result = object->f(argument);
    result->value = destination->value;
    return result;
}
