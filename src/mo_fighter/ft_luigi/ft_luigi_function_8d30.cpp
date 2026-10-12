#include <mo_fighter/ft_luigi/ft_luigi_function_8d30.h>

extern "C" soAnimCmdAddressPackConv fn_99_8D30(
    const ftLuigiAnimCmdAddressArrays* array, s32 index) {
    if (index < 0) {
        soAnimCmdAddressPackConv pack = { 0, 0, 0 };
        return pack;
    }

    const acAnimCmdConv* address1 = 0;
    if (index < array->addresses3->size())
        address1 = array->addresses3->at(index);

    const acAnimCmdConv* address2 = 0;
    if (index < array->addresses1->size())
        address2 = array->addresses1->at(index);

    const acAnimCmdConv* address3 = 0;
    if (index < array->addresses2->size())
        address3 = array->addresses2->at(index);

    soAnimCmdAddressPackConv pack = { address1, address2, address3 };
    return pack;
}
