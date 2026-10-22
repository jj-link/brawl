#include <types.h>
#pragma force_active on
namespace {
class PeachEnergy {
public:
    virtual void reserved0();
    virtual void update(void* accesser);
    virtual void reserved2();
    virtual void reserved3();
};

class PeachEnergyArray {
public:
    virtual void reserved0();
    virtual PeachEnergy*** at(int index);
    virtual void reserved2();
    virtual int size();
};
}

extern "C" void fn_103_C774(void*, PeachEnergyArray* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        PeachEnergy* energy = **array->at(i);
        enum EnableState { Disabled = 0, Enabled = 1 };
        EnableState disabled = static_cast<EnableState>(
            ((static_cast<unsigned int>(
                  reinterpret_cast<const unsigned char*>(energy)[5]) &
              0x80) >>
             7) == 0);
        unsigned int enabled = disabled == 0;
        unsigned int suspension;

        if (enabled &&
            (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->update(accesser);
                }
            }
        }
    }
}
