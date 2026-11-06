#pragma force_active on

#include <gr/gr_tengan_event.h>
#include <mt/mt_vector.h>
#include <types.h>

extern "C" {
extern const float lbl_65_rodata_0[];

u32 randi__Fl(s32 n);
void mtBezierCurve__FfP5Vec3fP5Vec3f(f32 t, Vec3f* points, Vec3f* out);
void setPos__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setRot__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setScale__9grGimmickFP5Vec3f(void* self, Vec3f* v);
void setMotion__8grMadeinFUl(void* self, u32 motion);
u32 isEndEntity__8grMadeinFv(void* self);
void endEntity__8grMadeinFv(void* self);
void fn_27_279250(void* self, s32 arg);
int playSeBasic__7stMeleeF5SndIDf(void* self, s32 sndID, f32 pan);
void cmReqQuake__FiP5Vec3f(s32 n, Vec3f* v);
void cmRemoveQuake__Fi(s32 n);
}

struct Stage {
    char pad0[0x488];
    grTenganEvent event;     /* 0x488 */
    char pad1[0x208];        /* 0x534 */
    s32 unk73C;              /* 0x73C */
    char pad2[0x20];         /* 0x740 */
    Vec3f posSpline[4];      /* 0x760 */
    Vec3f rotSpline[4];      /* 0x790 */
    Vec3f scaleSpline[4];    /* 0x7C0 */
    f32 t;                   /* 0x7F0 */
    char pad3[0x200];        /* 0x7F4 */
    s8 unk9F4;               /* 0x9F4 */
    char pad4[1];
    s8 unk9F6;               /* 0x9F6 */
    void* getGround(int index);
};

extern "C" void fn_65_2E70(Stage* arg0, f32 farg0) {
    const float* rd = lbl_65_rodata_0;
    Vec3f pos;
    Vec3f rot;
    Vec3f scale;

    if (arg0->event.isEvent()) {
        switch (arg0->event.getPhase()) {
        case 0: {
            f32 var_f31;
            arg0->event.setPhase(1);
            arg0->t = rd[0];
            if (arg0->unk73C != 0) {
                var_f31 = rd[0xCC / 4];
            } else {
                var_f31 = rd[0xD0 / 4];
            }
            arg0->unk9F4 = 1;
            arg0->unk9F6 = (s8) arg0->unk73C;

            u32 r = randi__Fl(2);
            if (r >= 1U) {
                r = 1U;
            }
            if ((s32) r == 0) {
                arg0->posSpline[0].m_x = var_f31;
                arg0->posSpline[0].m_y = rd[0xD4 / 4];
                arg0->posSpline[0].m_z = rd[0];
            } else {
                f32 neg = -var_f31;
                arg0->posSpline[0].m_y = rd[0x7C / 4];
                arg0->posSpline[0].m_x = neg;
                arg0->posSpline[0].m_z = rd[0];
            }

            r = randi__Fl(2);
            if (r >= 1U) {
                r = 1U;
            }
            if ((s32) r == 0) {
                arg0->posSpline[1].m_x = rd[0x6C / 4] * var_f31;
                arg0->posSpline[1].m_y = rd[0x70 / 4];
                arg0->posSpline[1].m_z = rd[0];
            } else {
                arg0->posSpline[1].m_x = rd[0x6C / 4] * -var_f31;
                arg0->posSpline[1].m_y = rd[0xD8 / 4];
                arg0->posSpline[1].m_z = rd[0];
            }

            r = randi__Fl(2);
            if (r >= 1U) {
                r = 1U;
            }
            if ((s32) r == 0) {
                arg0->posSpline[2].m_x = rd[0x6C / 4] * var_f31;
                arg0->posSpline[2].m_y = rd[0x70 / 4];
                arg0->posSpline[2].m_z = rd[0];
            } else {
                arg0->posSpline[2].m_x = rd[0x6C / 4] * -var_f31;
                arg0->posSpline[2].m_y = rd[0xD8 / 4];
                arg0->posSpline[2].m_z = rd[0];
            }

            arg0->posSpline[3].m_x = var_f31;
            arg0->posSpline[3].m_y = rd[0x7C / 4];
            arg0->posSpline[3].m_z = rd[0];

            arg0->rotSpline[0].m_x = rd[0];
            arg0->rotSpline[0].m_y = rd[0];
            arg0->rotSpline[0].m_z = rd[0xDC / 4];
            arg0->rotSpline[1].m_x = rd[0];
            arg0->rotSpline[1].m_y = rd[0];
            arg0->rotSpline[1].m_z = rd[0];
            arg0->rotSpline[2].m_x = rd[0];
            arg0->rotSpline[2].m_y = rd[0];
            arg0->rotSpline[2].m_z = rd[0];
            arg0->rotSpline[3].m_x = rd[0];
            arg0->rotSpline[3].m_y = rd[0];
            arg0->rotSpline[3].m_z = rd[0];

            arg0->scaleSpline[0].m_x = rd[0xC / 4];
            arg0->scaleSpline[0].m_y = rd[0xC / 4];
            arg0->scaleSpline[0].m_z = rd[0x8 / 4];
            arg0->scaleSpline[1].m_x = rd[0x8 / 4];
            arg0->scaleSpline[1].m_y = rd[0x8 / 4];
            arg0->scaleSpline[1].m_z = rd[0x8 / 4];
            arg0->scaleSpline[2].m_x = rd[0x10 / 4];
            arg0->scaleSpline[2].m_y = rd[0x10 / 4];
            arg0->scaleSpline[2].m_z = rd[0x10 / 4];
            arg0->scaleSpline[3].m_x = rd[0x10 / 4];
            arg0->scaleSpline[3].m_y = rd[0x10 / 4];
            arg0->scaleSpline[3].m_z = rd[0x10 / 4];

            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->posSpline, &pos);
            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->rotSpline, &rot);
            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->scaleSpline, &scale);
            setPos__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &pos);
            setRot__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &rot);
            setScale__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &scale);
            setMotion__8grMadeinFUl(arg0->getGround(arg0->unk73C + 0x4E), 0U);
            fn_27_279250(arg0->getGround(arg0->unk73C + 0x4E), 1);
            playSeBasic__7stMeleeF5SndIDf(arg0, 0x1CA8, rd[0]);
            break;
        }
        case 1: {
            f32 temp = arg0->t + rd[0xE0 / 4] * farg0;
            arg0->t = temp;
            if (temp >= rd[0x10 / 4]) {
                arg0->t = rd[0x10 / 4];
            }
            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->posSpline, &pos);
            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->rotSpline, &rot);
            mtBezierCurve__FfP5Vec3fP5Vec3f(arg0->t, arg0->scaleSpline, &scale);
            setPos__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &pos);
            setRot__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &rot);
            setScale__9grGimmickFP5Vec3f(arg0->getGround(arg0->unk73C + 0x4E), &scale);
            if (rd[0x10 / 4] == arg0->t) {
                arg0->event.setPhase(2);
                Vec3f q;
                q.m_x = rd[0];
                q.m_y = rd[0];
                q.m_z = rd[0];
                cmReqQuake__FiP5Vec3f(3, &q);
            }
            break;
        }
        case 2:
            if (isEndEntity__8grMadeinFv(arg0->getGround(arg0->unk73C + 0x4E)) == 1U) {
                endEntity__8grMadeinFv(arg0->getGround(arg0->unk73C + 0x4E));
                arg0->event.end();
                cmRemoveQuake__Fi(1);
                arg0->unk9F4 = 0;
            }
            break;
        }
    }
}
