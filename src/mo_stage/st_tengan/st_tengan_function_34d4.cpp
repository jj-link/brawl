#pragma force_active on

#include <types.h>
#include <ec/ec_mgr.h>
#include <gr/gr_tengan_event.h>
#include <mt/mt_vector.h>
#include <nw4r/g3d/g3d_scnmdl.h>

struct StMelee {
    char pad0[0x204];
    s32 unk204;
    char pad208[0x14];
    grTenganEvent ev21C;
    grTenganEvent ev2C8;
    grTenganEvent ev374;
    char pad420[0x828 - 0x420];
    grTenganEvent ev828;
    char pad8D4[0xCDC - 0x8D4];
    grTenganEvent evCDC;
    grTenganEvent evD88;
    Vec3f pos;
    char padE40[0x14];
    s8 unkE54;
    char padE55[0xEAC - 0xE55];
    s32 unkEAC;
};

extern "C" {
extern const float lbl_60_rodata_0[];
extern char lbl_60_data_0[];

void* getGround__5StageFi(void* self, s32 index);
void setMotion__8grMadeinFUl(void* self, u32 motion);
void startEntity__8grMadeinFv(void* self);
void startEntityAutoLoop__8grMadeinFv(void* self);
void endEntity__8grMadeinFv(void* self);
u32 isEndEntity__8grMadeinFv(void* self);
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* pos);
void cmReqQuake__FiP5Vec3f(s32 id, Vec3f* offset);
u32 fn_27_2793BC(void* ground, f32 value);
s32 playSeBasic__7stMeleeF5SndIDf(void* self, s32 sndID, f32 pan);
}

