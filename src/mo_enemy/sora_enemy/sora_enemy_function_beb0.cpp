#include <so/so_array.h>
#pragma force_active on

struct BeB0Source {
    char pad[0x10];
    soArrayFixed<u32>* b;
    soArrayFixed<u32>* c;
    soArrayFixed<u32>* a;
};

struct BeB0Triple {
    u32 a;
    u32 b;
    u32 c;
};

extern "C" BeB0Triple fn_41_BEB0(BeB0Source* src, s32 index) {
    if (index < 0) {
        BeB0Triple result = { 0, 0, 0 };
        return result;
    }
    u32 a = 0;
    if (index < src->a->size()) {
        a = src->a->at(index);
    }
    u32 b = 0;
    if (index < src->b->size()) {
        b = src->b->at(index);
    }
    u32 c = 0;
    if (index < src->c->size()) {
        c = src->c->at(index);
    }
    BeB0Triple result = { a, b, c };
    return result;
}
