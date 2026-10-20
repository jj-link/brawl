#include <StaticAssert.h>
#include <so/so_array.h>
#include <so/so_array_vector_calculator.h>
#include <types.h>
#pragma force_active on

namespace soArrayVectorCalculator {
    void pop(soArrayVectorCalcInterface& interface, bool isEmpty, s32 capacity, s32 lastIndex) {
        if (isEmpty != 1) {
            s32 index = lastIndex - 1;
            if (index < 0) {
                index = capacity - 1;
            }
            interface.setLastIndex(index);
            interface.offFull();
        }
    }
}
