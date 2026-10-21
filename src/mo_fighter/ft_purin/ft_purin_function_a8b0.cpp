#pragma force_active on
extern "C" int __cntlzw(unsigned int);

namespace {
class PurinEnergy {
public:
    virtual bool isNull() const = 0;
    virtual void updateEnergy(void* accesser) = 0;
};

class PurinEnergyArray {
public:
    virtual ~PurinEnergyArray();
    virtual PurinEnergy*** at(int index) = 0;
    virtual PurinEnergy*** at(int index) const = 0;
    virtual int size() const = 0;
};
}

extern "C" void fn_124_A8B0(void*, PurinEnergyArray* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        PurinEnergy* energy = **array->at(i);
        unsigned int disabled = static_cast<unsigned int>(
            __cntlzw((static_cast<unsigned int>(
                reinterpret_cast<const unsigned char*>(energy)[5]) & 0x80) >> 7)) >> 5;
        unsigned int enabled = static_cast<unsigned int>(__cntlzw(disabled)) >> 5;
        unsigned int suspension;
        if (enabled && (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (enabled == true && suspension == 0) {
                if (enabled == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}
