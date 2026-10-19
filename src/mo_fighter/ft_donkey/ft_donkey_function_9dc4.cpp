#include <types.h>
#pragma force_active on

struct Result {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
};

extern "C" Result fn_92_9C98(void*, void*);

extern "C" Result* fn_92_9DC4(void* arg1, void* arg2) {
    return &fn_92_9C98(arg1, arg2);
}
