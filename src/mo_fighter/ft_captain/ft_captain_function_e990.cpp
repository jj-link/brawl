#include <so/so_module_accesser.h>
#pragma force_active on
#pragma opt_propagation off

struct CaptainFinalHit {
    unsigned int taskId;
    int linkIndex;
    unsigned char reserved[0x1c];
    unsigned char active : 1;
    unsigned char applied : 1;
    unsigned char remaining : 6;
    unsigned char padding[3];
};

struct CaptainFinalEvent : soLinkEventArgs {
    int kind;
    union {
        int attackId;
        unsigned char payload[0x24];
    };

    CaptainFinalEvent(int value)
        : soLinkEventArgs(0x44f), kind(value) {}
};

class CaptainFinalAttackModule {
public:
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void hitAbsolute(int, Vec3f*, unsigned int, int, int);
};

extern "C" {
extern CaptainFinalHit* lbl_100_bss_268;
extern const char lbl_100_data_6600[];
extern const float lbl_100_rodata_44;
extern const float lbl_100_rodata_30;

Vec3f* fn_100_CC84(Vec3f*, float, float, float);
void fn_100_E184(Vec3f*, const Vec3f*);
}

extern "C" void fn_100_E990(void*, soModuleAccesser* accesser) {
    soWorkManageModule* work =
        accesser->m_enumerationStart->m_workManageModule;
    soModelModule* model =
        accesser->m_enumerationStart->m_modelModule;
    soLinkModule* link =
        accesser->m_enumerationStart->m_linkModule;

    Vec3f direction;
    fn_100_CC84(&direction, lbl_100_rodata_44,
                lbl_100_rodata_30, lbl_100_rodata_30);

    Vec3f position;
    Vec3f target;
    Vec3f delta;
    const char* nodeName = lbl_100_data_6600;
    Vec3f initial = model->getNodeGlobalPosition(
        model->getNodeId(nodeName), false);
    fn_100_E184(&position, &initial);

    int count = work->getInt(0x20000000);
    CaptainFinalHit* hit = lbl_100_bss_268;

    for (int i = 0; i < count; ++i, ++hit) {
        if (hit->active && !hit->applied &&
            hit->taskId != 0xffffffff) {
            Vec3f parent = link->getParentModelNodeGlobalPosition(
                hit->linkIndex, lbl_100_data_6600, false);
            fn_100_E184(&target, &parent);

            Vec3f difference;
            Vec3fSub(&difference, &target, &position);
            fn_100_E184(&delta, &difference);

            if (direction.m_z * delta.m_z +
                    (direction.m_x * delta.m_x +
                     direction.m_y * delta.m_y) <=
                lbl_100_rodata_30) {
                CaptainFinalEvent event(8);
                event.attackId = 1;
                link->sendEventParents(hit->linkIndex, event);

                reinterpret_cast<CaptainFinalAttackModule*>(
                    accesser->m_enumerationStart->m_collisionAttackModule)
                    ->hitAbsolute(0, &position, hit->taskId, 0, 0);

                CaptainFinalEvent finish(4);
                link->sendEventParents(hit->linkIndex, finish);
                hit->applied = true;
                break;
            }
        }
    }
}
