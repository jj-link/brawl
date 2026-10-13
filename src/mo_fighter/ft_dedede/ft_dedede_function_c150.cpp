#include <so/so_array.h>

struct soAnimCmdAddressPackConv;

// soAnimCmdAddressPackArraySeparate inherits this fixed-array emptiness check.
extern "C" bool fn_117_C150(const soArrayFixed<soAnimCmdAddressPackConv>* array) {
    return array->size() == 0;
}
