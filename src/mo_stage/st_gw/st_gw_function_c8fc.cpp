#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_63_C8FC(soArrayVectorAbstract<u32>* self) {
    soArrayVectorCalculator::clear(*self);
    self->setSize(0);
}
