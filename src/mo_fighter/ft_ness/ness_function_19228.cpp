#include <so/so_module_accesser.h>
#include <math.h>

// The article manager is opaque in the common enumeration. Only the
// operation used here is specified; earlier slots preserve its dispatch ABI.
class NessThunderArticleManager {
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
public:
    virtual void operation(int article, int target) = 0;
};
struct NessThunderLinkEvent : soLinkEventArgs {
    NessThunderLinkEvent() : soLinkEventArgs(0x838) {}
};
struct NessThunderTransition {
    unsigned char prefix[0x60];
    soModuleAccesser* accesser;
};
extern "C" {
// Shared constant pool: zero, pi and two-pi are at offsets 8, 20 and 24.
extern const float lbl_101_rodata_D0[];
extern const unsigned char lbl_101_data_83D0[], lbl_101_data_4330[];
extern const unsigned char lbl_101_data_9840[], lbl_101_data_3890[];
void* __dynamic_cast(void*, long, const void*, const void*, short);
Vec2f* fn_101_FE5C(Vec2f*, const Vec2f*);
void fn_27_8D1B0(void*, int, soModuleAccesser*);
}

extern "C" int fn_101_19228(NessThunderTransition* object) {
    const float* constants = lbl_101_rodata_D0;
    Vec2f speed;
    NessThunderLinkEvent event;
    object->accesser->m_enumerationStart->m_linkModule->sendEventParents(3, event);
    static_cast<NessThunderArticleManager*>(
        object->accesser->m_enumerationStart->m_generateArticleManageModule)->operation(0, 0);
    object->accesser->m_enumerationStart->m_workManageModule->setInt(0, 0x20000000);
    object->accesser->m_enumerationStart->m_linkModule->setAttribute(
        3, static_cast<soLinkConnection::Attribute>(4), false);
    float angle = object->accesser->m_enumerationStart->m_workManageModule->getFloat(0x21000000);
    angle += constants[5];
    while (angle < constants[2]) {
        angle += constants[6];
    }
    while (angle > constants[6]) {
        angle -= constants[6];
    }
    object->accesser->m_enumerationStart->m_workManageModule->setFloat(angle, 0x21000000);
    unsigned char* fighter = static_cast<unsigned char*>(__dynamic_cast(
        object->accesser->m_stageObject, 0x3c, lbl_101_data_83D0, lbl_101_data_4330, 1));
    const float* parameters = *reinterpret_cast<const float**>(fighter + 0xDDD0);
    speed.m_x = parameters[1] * static_cast<float>(cos(angle));
    speed.m_y = parameters[1] * static_cast<float>(sin(angle));
    void* energy = __dynamic_cast(object->accesser->m_enumerationStart->m_kineticModule->getEnergy(0),
        0, lbl_101_data_9840, lbl_101_data_3890, 1);
    fn_101_FE5C(reinterpret_cast<Vec2f*>(reinterpret_cast<unsigned long>(energy) + 8), &speed);
    fn_27_8D1B0(reinterpret_cast<unsigned char*>(object) + 0x88, -1, object->accesser);
    return 0;
}
