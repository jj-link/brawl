#include <types.h>
#pragma force_active on

// vtable at 0x5a84: 4 slots; the object holds the vtable pointer at offset 0x0.
// Slot 0xc is the indexed getter, slot 0x14 is size().
class Array {
public:
    virtual void unused0();
    virtual int* at(int index) = 0;
    virtual void unused2();
    virtual int size() = 0;
};

// soArray-style set(): fills elements [start, start+count) with *elm,
// clamping count so it never writes past size().
extern "C" void fn_96_1F6AC(Array* array, int start, const int* elm, bool flag) {
    int c = flag;
    if (c + start >= array->size())
        c = array->size() - start;
    for (int i = 0; i < c; i++)
        *array->at(start + i) = *elm;
}
