#pragma force_active on
namespace {
class FtWolfEnergy {
public:
    virtual void reserved00();
    virtual void updateEnergy(void* accesser);

    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool suspended;

    bool isDisabled() const { return enabled == 0; }
    bool isEnabled() const { return isDisabled() == false; }

    void updateIfActive(unsigned int active, void* accesser) {
        if (active == true && suspended == false)
            updateEnergy(accesser);
    }

    void dispatchUpdate(unsigned int active, void* accesser) {
        if (active == true && suspended == false)
            updateIfActive(active, accesser);
    }
};

struct FtWolfEnergyUnit {
    FtWolfEnergy* energy;
};

class FtWolfEnergyArray {
public:
    virtual void reserved00();
    virtual FtWolfEnergyUnit*& at(int index);
    virtual void reserved08();
    virtual int size() const;
};
}

extern "C" void fn_125_DCDC(void*, FtWolfEnergyArray* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        FtWolfEnergy* energy = array->at(i)->energy;
        bool disabled = energy->isDisabled();
        unsigned int active = disabled == false;
        if (active && energy->suspended != true)
            energy->dispatchUpdate(active, accesser);
    }
}
