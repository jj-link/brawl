#include <gr/gr_yakumono.h>
#include <st/st_trigger.h>
#include <gf/gf_memory_util.h>
#include <so/area/so_area_module_impl.h>
#pragma force_active on
#pragma opt_propagation off
extern "C" const float lbl_66_rodata_A8[];
extern "C" const char lbl_66_data_B60[];
class EarthGround : public grYakumono {
public:
    char pad[0x1d4];
    stTrigger* trigger;
    soAreaData area;
    soSet<soAreaData> set;
    ykAreaData data;
    Yakumono* getYakumono() { return m_yakumono; }
};
extern "C" void fn_66_54D8(EarthGround* self) {
    const float* values = lbl_66_rodata_A8;
    gfMemFill(&self->data, 0, 12);
    ((unsigned char*)&self->area)[0] = 0;
    ((unsigned char*)&self->area)[1] = 21;
    self->area.m_0x4 = 0;
    self->area.m_0x8 = 0;
    self->area.m_shapeFlag.m_mask = 1;
    self->area.m_nodeIndex = self->getNodeIndex(0, lbl_66_data_B60);
    self->area.m_offsetPos.m_x = values[13];
    self->area.m_offsetPos.m_y = values[14];
    self->area.m_range.m_x = values[11];
    self->area.m_range.m_y = values[12];
    self->grYakumono::setAreaGimmick(&self->area, &self->set, &self->data, false);
    stTrigger* t = g_stTriggerMng->createTrigger((Gimmick::AreaKind)47, -1);
    self->trigger = t;
    t->setObserveYakumono(self->getYakumono());
}