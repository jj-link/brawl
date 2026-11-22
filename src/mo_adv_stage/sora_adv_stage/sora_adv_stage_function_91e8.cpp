#include <types.h>
#include <st/stage.h>
#include <st/st_data_container.h>
#include <sora_adv_stage/gr_adventure_final.h>
#pragma force_active on

static inline s16 getModelIndex(stDataContainerData* data) { return *(u8*)data; }

extern "C" {
extern char lbl_40_data_444[];
extern char lbl_40_data_448[];
grAdventureFinal* create__16grAdventureFinalFiPCcPCc(s16, const char*, const char*);

void fn_40_91E8(Stage* stage, u32 type, stDataMultiContainer* multi) {
    grAdventureFinal* ground;
    stDataContainer* container;
    u32 index = 0;
    while ((container = multi->searchContainer(type, index++)) != 0) {
        for (u32 i = 0; i < container->m_filedata->m_numFiles; i++) {
            ground = create__16grAdventureFinalFiPCcPCc(
                getModelIndex(container->getData(i)), lbl_40_data_444, lbl_40_data_448);
            if (ground != 0) {
                stage->addGround(ground);
                ground->startup(*(gfArchive**)((char*)stage + 0x1a0), 0,
                                (gfSceneRoot::LayerType)0);
            }
        }
    }
}
}