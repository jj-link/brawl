#include <so/so_array.h>
#pragma force_active on

class CrayonArray : public soArrayVectorAbstract<int> {
public:
    void clear();
};

extern "C" void fn_56_7458(CrayonArray* self) {
    soArrayVectorCalculator::clear(*self);
    self->setSize(0);
}
