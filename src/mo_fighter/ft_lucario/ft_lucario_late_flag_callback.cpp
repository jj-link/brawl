#include <so/so_module_accesser.h>

namespace {
// The shared enumeration exposes these modules as opaque pointers. Declare the
// observed virtual ABI only, leaving their vtables and implementations external.
class TeamModule {
public:
    virtual ~TeamModule();
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14(int, bool) = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20(int) = 0;
    virtual void slot24(int) = 0;
};
struct ReflectPrefix {
    unsigned char storage[8];
};
class ReflectModule : private ReflectPrefix {
public:
    virtual ~ReflectModule();
    virtual void slot0C() = 0;
    virtual void slot10() = 0;
    virtual void slot14() = 0;
    virtual void slot18() = 0;
    virtual void slot1C() = 0;
    virtual void slot20() = 0;
    virtual void slot24() = 0;
    virtual int slot28() = 0;
    virtual int slot2C() = 0;
    int value() { return slot28(); }
};
struct TeamUpdate {
    ReflectModule* reflect;
    TeamModule* team;

    void apply() {
        int value = reflect->value();
        team->slot24(value);
    }
};
struct CallbackStorage {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
struct PointerStorageC0 {
    unsigned char prefix[0xC0];
    void* value;
};
struct PointerStorage28 {
    unsigned char prefix[0x28];
    void* value;
};
}

extern "C" bool fn_118_13900(CallbackStorage* object, unsigned int flags) {
    if (flags & 0x10) {
        return false;
    }
    if (flags & 0x8) {
        ReflectModule* reflect = static_cast<ReflectModule*>(object->accesser->m_enumerationStart->m_reflectModule);
        int value = reflect->slot2C();
        TeamModule* team = static_cast<TeamModule*>(object->accesser->m_enumerationStart->m_teamModule);
        team->slot14(value, true);
        team = static_cast<TeamModule*>(object->accesser->m_enumerationStart->m_teamModule);
        team->slot20(value);
        const soModuleEnumeration* modules = object->accesser->m_enumerationStart;
        TeamUpdate update = {
            static_cast<ReflectModule*>(modules->m_reflectModule),
            static_cast<TeamModule*>(modules->m_teamModule)
        };
        update.apply();
        return false;
    }
    return true;
}

extern "C" void* fn_118_139F0(const PointerStorageC0* object) {
    return object->value;
}

extern "C" void* fn_118_139F8(const PointerStorage28* object) {
    return object->value;
}
