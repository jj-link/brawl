#pragma once

#include <so/anim/so_anim_cmd_module_impl.h>

// Layout of soAnimCmdAddressPackArraySeparate, whose constituent arrays are private.
struct ftLuigiAnimCmdAddressArrays {
    void* vtable;
    soAnimCmdAddressPackConv pack;
    soArrayFixed<const acAnimCmdConv*>* addresses1;
    soArrayFixed<const acAnimCmdConv*>* addresses2;
    soArrayFixed<const acAnimCmdConv*>* addresses3;
};
static_assert(sizeof(ftLuigiAnimCmdAddressArrays) == sizeof(soAnimCmdAddressPackArraySeparate),
              "Animation command array layout must match");

extern "C" soAnimCmdAddressPackConv fn_99_8D30(
    const ftLuigiAnimCmdAddressArrays* array, s32 index);
