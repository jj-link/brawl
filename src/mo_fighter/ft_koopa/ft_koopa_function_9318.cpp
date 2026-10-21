// fn_102_9318 -- ft_koopa .text [0x9318, 0x93CC)
//
// soAnimCmdAddressPackArraySeparate::size() for this module's statically
// linked copy. Returns the largest of the three constituent animation-
// command address arrays' sizes. Each comparison re-evaluates the array's
// size() virtually, so the winning array is queried a second time; the
// constituent arrays are read in addresses3, addresses1, addresses2 order.

#include <so/anim/so_anim_cmd_module_impl.h>
#include <types.h>
#pragma force_active on

// Raw layout of soAnimCmdAddressPackArraySeparate: the aggregate itself
// caches the last packed triple at 0x8 and keeps pointers to its three
// constituent arrays at 0x10 (addresses1), 0x14 (addresses2) and
// 0x18 (addresses3).
struct ftKoopaAnimCmdAddressArrays {
    void* vtable;
    soAnimCmdAddressPackConv pack;
    soArrayFixed<const acAnimCmdConv*>* addresses1;
    soArrayFixed<const acAnimCmdConv*>* addresses2;
    soArrayFixed<const acAnimCmdConv*>* addresses3;
};

extern "C" s32 fn_102_9318(const ftKoopaAnimCmdAddressArrays* array) {
    s32 max = array->addresses3->size();
    if (max < array->addresses1->size())
        max = array->addresses1->size();
    if (max < array->addresses2->size())
        max = array->addresses2->size();
    return max;
}
