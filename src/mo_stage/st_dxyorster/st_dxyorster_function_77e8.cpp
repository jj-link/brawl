#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_76_77E8(soArrayVectorAbstract<int>* self) {
    soArrayVectorCalculator::clear(*self);
    self->setSize(0);
}
