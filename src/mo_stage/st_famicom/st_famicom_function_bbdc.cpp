#include <types.h>
#include <nw4r/g3d/g3d_scnmdlsmpl.h>
#include <it/it_manager.h>
#include <so/so_external_value_accesser.h>

#pragma force_active off
namespace {
#define PSVECScale LocalScale
#define PSVECNormalize LocalNormalize
#define PSVECAdd LocalAdd
#define PSVECDotProduct LocalDot
#include <../src/revolution/MTX/vec.c>
#undef PSVECDotProduct
#undef PSVECAdd
#undef PSVECNormalize
#undef PSVECScale
}
#pragma force_active on

extern "C" const float lbl_68_rodata_D0[];
extern "C" void fn_27_263984(void*, float);

struct Entry {
    float x, y, z;
    float rx, ry, rz;
    u8 flag;
    char pad[15];
};

extern "C" void fn_68_BBDC(char* self) {
    const float* rd = lbl_68_rodata_D0;
    char* p = self + 0xd0;

    if (p != 0) {
        nw4r::g3d::ScnMdlSimple* m =
            *(nw4r::g3d::ScnMdlSimple**)(*(char**)(self + 0x44));

        if (m != 0) {
            if (m->m_calcWorldCallBack == 0) {
                *(int*)(p + 0xc) = 0;
                *(int*)(*(char**)(p + 4)) = *(int*)(self + 0xc4);
                m->m_calcWorldCallBack = (nw4r::g3d::ICalcWorldCallBack*)p;
                m->EnableScnMdlCallbackTiming(1);
                m->m_nodeIndex = (short)*(int*)(*(char**)(p + 4));
            }

            if (*(Entry**)(self + 0x178) != 0) {
                nw4r::math::VEC3 pos;
                Entry* e = &(*(Entry**)(self + 0x178))[*(u8*)(self + 0x175)];
                pos.x = e->x;
                pos.y = e->y;
                pos.z = e->z;
                pos.y += rd[15];
                *(nw4r::math::VEC3*)(*(char**)(p + 4) + 8) = pos;

                e = &(*(Entry**)(self + 0x178))[*(u8*)(self + 0x175)];
                *(nw4r::math::VEC3*)(*(char**)(p + 4) + 0x14) =
                    *(nw4r::math::VEC3*)&e->rx;

                nw4r::math::VEC3 scaled;
                LocalScale((const Vec*)(self + 0x1b4), (Vec*)&scaled, rd[19]);
                *(nw4r::math::VEC3*)(*(char**)(p + 4) + 0x20) = scaled;

                if (*(int*)(self + 0x1a8) != 0) {
                    itManager* mgr = itManager::getInstance();
                    if (mgr == 0)
                        return;

                    BaseItem* item =
                        mgr->getItemFromInstanceId(*(int*)(self + 0x1a8));
                    if (item == 0)
                        return;

                    if (item->isHaved() == 1)
                        *(u8*)(self + 0x150) = 0xe;

                    Vec3f itemPos = soExternalValueAccesser::getPos(item);
                    e = &(*(Entry**)(self + 0x178))[*(u8*)(self + 0x175)];
                    e->x = itemPos.m_x;
                    e->y = itemPos.m_y;
                    e->z = itemPos.m_z;

                    e = &(*(Entry**)(self + 0x178))[*(u8*)(self + 0x175)];
                    e->y -= rd[15];
                }

                e = &(*(Entry**)(self + 0x178))[*(u8*)(self + 0x175)];
                if (e->flag == 1)
                    fn_27_263984(*(void**)(self + 0x14c), rd[1]);
                else
                    fn_27_263984(*(void**)(self + 0x14c), rd[12]);
            }
        }
    }
}
