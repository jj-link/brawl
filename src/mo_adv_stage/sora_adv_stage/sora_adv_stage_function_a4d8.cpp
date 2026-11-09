#pragma force_active on
#include <gr/gr_gimmick_warpzone.h>
#include <gm/gm_global.h>
#include <st/st_data_container.h>
#include <st/stage.h>
class GimmickDataSetter : public grGimmickWarpZone {
public:
    virtual void setGimmickData(void*);
};
extern "C" {
extern char lbl_40_data_31C[];
grGimmickWarpZone* fn_40_2AF48(short, const char*);
stDataContainer* searchContainer__20stDataMultiContainerFUlUl(void*, u32, u32);
void fn_40_A4D8(void* stage, u32 kind, stDataMultiContainer* multi) {
    grGimmickWarpZone* ground;
    stDataContainer* container;
    u32 containerIndex = 0;
    while ((container = searchContainer__20stDataMultiContainerFUlUl(multi, kind, containerIndex++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; ++i) {
            unsigned char* record = (unsigned char*)container->getData(i);
            ground = fn_40_2AF48((short)record[0x3c], lbl_40_data_31C);
            unsigned char* table = *(unsigned char**)((unsigned char*)stage + 0x1c0);
            if (table != 0) {
                unsigned char* advData = (unsigned char*)g_GameGlobal->m_advData;
                int frame = advData[0x5fd];
                int index = frame - advData[0x4916];
                int maxIndex = frame - 5;
                if (index < maxIndex) index = maxIndex;
                if (index < 0) index = 0;
                if (index > 14) index = 14;
                *(int*)(record + 0x238) = (int)(*(float*)(record + 0x1e4) * (float)table[(unsigned char)index + 0x80]);
            } else {
                *(int*)(record + 0x238) = (int)*(float*)(record + 0x1e4);
            }
            if (ground != 0) {
                ((Stage*)stage)->addGround(ground);
                ((GimmickDataSetter*)ground)->setGimmickData(record);
                ground->startup(*(gfArchive**)((unsigned char*)stage + 0x1a0), (u32)0, (gfSceneRoot::LayerType)0);
            }
        }
    }
}
}