#pragma force_active on

#include <gf/gf_3d_scene.h>
#include <mt/mt_vector.h>

extern "C" const float lbl_47_rodata_0[];
extern "C" void cmReqQuake__FiP5Vec3f(int, const Vec3f*);

struct MansionParams {
    float a0;
    float a4;
};

struct Mansion {
    char pad[0x9c];
    MansionParams* params;
    char pad2[0x208 - 0xa0];
    unsigned char state;
    char pad3[3];
    float timer;
    float frame;
    float timer2;
    char pad4[0x24c - 0x218];
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned char b4;
};

extern "C" void fn_47_F78(Mansion* self, float delta) {
    const float* data = lbl_47_rodata_0;
    MansionParams* p = self->params;
    if (p == NULL) return;

    self->timer -= delta;
    if (self->timer < data[0])
        self->timer = data[0];

    unsigned int flag = 1;

    switch (self->state) {
    case 0:
        self->b1 = 0;
        self->b2 = 0;
        self->b3 = 0;
        self->b4 = 0;
        self->timer2 = data[1];
        self->state = 1;
        break;

    case 1:
        if (self->b1 == 2 && self->b2 == 2 &&
            self->b3 == 2 && self->b4 == 2) {
            self->b1 = 3;
            self->b2 = 3;
            self->b3 = 3;
            self->b4 = 3;
            self->timer2 = data[0];
            self->timer = p->a0;
            self->state = 2;
        }
        break;

    case 2:
        if (data[0] == self->timer) {
            self->b1 = 4;
            flag = 0;
            self->b2 = 4;
            self->b3 = 4;
            self->b4 = 4;
            self->timer = p->a4;
            g_gfSceneRoot->setCurrentFrame(data[2]);
            self->state = 3;
        }
        break;

    case 3:
        if (data[0] == self->timer) {
            self->state = 0;
        } else {
            float val = data[1] - (self->timer / p->a4);
            if (val < data[0]) val = data[0];
            if (val > data[1]) val = data[1];
            self->timer2 = val;
            flag = 0;
            Vec3f pos(data[0], data[0], data[0]);
            cmReqQuake__FiP5Vec3f(1, &pos);
        }
        break;
    }

    if (flag == 1) {
        float frame_val = data[0];

        if (self->b1 == 2 && self->b3 == 2) {
            frame_val = data[3];
        } else if (self->b1 == 2 && self->b2 == 2) {
            frame_val = data[4];
        } else if (self->b3 == 2 && self->b4 == 2) {
            frame_val = data[5];
        } else if (self->b1 == 2) {
            frame_val = data[1];
        } else if (self->b3 == 2) {
            frame_val = data[6];
        }

        if (data[3] == frame_val && self->b2 == 2) {
            frame_val = data[7];
        } else if (data[3] == frame_val && self->b4 == 2) {
            frame_val = data[8];
        }

        if (self->b2 == 3 && self->b4 == 3) {
            frame_val = data[9];
        }

        g_gfSceneRoot->setCurrentFrame(frame_val);
        self->frame = data[0];
    } else {
        float frame = data[0];
        if (g_gfSceneRoot->m_anmScnRes)
            frame = g_gfSceneRoot->m_anmScnRes->GetFrame();

        if (frame < self->frame) {
            g_gfSceneRoot->setCurrentFrame(self->frame);
        } else {
            float newFrame = data[0];
            if (g_gfSceneRoot->m_anmScnRes)
                newFrame = g_gfSceneRoot->m_anmScnRes->GetFrame();
            self->frame = newFrame;
        }
    }
}
