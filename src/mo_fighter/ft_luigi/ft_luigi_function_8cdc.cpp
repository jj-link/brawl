#include <mo_fighter/ft_luigi/ft_luigi_function_8d30.h>
#pragma force_active on

extern "C" soAnimCmdAddressPackConv* fn_99_8CDC(ftLuigiAnimCmdAddressArrays* array,
                                                s32 index)
{
    array->pack = fn_99_8D30(array, index);
    return &array->pack;
}
