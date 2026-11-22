#include <types.h>
#include <st/st_melee.h>
#include <gr/gr_gimmick.h>
#include <gr/gr_tengan_event.h>
#include <ef/ef_screen.h>

#pragma force_active on

struct PlatformEntry {
    unsigned char state;
    char pad01[3];
    float x;
    float y;
    char pad0c[8];
    float scale;
    float timer;
    grGimmick* ground;
};

struct CameraRect {
    u32 left;
    u32 right;
    u32 top;
    u32 bottom;
    CameraRect& operator=(const CameraRect& other) {
        __memcpy(&left, &other.left, 8);
        __memcpy(&top, &other.top, 8);
        return *this;
    }
};

struct CameraData {
    char pad[0x148];
    CameraRect rect;
};

extern "C" {
extern const float lbl_84_rodata_0[];
extern char lbl_84_data_0[];

void fn_84_3030(stMelee*);
void fn_84_2BF8(stMelee*);
void fn_84_3A08(stMelee*);
void fn_84_13D4(stMelee*, float);
void fn_84_3B28(stMelee*, void*, Vec3f*, float);
unsigned int fn_27_2249E0(stMelee*);
void fn_8005E3C8(efScreen*, unsigned char*, float);
CameraData* getInstance__16CameraControllerFv();
void fn_8009CEA8(CameraData*, CameraRect*);
}

#define FLD(T, off) (*reinterpret_cast<T*>(reinterpret_cast<char*>(self) + (off)))
#define ENT(c) (reinterpret_cast<PlatformEntry*>((c) + 0x220))

