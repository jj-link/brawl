#include <so/so_array.h>
#pragma force_active on

namespace {
class PikminEnergy {
public:
    virtual void reserved() = 0;
    virtual void update(void*) = 0;
};
}

extern "C" void fn_113_2A278(void*, soArrayFixed<PikminEnergy**>* array, void* argument) {
    for (int i = 0; i < array->size(); ++i) {
        PikminEnergy* energy = *array->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(energy)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
        unsigned int suspension;
        if (enabled && (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->update(argument);
                }
            }
        }
    }
}
