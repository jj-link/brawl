#include <so/so_array.h>
#include <so/so_array_vector_calculator.h>
#include <types.h>

#pragma force_active on

extern "C" void fn_27_C2C18(void* self, s32 base, s32 count, s32 mod);

namespace soArrayVectorCalculator {

s32 insert(soArrayVectorCalcInterface& iface, s32 index, bool isFull, s32 size, s32 capacity, s32 topIndex, s32 lastIndex) {
    if (isFull == true) {
        return 0;
    }
    if (index < 0 || index > size) {
        return 0;
    }
    s32 result;
    if (size <= 0 || index == size) {
        s32 newLast = lastIndex + 1;
        if (newLast >= capacity) {
            newLast -= capacity;
        }
        iface.setLastIndex(newLast);
        if (topIndex == newLast) {
            iface.onFull();
        }
        result = lastIndex;
    } else {
        if (index == 0) {
            return unshift(iface, isFull, capacity, topIndex, lastIndex);
        }
        fn_27_C2C18(&iface, index + topIndex, size - index, capacity);
        s32 newLast = lastIndex + 1;
        if (newLast >= capacity) {
            newLast = 0;
        }
        iface.setLastIndex(newLast);
        s32 ret = index;
        ret = ret + topIndex;
        if (ret >= capacity) {
            ret -= capacity;
        }
        if (topIndex == newLast) {
            iface.onFull();
        }
        result = ret;
    }
    return result;
}

}
