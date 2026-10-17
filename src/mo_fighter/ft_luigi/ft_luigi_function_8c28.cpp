// fn_99_8C28 -- ft_luigi .text [0x8C28, 0x8CDC)
//
// soAnimCmdAddressPackArraySeparate::size() for this module's statically
// linked copy. Returns the largest of the three constituent animation-
// command address arrays' sizes. Each comparison re-evaluates the array's
// size() virtually, so the winning array is queried a second time; the
// constituent arrays are read in addresses3, addresses1, addresses2 order.

#include <mo_fighter/ft_luigi/ft_luigi_function_8d30.h>

extern "C" s32 fn_99_8C28(const ftLuigiAnimCmdAddressArrays* array) {
    s32 max = array->addresses3->size();
    if (max < array->addresses1->size())
        max = array->addresses1->size();
    if (max < array->addresses2->size())
        max = array->addresses2->size();
    return max;
}
