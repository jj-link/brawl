#pragma force_active on
namespace {
class EnergyBase {
public:
    virtual void reserved0();
    virtual void updateEnergy(void* accesser);

    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool suspended;

    bool isDisabled() const { return enabled == 0; }
};

struct EnergyUnit {
    EnergyBase* energy;
};

class EnergyArray {
public:
    virtual ~EnergyArray();
    virtual EnergyUnit*& at(int index);
    virtual void reserved4();
    virtual int size() const;
};
}

extern "C" void fn_93_E0EC(void*, EnergyArray* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        EnergyBase* energy = array->at(i)->energy;
        bool disabled = energy->isDisabled();
        unsigned int active = disabled == false;
        unsigned int suspension;

        if (active &&
            (suspension = reinterpret_cast<const unsigned char*>(energy)[6]) != 1) {
            if (active == true && suspension == 0) {
                if (active == true && suspension == 0) {
                    energy->updateEnergy(accesser);
                }
            }
        }
    }
}
