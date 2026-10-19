#include <types.h>
#pragma force_active on

struct A7CCResult {
    u32 words[4];
};

extern "C" void fn_123_A6A0(A7CCResult* result, A7CCResult* destination, const A7CCResult* source);

extern "C" A7CCResult& fn_123_A7CC(A7CCResult* destination, const A7CCResult* source) {
    A7CCResult result;
    fn_123_A6A0(&result, destination, source);
    return result;
}
