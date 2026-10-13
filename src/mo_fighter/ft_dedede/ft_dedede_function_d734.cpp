namespace {
class DededeEnergy {
public:
    virtual bool isNull() const = 0;
    virtual void updateEnergy(void* accesser) = 0;

    unsigned char nullable;
    unsigned char enabled : 1;
    unsigned char otherFlags : 7;
    bool suspended;

    bool isDisabled() const { return enabled == 0; }
    bool isEnabled() const { return isDisabled() == false; }

    void updateIfActive(bool active, void* accesser) {
        if (active == true && suspended == false)
            updateEnergy(accesser);
    }
    void dispatchUpdate(bool active, void* accesser) {
        if (active == true && suspended == false)
            updateIfActive(active, accesser);
    }
};
struct DededeEnergyUnit {
    DededeEnergy* energy;
};
class DededeEnergyArray {
public:
    virtual ~DededeEnergyArray();
    virtual DededeEnergyUnit*& at(int index) = 0;
    virtual DededeEnergyUnit* const& at(int index) const = 0;
    virtual int size() const = 0;
};
}

// Update each enabled, unsuspended energy through the array's live virtual view.
extern "C" void fn_117_D734(void*, DededeEnergyArray* array, void* accesser) {
    for (int i = 0; i < array->size(); ++i) {
        DededeEnergy* energy = array->at(i)->energy;
        bool active = energy->isEnabled();
        if (active && energy->suspended != true)
            energy->dispatchUpdate(active, accesser);
    }
}
