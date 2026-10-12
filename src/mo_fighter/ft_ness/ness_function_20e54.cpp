#include <so/so_module_accesser.h>

namespace {
// The common module enumeration leaves physics opaque. This view exposes
// only the indexed float accessor used here; its vptr follows eight bytes.
struct NessPhysicsPrefix {
    unsigned char prefix[8];
};
class NessPhysicsModule : public NessPhysicsPrefix {
    virtual void slot_08() = 0;
    virtual void slot_0C() = 0;
    virtual void slot_10() = 0;
    virtual void slot_14() = 0;
    virtual void slot_18() = 0;
    virtual void slot_1C() = 0;
    virtual void slot_20() = 0;
    virtual void slot_24() = 0;
    virtual void slot_28() = 0;
    virtual void slot_2C() = 0;
    virtual void slot_30() = 0;
    virtual void slot_34() = 0;
    virtual void slot_38() = 0;
    virtual void slot_3C() = 0;
    virtual void slot_40() = 0;
    virtual void slot_44() = 0;
    virtual void slot_48() = 0;
    virtual void slot_4C() = 0;
    virtual void slot_50() = 0;
    virtual void slot_54() = 0;
    virtual void slot_58() = 0;
    virtual void slot_5C() = 0;
    virtual void slot_60() = 0;
    virtual void slot_64() = 0;
    virtual void slot_68() = 0;
    virtual void slot_6C() = 0;
    virtual void slot_70() = 0;
public:
    virtual float getIndexedValue(int) = 0;
};
struct NessArticleParameters {
    int flaggedCount;
    int normalCount;
};
struct NessArticleOwner {
    unsigned char prefix[0x2100];
    const NessArticleParameters* parameters;
};
}

extern "C" {
extern const unsigned char lbl_101_data_80F8[], lbl_101_data_4330[];
extern const float lbl_101_rodata_158;
void* __dynamic_cast(void*, long, const void*, const void*, short);
}

extern "C" void fn_101_20E54(void*, soModuleAccesser* accesser) {
    NessArticleOwner* article = static_cast<NessArticleOwner*>(__dynamic_cast(
        accesser->m_stageObject, 0x3c, lbl_101_data_80F8, lbl_101_data_4330,
        static_cast<short>(1)));
    const NessArticleParameters* parameters = article->parameters;
    const soModuleEnumeration* modules = accesser->m_enumerationStart;
    soWorkManageModule* work = modules->m_workManageModule;
    NessPhysicsModule* physics = static_cast<NessPhysicsModule*>(modules->m_physicsModule);
    int count;
    if (work->isFlag(0x22000000)) {
        count = parameters->flaggedCount;
    } else {
        count = parameters->normalCount;
    }
    float total = lbl_101_rodata_158;
    for (int index = 0; index < count; ++index) {
        total += physics->getIndexedValue(index);
    }
    work->setFloat(total, 0x21000000);
    work->setInt(count, 0x20000001);
}
