#pragma force_active on

#include <gr/gr_tengan_event.h>
#include <snd/snd_system.h>

struct StMadeinState {
    char pad0[0x330];
    grTenganEvent event;        /* 0x330 */
    char pad1[0x760 - 0x330 - sizeof(grTenganEvent)];
    Vec3f pos[4];               /* 0x760 */
    Vec3f rot[4];               /* 0x790 */
    Vec3f scale[4];             /* 0x7C0 */
    float t;                    /* 0x7F0 */
    s32 groundIndex;            /* 0x7F4 */
};

extern "C" {
extern const float lbl_65_rodata_0[];
extern s32 lbl_805A01D8;

void mtBezierCurve__FfP5Vec3fP5Vec3f(float t, Vec3f* points, Vec3f* out);
s32 isEvent__13grTenganEventCFv(const void* self);
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setRot__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setScale__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void* getGround__5StageFi(void* self, s32 index);
void setMotion__8grMadeinFUl(void* self, u32 motion);
void startEntity__8grMadeinFv(void* self);
void endEntity__8grMadeinFv(void* self);
void cmReqQuake__FiP5Vec3f(s32 id, Vec3f* offset);
void cmRemoveQuake__Fi(s32 id);
void playSeBasic__7stMeleeF5SndIDf(void* self, s32 id, float vol);
void fn_800790FC(s32 a, s32 b);

void fn_65_2104(StMadeinState* self, float dt) {
    const float* rd = lbl_65_rodata_0;
    float f31 = rd[0x80 / 4];
    Vec3f sp2C, sp20, sp14, sp8;

    if (isEvent__13grTenganEventCFv(&self->event) != 0) {
        switch (self->event.getPhase()) {
        case 0:
            self->t = rd[0];
            self->pos[0].m_x = rd[0];
            self->pos[0].m_y = f31;
            self->pos[0].m_z = rd[0];
            self->pos[1].m_x = rd[0];
            self->pos[1].m_y = f31;
            self->pos[1].m_z = rd[0];
            self->pos[2].m_x = rd[0];
            self->pos[2].m_y = f31;
            self->pos[2].m_z = rd[0];
            self->pos[3].m_x = rd[0];
            self->pos[3].m_y = f31;
            self->pos[3].m_z = rd[0];
            self->rot[0].m_x = rd[0];
            self->rot[0].m_y = rd[0];
            self->rot[0].m_z = rd[0];
            self->rot[1].m_x = rd[0];
            self->rot[1].m_y = rd[0];
            self->rot[1].m_z = rd[0];
            self->rot[2].m_x = rd[0];
            self->rot[2].m_y = rd[0];
            self->rot[2].m_z = rd[0];
            self->rot[3].m_x = rd[0];
            self->rot[3].m_y = rd[0];
            self->rot[3].m_z = rd[0];
            self->scale[0].m_x = rd[8];
            self->scale[0].m_y = rd[8];
            self->scale[0].m_z = rd[8];
            self->scale[1].m_x = rd[4];
            self->scale[1].m_y = rd[4];
            self->scale[1].m_z = rd[4];
            self->scale[2].m_x = rd[4];
            self->scale[2].m_y = rd[4];
            self->scale[2].m_z = rd[4];
            self->scale[3].m_x = rd[4];
            self->scale[3].m_y = rd[4];
            self->scale[3].m_z = rd[4];
            mtBezierCurve__FfP5Vec3fP5Vec3f(rd[0], self->pos, &sp2C);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->rot, &sp20);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->scale, &sp14);
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp2C);
            setRot__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp20);
            setScale__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp14);
            setMotion__8grMadeinFUl(getGround__5StageFi(self, self->groundIndex + 0x53), 0U);
            startEntity__8grMadeinFv(getGround__5StageFi(self, self->groundIndex + 0x53));
            self->event.setPhase(1);
            if (g_sndSystem->getBGMId() == 0x27A1U) {
                fn_800790FC(lbl_805A01D8, 0);
                playSeBasic__7stMeleeF5SndIDf(self, 0x1CA2, rd[0]);
            }
            break;
        case 1:
            self->t += rd[33] * dt;
            if (self->t >= rd[4]) {
                self->t = rd[4];
            }
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->pos, &sp2C);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->rot, &sp20);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->scale, &sp14);
            setScale__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp14);
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp2C);
            setRot__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp20);
            if (rd[4] == self->t) {
                self->event.setPhase(2);
                self->t = rd[0];
                sp8.m_x = rd[0];
                sp8.m_y = rd[0];
                sp8.m_z = rd[0];
                cmReqQuake__FiP5Vec3f(3, &sp8);
                return;
            }
            break;
        case 2:
            cmRemoveQuake__Fi(1);
            self->event.setPhase(3);
            return;
        case 3:
            self->t += rd[34] * dt;
            if (self->t >= rd[4]) {
                self->t = rd[4];
            }
            if (rd[4] == self->t) {
                self->event.setPhase(4);
                self->pos[0].m_y = f31;
                self->t = rd[0];
                self->pos[0].m_x = rd[0];
                self->pos[0].m_z = rd[0];
                self->pos[1].m_x = rd[0];
                self->pos[1].m_y = f31;
                self->pos[1].m_z = rd[0];
                self->pos[2].m_x = rd[0];
                self->pos[2].m_y = f31;
                self->pos[2].m_z = rd[0];
                self->pos[3].m_x = rd[0];
                self->pos[3].m_y = f31;
                self->pos[3].m_z = rd[0];
                self->rot[0].m_x = rd[0];
                self->rot[0].m_y = rd[0];
                self->rot[0].m_z = rd[0];
                self->rot[1].m_x = rd[0];
                self->rot[1].m_y = rd[0];
                self->rot[1].m_z = rd[0];
                self->rot[2].m_x = rd[0];
                self->rot[2].m_y = rd[0];
                self->rot[2].m_z = rd[0];
                self->rot[3].m_x = rd[0];
                self->rot[3].m_y = rd[0];
                self->rot[3].m_z = rd[0];
                return;
            }
            break;
        case 4:
            self->t += rd[33] * dt;
            if (self->t >= rd[4]) {
                self->t = rd[4];
            }
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->pos, &sp2C);
            mtBezierCurve__FfP5Vec3fP5Vec3f(self->t, self->rot, &sp20);
            setPos__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp2C);
            setRot__9grGimmickFP5Vec3f(getGround__5StageFi(self, self->groundIndex + 0x53), &sp20);
            if (rd[4] == self->t) {
                self->t = rd[0];
                self->event.end();
                endEntity__8grMadeinFv(getGround__5StageFi(self, self->groundIndex + 0x53));
            }
            break;
        }
    }
}
}
