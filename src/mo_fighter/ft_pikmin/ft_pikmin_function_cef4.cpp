#include <so/so_array.h>
#include <types.h>
#pragma force_active on

struct Fn113Triple {
    u32 a;
    u32 b;
    u32 c;
};

struct Fn113Source {
    void* vtable;
    Fn113Triple cache;
    soArrayFixed<u32>* p10;
    soArrayFixed<u32>* p14;
    soArrayFixed<u32>* p18;
};

extern "C" Fn113Triple fn_113_CEF4(Fn113Source* src, s32 index) {
    if (index < 0) {
        Fn113Triple result = { 0, 0, 0 };
        return result;
    }
    u32 v18 = 0;
    if (index < src->p18->size()) {
        v18 = src->p18->at(index);
    }
    u32 v10 = 0;
    if (index < src->p10->size()) {
        v10 = src->p10->at(index);
    }
    u32 v14 = 0;
    if (index < src->p14->size()) {
        v14 = src->p14->at(index);
    }
    Fn113Triple result = { v18, v10, v14 };
    return result;
}
