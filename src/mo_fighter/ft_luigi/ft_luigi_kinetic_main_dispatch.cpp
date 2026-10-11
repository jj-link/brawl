class soKineticEnergy;
class soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiMainDispatchEnergyPrefix {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char field7;
};

struct LuigiMainDispatchUnitPrefix {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiMainDispatchEnergyPrefix energy;
};

extern "C" {
void fn_99_B33C(soKineticEnergy*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B41C(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" bool fn_99_B38C(LuigiMainDispatchUnitPrefix* object,
                           const LuigiObserverSignal* attributes,
                           soModuleAccesser* accesser) {
    LuigiMainDispatchEnergyPrefix* energy = &object->energy;
    if ((attributes->flags & 1) && static_cast<bool>(energy->enabled) == true &&
        energy->suspended == 0) {
        fn_99_B33C(reinterpret_cast<soKineticEnergy*>(energy), accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, attributes);
    return fn_99_B41C(object->baseStorage, &copy, accesser);
}

extern "C" bool fn_99_B41C(void*, const LuigiObserverSignal*, soModuleAccesser*) {
    return false;
}
