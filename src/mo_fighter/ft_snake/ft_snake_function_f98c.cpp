#include <so/so_array.h>
#pragma force_active on

struct SnakeArrayTriple {
    u32 a;
    u32 b;
    u32 c;
};

struct SnakeArrayAggregate {
    void* vtable;
    u32 pad[3];
    soArrayFixed<u32>* p10;
    soArrayFixed<u32>* p14;
    soArrayFixed<u32>* p18;
};

extern "C" SnakeArrayTriple fn_122_F98C(SnakeArrayAggregate* arrays, s32 index) {
    if (index < 0) {
        SnakeArrayTriple result = { 0, 0, 0 };
        return result;
    }

    u32 a = 0;
    if (index < arrays->p18->size()) {
        a = arrays->p18->at(index);
    }

    u32 b = 0;
    if (index < arrays->p10->size()) {
        b = arrays->p10->at(index);
    }

    u32 c = 0;
    if (index < arrays->p14->size()) {
        c = arrays->p14->at(index);
    }

    SnakeArrayTriple result = { a, b, c };
    return result;
}
