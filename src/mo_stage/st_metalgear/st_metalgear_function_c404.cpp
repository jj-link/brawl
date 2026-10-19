#include <so/so_array.h>
#pragma force_active on

extern "C" void fn_71_C404(soArrayVectorAbstract<int>* self) {
    soArrayVectorCalculator::clear(*self);
    self->setSize(0);
}