extern "C" void fn_84_E34(stMelee* self, float delta)
{
    const float* k;
    const char* names;
    names = lbl_84_data_0;
    k = lbl_84_rodata_0;

    unsigned char handle;
    GXColor initial;
    unsigned int colorBits;

    fn_84_3030(self);
    fn_84_2BF8(self);
    fn_84_3A08(self);

    if ((FLD(unsigned char, 0x1d8) >> 7) & 1) {
        FLD(float, 0x1dc) -= delta;
        if (FLD(float, 0x1dc) < k[0x28 / 4])
            FLD(float, 0x1dc) = k[0x28 / 4];

        if (k[0x28 / 4] == FLD(float, 0x1dc)) {
            if (((FLD(unsigned char, 0x1d8) >> 6) & 1U) == 1U) {
                initial.r = 0;
                initial.g = 0;
                initial.b = 0;
                initial.a = 255;
                FLD(float, 0x1dc) = k[0xfc / 4];
                FLD(unsigned char, 0x1d8) &= ~0x40;
                colorBits = *reinterpret_cast<unsigned int*>(&initial);
                FLD(unsigned char, 0x9f9) = static_cast<unsigned char>(
                    static_cast<unsigned int>(g_efScreen->requestFill(
                        k[0x100 / 4], 0, 0, reinterpret_cast<GXColor*>(&colorBits))) >> 24);
            } else {
                FLD(float, 0x1dc) = k[0xec / 4];
                FLD(unsigned char, 0x1d8) |= 0x40;
                handle = FLD(unsigned char, 0x9f9);
                fn_8005E3C8(g_efScreen, &handle, k[0x100 / 4]);
                FLD(signed char, 0x9f9) = -1;
            }
        }
    }

    char* cursor = reinterpret_cast<char*>(self);
    for (int i = 0; i < 20; ++i, cursor += 0x20) {
        Vec3f pos(ENT(cursor)->x, ENT(cursor)->y, k[0x28 / 4]);
        Vec3f scale;

        float size = k[0x104 / 4] * ENT(cursor)->scale;
        scale.m_x = size;
        scale.m_y = size;
        scale.m_z = size;

        ENT(cursor)->ground->setScale(&scale);
        ENT(cursor)->ground->setPos(&pos);

        if (((*reinterpret_cast<unsigned char*>(
                  reinterpret_cast<char*>(ENT(cursor)->ground) + 0x16c) >> 4) & 1U) == 1U &&
            ENT(cursor)->state == 1 && i != 0 && i != 6) {
            PlatformEntry* sel = &reinterpret_cast<PlatformEntry*>(reinterpret_cast<char*>(self) + 0x220)[i];
            sel->state = 2;
            FLD(short, 0x740) = 120;
            sel->timer = k[0x108 / 4];
            self->playSeBasic(static_cast<SndID>(0x3b), k[0x28 / 4]);
            break;
        }
    }

    Vec2f position;
    unsigned int j = 0;
    cursor = reinterpret_cast<char*>(self);
    do {
        if ((*reinterpret_cast<unsigned char*>(
                reinterpret_cast<char*>(self->getGround(j + 12)) + 0x16c) >> 4) & 1) {
            char* data = *reinterpret_cast<char**>(
                reinterpret_cast<char*>(self->getGround(j + 12)) + 0x160);
            position = *reinterpret_cast<Vec2f*>(data + 0x30);
            *reinterpret_cast<float*>(cursor + 0x200) += *reinterpret_cast<float*>(
                *reinterpret_cast<char**>(
                    reinterpret_cast<char*>(self->getGround(j + 12)) + 0x160) + 0x28);
            if (position.m_x > k[0x28 / 4])
                *reinterpret_cast<float*>(cursor + 0x1fc) = k[0x24 / 4] + position.m_x;
            else
                *reinterpret_cast<float*>(cursor + 0x1fc) = k[0x10c / 4] + position.m_x;
        }
        ++j;
        cursor += 0x18;
    } while (j < 2);

    reinterpret_cast<grTenganEvent*>(reinterpret_cast<char*>(self) + 0x7f0)->update(delta);
    reinterpret_cast<grTenganEvent*>(reinterpret_cast<char*>(self) + 0x744)->update(delta);
    fn_84_13D4(self, delta);

    Vec3f pos2;
    Vec3f node;
    CameraRect rect;
    Vec3f trainerPos;
    const Vec3f& gp = static_cast<grGimmick*>(self->getGround(0))->getPos();
    pos2.m_z = gp.m_z;
    pos2.m_x = k[0x110 / 4];
    pos2.m_y = gp.m_y + k[0x114 / 4];
    static_cast<grGimmick*>(self->getGround(11))->setPos(&pos2);

    node.m_x = k[0x28 / 4];
    node.m_y = k[0x28 / 4];
    node.m_z = k[0x28 / 4];

    self->getGround(5)->getNodePosition(&node, 0, names + 0x168);
    fn_84_3B28(self, reinterpret_cast<char*>(self) + 0x4d0, &node,
               FLD(float, 0x4b4) - k[0x118 / 4]);
    self->getGround(5)->getNodePosition(&node, 0, names + 0x170);
    fn_84_3B28(self, reinterpret_cast<char*>(self) + 0x5f0, &node,
               FLD(float, 0x4b4) - k[0x118 / 4]);

    rect = getInstance__16CameraControllerFv()->rect;
    float& bottom = *reinterpret_cast<float*>(&rect.bottom);

    if (FLD(unsigned char, 0x9f8) == 1) {
        FLD(float, 0x9f0) = bottom;
        FLD(unsigned char, 0x9f8) = 0;
    }

    bottom = self->getAcidHeight();
    if (bottom < FLD(float, 0x9f0))
        bottom = FLD(float, 0x9f0);
    fn_8009CEA8(getInstance__16CameraControllerFv(), &rect);

    if (fn_27_2249E0(self) == 1) {
        if (self->getAcidHeight() > FLD(float, 0x9f4) - k[0x9c / 4]) {
            FLD(float, 0x9f4) = k[0x9c / 4] + self->getAcidHeight();
        } else {
            FLD(float, 0x9f4) -= k[0x11c / 4];
            if (FLD(float, 0x9f4) < k[0x68 / 4])
                FLD(float, 0x9f4) = k[0xe4 / 4];
        }

        float y = FLD(float, 0x9f4);
        trainerPos.m_x = k[0x68 / 4];
        trainerPos.m_y = y;
        trainerPos.m_z = k[0xe8 / 4];
        static_cast<grGimmick*>(self->getGround(15))->setPos(&trainerPos);

        self->getGround(15)->getNodePosition(
            &(*reinterpret_cast<Vec3f**>(reinterpret_cast<char*>(self) + 0xbc))[0], 0, names + 0x178);
        self->getGround(15)->getNodePosition(
            &(*reinterpret_cast<Vec3f**>(reinterpret_cast<char*>(self) + 0xbc))[1], 0, names + 0x18c);
        self->getGround(15)->getNodePosition(
            &(*reinterpret_cast<Vec3f**>(reinterpret_cast<char*>(self) + 0xbc))[2], 0, names + 0x1a0);
        self->getGround(15)->getNodePosition(
            &(*reinterpret_cast<Vec3f**>(reinterpret_cast<char*>(self) + 0xbc))[3], 0, names + 0x1b4);
    }
}
