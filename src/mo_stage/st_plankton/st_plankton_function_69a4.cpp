#include <stddef.h>
#pragma force_active on

struct Plankton {
    int field0;
    int field1;
    int field2;
};

extern "C" int fn_74_69A4(Plankton *self) {
    return (self->field2 >> 25) & 1;
}
