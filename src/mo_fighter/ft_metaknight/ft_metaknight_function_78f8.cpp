#include <types.h>
#pragma force_active on

struct MetaKnightArrayTriple {
    u32 c;
    u32 a;
    u32 b;
};

struct MetaKnightArrayAggregate {
    void* vtable;
    MetaKnightArrayTriple cache;
    void* a;
    void* b;
    void* c;
};

extern MetaKnightArrayAggregate lbl_111_data_1734;

extern "C" void fn_111_78F8(MetaKnightArrayAggregate* obj, void* a, void* b, void* c) {
    obj->vtable = &lbl_111_data_1734;
    obj->a = a;
    obj->b = b;
    obj->c = c;
}
