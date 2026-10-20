#include <types.h>
#pragma force_active on

typedef struct {
    unsigned int a : 2;
    unsigned int b : 2;
    unsigned int rest : 28;
} Fields;

extern "C" void fn_67_5188(void* self, unsigned int value) {
    Fields* f = (Fields*)((char*)self + 8);
    f->b = value & 3;
}
