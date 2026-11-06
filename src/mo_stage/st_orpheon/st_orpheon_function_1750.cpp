#include <gr/gr_tengan_event.h>
#include <gr/gr_madein.h>
#include <st/st_melee.h>
#include <gf/gf_3d_scene.h>

#pragma force_active on

struct Orpheon {
    char pad[0x1a0];
    gfArchive* archive;
    char pad2[0xe0];
    grTenganEvent event;
    grTenganEvent other;
};

extern "C" {
extern const float lbl_55_rodata_0[];
extern const float lbl_55_rodata_4;
void fn_55_1750(Orpheon* self, float dt) {
    if (self->event.isEvent()) {
        switch (self->event.getPhase()) {
        case 0:
            if (!self->other.isEvent() && self->event.isReadyEnd()) {
                g_gfSceneRoot->removeResAnmScn();
                ((Stage*)self)->registScnAnim((nw4r::g3d::ResFileData*)self->archive->getData(Data_Type_Scene, 1, 0xfffe), 0);
                ((grMadein*)((Stage*)self)->getGround(1))->setMotionDetails(0, 0, 0, 0, 1);
                ((grMadein*)((Stage*)self)->getGround(1))->startEntity();
                self->event.setPhase(self->event.getPhase() + 1);
                ((stMelee*)self)->playSeBasic((SndID)0x1bd2, lbl_55_rodata_0[0]);
                self->event.m_manualFramesLeft = lbl_55_rodata_0[0];
            }
            break;
        case 1:
            self->event.m_manualFramesLeft += dt;
            if (self->event.m_manualFramesLeft >= lbl_55_rodata_4) {
                ((stMelee*)self)->playSeBasic((SndID)0x1bd3, lbl_55_rodata_0[0]);
                self->event.m_manualFramesLeft = lbl_55_rodata_0[0];
                self->event.setPhase(self->event.getPhase() + 1);
            }
            break;
        case 2:
            if (((grMadein*)((Stage*)self)->getGround(1))->isEndEntity() == true) {
                g_gfSceneRoot->removeResAnmScn();
                ((Stage*)self)->registScnAnim((nw4r::g3d::ResFileData*)self->archive->getData(Data_Type_Scene, 2, 0xfffe), 0);
                ((grMadein*)((Stage*)self)->getGround(1))->setMotionDetails(0, 0, 0, 0, 2);
                ((grMadein*)((Stage*)self)->getGround(1))->startEntity();
                self->event.setPhase(self->event.getPhase() + 1);
            }
            break;
        case 3:
            if (((grMadein*)((Stage*)self)->getGround(1))->isEndEntity() == true) {
                g_gfSceneRoot->removeResAnmScn();
                ((Stage*)self)->registScnAnim((nw4r::g3d::ResFileData*)self->archive->getData(Data_Type_Scene, 3, 0xfffe), 0);
                ((grMadein*)((Stage*)self)->getGround(1))->setMotionDetails(0, 0, 0, 0, 3);
                ((grMadein*)((Stage*)self)->getGround(1))->startEntity();
                self->event.setPhase(self->event.getPhase() + 1);
                ((stMelee*)self)->playSeBasic((SndID)0x1bd4, lbl_55_rodata_0[0]);
            }
            break;
        case 4:
            if (((grMadein*)((Stage*)self)->getGround(1))->isEndEntity() == true) {
                g_gfSceneRoot->removeResAnmScn();
                ((Stage*)self)->registScnAnim((nw4r::g3d::ResFileData*)self->archive->getData(Data_Type_Scene, 0, 0xfffe), 0);
                ((grMadein*)((Stage*)self)->getGround(1))->setMotionDetails(0, 0, 0, 0, 0);
                ((grMadein*)((Stage*)self)->getGround(1))->startEntityAutoLoop();
                self->event.end();
            }
            break;
        }
        self->event.update(dt);
    }
}
}