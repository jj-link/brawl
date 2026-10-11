class soKineticEnergy;
class soModuleAccesser;

struct LuigiObserverSignal {
    short flags;
};

struct LuigiGravityDispatchEnergyPrefix {
    const void* vtable;
    unsigned char field4;
    unsigned char enabled : 1;
    unsigned char : 7;
    unsigned char suspended;
    unsigned char field7;
};

struct LuigiGravityDispatchUnitPrefix {
    const void* vtable;
    unsigned char baseStorage[8];
    LuigiGravityDispatchEnergyPrefix energy;
};

extern "C" {
void fn_99_B1A4(soKineticEnergy*, soModuleAccesser*);
LuigiObserverSignal* fn_99_B874(LuigiObserverSignal*, const LuigiObserverSignal*);
bool fn_99_B284(void*, const LuigiObserverSignal*, soModuleAccesser*);
}

extern "C" soKineticEnergy* fn_99_B1DC(LuigiGravityDispatchUnitPrefix* object, int index) {
    return index == 0 ? reinterpret_cast<soKineticEnergy*>(&object->energy) : 0;
}

extern "C" bool fn_99_B1F4(LuigiGravityDispatchUnitPrefix* object,
                           const LuigiObserverSignal* attributes,
                           soModuleAccesser* accesser) {
    LuigiGravityDispatchEnergyPrefix* energy = &object->energy;
    if ((attributes->flags & 1) && static_cast<bool>(energy->enabled) == true &&
        energy->suspended == 0) {
        fn_99_B1A4(reinterpret_cast<soKineticEnergy*>(energy), accesser);
    }
    LuigiObserverSignal copy;
    fn_99_B874(&copy, attributes);
    return fn_99_B284(object->baseStorage, &copy, accesser);
}

extern "C" bool fn_99_B284(void*, const LuigiObserverSignal*, soModuleAccesser*) {
    return false;
}

extern "C" soKineticEnergy* fn_99_B28C(LuigiGravityDispatchUnitPrefix* object, int index) {
    return index == 0 ? reinterpret_cast<soKineticEnergy*>(&object->energy) : 0;
}
