class soKineticEnergy;
class soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiMainEnergyPrefix {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char field7;
};

struct LuigiMainEnergyUnitPrefix {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiMainEnergyPrefix energy;
};

extern "C" {
void fn_99_C850(soKineticEnergy*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B4CC(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" bool fn_99_B43C(LuigiMainEnergyUnitPrefix* object,
                           const LuigiObserverSignal* attributes,
                           soModuleAccesser* accesser) {
    LuigiMainEnergyPrefix* energy = &object->energy;
    if ((attributes->flags & 1) && static_cast<bool>(energy->enabled) == true &&
        energy->suspended == 0) {
        fn_99_C850(reinterpret_cast<soKineticEnergy*>(energy), accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, attributes);
    return fn_99_B4CC(object->baseStorage, &copy, accesser);
}

extern "C" bool fn_99_B4CC(void*, const LuigiObserverSignal*, soModuleAccesser*) {
    return false;
}
