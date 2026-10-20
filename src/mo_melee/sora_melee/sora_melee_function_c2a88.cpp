#include <so/so_array.h>
#pragma force_active on

void soArrayVectorCalculator::clear(soArrayVectorCalcInterface& calc) {
    calc.setTopIndex(0);
    calc.setLastIndex(0);
    calc.offFull();
}
