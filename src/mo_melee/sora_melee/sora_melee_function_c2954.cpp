#include <so/so_array.h>
#include <so/so_array_vector_calculator.h>
#pragma force_active on

namespace soArrayVectorCalculator {

s32 push(soArrayVectorCalcInterface& interface, bool isFull, s32 capacity, s32 topIndex, s32 lastIndex) {
    if (isFull == 1)
        return 0;
    s32 newIndex = lastIndex + 1;
    if (newIndex >= capacity)
        newIndex -= capacity;
    interface.setLastIndex(newIndex);
    if (topIndex == newIndex)
        interface.onFull();
    return lastIndex;
}

}
