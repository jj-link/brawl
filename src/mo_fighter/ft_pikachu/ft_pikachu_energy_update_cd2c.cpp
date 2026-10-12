// The switch table occupies a four-byte-aligned range in the original REL.
#pragma section data_type ".data$pikachuCD2C" ".bss"

#include <so/so_module_accesser.h>
#include <so/so_enable.h>

// Local layout view; the original concrete type names are not established.
struct PikachuMediatorEnergy {
    void* vtable;
    unsigned char nullable;
    soEnable enabled;
    bool suspended;
};

// The specialization's short-lived nullable state has a nontrivial lifetime.
// This local name is descriptive, not a recovered original declaration.
class PikachuKineticUpdateContext {
    bool m_isNull;
public:
    inline PikachuKineticUpdateContext(const bool& isNull) : m_isNull(isNull) {}
    inline ~PikachuKineticUpdateContext() {}
    bool isNull() const { return m_isNull; }
};

extern "C" void fn_98_CD2C(PikachuMediatorEnergy* energy, soModuleAccesser* accesser) {
    if (accesser->getKineticModule().getKineticType() <= 99) {
        if (energy->enabled.isEnable() == true && !energy->suspended)
            reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
    } else {
        switch (accesser->getKineticModule().getKineticType()) {
        case 100: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 101: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 102: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 103: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 104: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 105: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 106: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        case 107: {
            bool isNull = false;
            PikachuKineticUpdateContext context(isNull);
            if (!context.isNull())
                reinterpret_cast<soKineticEnergy*>(energy)->updateEnergy(accesser);
            break;
        }
        }
    }
}