extern "C" s32 fn_60_34D4(StMelee* self, f32 dt) {
    u32 h;
    const float* c = lbl_60_rodata_0;
    char* data = lbl_60_data_0;
    u32 idx = 0;
    Vec3f pos;
    Vec3f q2;
    Vec3f q1;
    Vec3f q0;

    switch (self->unk204) {
    case 0:
        idx = 3;
        break;
    case 1:
        idx = 0x12;
        break;
    case 2:
        idx = 0x13;
        break;
    }

    switch (self->ev21C.getPhase()) {
    case 0:
        if (self->ev21C.isReadyEnd() == 1) {
            pos = self->pos;
            g_ecMgr->setDrawPrio(1);
            h = g_ecMgr->setEffect((EfID)0x460002);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setPos(h, &self->pos);
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C3B, c[0]);
            self->ev21C.setPhase(1);
            self->ev21C.m_manualFramesLeft = c[0];
        }
        break;
    case 1:
        self->ev21C.m_manualFramesLeft = self->ev21C.m_manualFramesLeft + dt;
        if (self->ev21C.m_manualFramesLeft >= c[0xA8 / 4]) {
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C3C, c[0]);
            self->ev21C.setPhase(2);
        }
        break;
    case 2:
        self->ev21C.m_manualFramesLeft = self->ev21C.m_manualFramesLeft + dt;
        if (self->ev21C.m_manualFramesLeft >= c[0xAC / 4]) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, idx), 3);
            startEntity__8grMadeinFv(getGround__5StageFi(self, idx));
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, idx), &self->pos);
            if (self->unk204 == 1) {
                g_ecMgr->setDrawPrio(1);
                h = g_ecMgr->setEffect((EfID)0x460003);
                void* g1 = getGround__5StageFi(self, idx);
                g_ecMgr->setParent(h, **(nw4r::g3d::ScnMdl***)((char*)g1 + 0x44), data + 0x390, false);
                h = g_ecMgr->setEffect((EfID)0x460003);
                void* g2 = getGround__5StageFi(self, idx);
                g_ecMgr->setParent(h, **(nw4r::g3d::ScnMdl***)((char*)g2 + 0x44), data + 0x3AC, false);
                g_ecMgr->setDrawPrio(-1);
            }
            if (self->unk204 == 0) {
                g_ecMgr->setDrawPrio(1);
                h = g_ecMgr->setEffect((EfID)0x460003);
                void* g3 = getGround__5StageFi(self, idx);
                g_ecMgr->setParent(h, **(nw4r::g3d::ScnMdl***)((char*)g3 + 0x44), data + 0x3C8, false);
                h = g_ecMgr->setEffect((EfID)0x460003);
                void* g4 = getGround__5StageFi(self, idx);
                g_ecMgr->setParent(h, **(nw4r::g3d::ScnMdl***)((char*)g4 + 0x44), data + 0x3E4, false);
                g_ecMgr->setDrawPrio(-1);
            }
            self->ev21C.setPhase(3);
            self->unkEAC = 0;
        }
        break;
    case 3:
        if (idx != 0x13) {
            switch (self->unkEAC) {
            case 0:
                if (fn_27_2793BC(getGround__5StageFi(self, idx), c[0x68 / 4]) == 1) {
                    q2.m_x = c[0];
                    q2.m_y = c[0];
                    q2.m_z = c[0];
                    cmReqQuake__FiP5Vec3f(3, &q2);
                    self->unkEAC += 1;
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1C3D, c[0]);
                }
                break;
            case 1:
                if (fn_27_2793BC(getGround__5StageFi(self, idx), c[0x5C / 4]) == 1) {
                    q1.m_x = c[0];
                    q1.m_y = c[0];
                    q1.m_z = c[0];
                    cmReqQuake__FiP5Vec3f(3, &q1);
                    self->unkEAC += 1;
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1C3E, c[0]);
                }
                break;
            case 2:
                if (fn_27_2793BC(getGround__5StageFi(self, idx), c[0x40 / 4]) == 1) {
                    q0.m_x = c[0];
                    q0.m_y = c[0];
                    q0.m_z = c[0];
                    cmReqQuake__FiP5Vec3f(3, &q0);
                    self->unkEAC += 1;
                    playSeBasic__7stMeleeF5SndIDf(self, 0x1C3D, c[0]);
                }
                break;
            }
        }
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, idx)) == 1) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, idx), 0);
            startEntityAutoLoop__8grMadeinFv(getGround__5StageFi(self, idx));
            self->ev21C.setPhase(0xA);
            self->ev374.end();
            self->ev374.start();
            self->ev2C8.end();
            self->ev2C8.start();
        }
        break;
    case 10:
        if (self->ev374.isReadyEnd() == 1 &&
            isEndEntity__8grMadeinFv(getGround__5StageFi(self, idx)) == 1 &&
            self->ev828.isEvent() == 0 &&
            self->evCDC.isEvent() == 0 &&
            self->evD88.isEvent() == 0) {
            setMotion__8grMadeinFUl(getGround__5StageFi(self, idx), 4);
            startEntity__8grMadeinFv(getGround__5StageFi(self, idx));
            self->ev21C.setPhase(0xB);
            self->ev2C8.end();
            self->unkE54 = 0;
        }
        break;
    case 11:
        if (isEndEntity__8grMadeinFv(getGround__5StageFi(self, idx)) == 1) {
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C3F, c[0]);
            g_ecMgr->setDrawPrio(1);
            u32 h2 = g_ecMgr->setEffect((EfID)0x460004);
            g_ecMgr->setDrawPrio(-1);
            g_ecMgr->setPos(h2, &self->pos);
            self->ev21C.setPhase(0xC);
            self->ev21C.m_manualFramesLeft = c[0];
        }
        break;
    case 12:
        self->ev21C.m_manualFramesLeft = self->ev21C.m_manualFramesLeft + dt;
        if (self->ev21C.m_manualFramesLeft >= c[0x50 / 4]) {
            playSeBasic__7stMeleeF5SndIDf(self, 0x1C40, c[0]);
            endEntity__8grMadeinFv(getGround__5StageFi(self, idx));
            self->ev21C.setPhase(0xD);
        }
        break;
    case 13:
        self->ev2C8.end();
        self->ev374.end();
        self->ev21C.end();
        self->ev21C.start();
        break;
    }

    return 0;
}