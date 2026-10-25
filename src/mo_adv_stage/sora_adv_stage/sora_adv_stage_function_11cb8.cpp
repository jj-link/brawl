#include <types.h>
#pragma force_active on

// Classes this function calls through, from the game's vtables. Keep every method in this order so
// the vtable offsets come out the same; declare parameters and return types as the code needs.

// vtable at 0x5648: 16 slots; the object holds the vtable pointer at offset 0x0; shown up to slot 3
class Container {
public:
    virtual void reserved0();   // offset 0x8
    virtual int* get(int);      // offset 0xc
    virtual void reserved1();   // offset 0x10
    virtual int size();         // offset 0x14
};

extern "C" void fn_40_11CB8(Container* self, int start, const int* value,
                            unsigned int countArg)
{
    int count = static_cast<int>(countArg);

    if (count + start >= self->size())
        count = self->size() - start;

    for (int i = 0; i < count; ++i) {
        *self->get(start + i) = *value;
    }
}
