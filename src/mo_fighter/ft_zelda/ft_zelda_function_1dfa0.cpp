#include <so/so_module_accesser.h>
#include <mt/mt_vector.h>
#include <nw4r/math/math_types.h>
#pragma force_active on

struct ZeldaNodes {
    u32 node[4];
};

struct ZeldaConstants {
    ZeldaNodes nodes;
    float zero;
    float one;
};

extern "C" {
extern const ZeldaConstants lbl_104_rodata_F0;
void fn_104_1E33C(Vec3f*, const Vec3f*);
}

extern "C" void fn_104_1DFA0(void*, soModuleAccesser* accesser) {
    int i;
    soWorkManageModule* work =
        accesser->m_enumerationStart->m_workManageModule;
    soCollisionAttackModule* attack =
        accesser->m_enumerationStart->m_collisionAttackModule;
    soLinkModule* link =
        accesser->m_enumerationStart->m_linkModule;

    ZeldaNodes nodes = {{3, 5, 7, 9}};
    Vec3f position =
        accesser->m_enumerationStart->m_postureModule->getPos();
    float lr = accesser->m_enumerationStart->m_postureModule->getLr();

    if (link->isLink(6)) {
        if (work->isFlag(0x22000016)) {
            for (i = 0; i < 4; ++i) {
                if (!attack->isAttack(i, false)) {
                    attack->set(i, 0);
                }
            }
            work->offFlag(0x22000016);
        }

        bool fixed = work->isFlag(0x22000015);
        Vec3f target;
        Vec3f difference;
        Vec3f offset;

        if (fixed) {
            Vec3f raw =
                accesser->m_enumerationStart->m_modelModule
                    ->getNodeGlobalPosition(30, false);
            fn_104_1E33C(&target, &raw);
        }

        for (i = 0; i < 4; ++i) {
            if (attack->isAttack(i, false)) {
                if (!fixed) {
                    Vec3f raw = link->getParentModelNodeGlobalPosition(
                        6, nodes.node[i], true);
                    fn_104_1E33C(&target, &raw);
                }

                target.m_z = 0.0f;
                Vec3fSub(&difference, &target, &position);

                float y = difference.m_y;
                offset.m_x = 0.0f;
                offset.m_y = y;
                offset.m_z = difference.m_x * lr;

                if (0.0f !=
                    accesser->m_enumerationStart->m_postureModule->getScale()) {
                    float scale =
                        accesser->m_enumerationStart->m_postureModule->getScale();
                    scale = 1.0f / scale;
                    nw4r::math::VEC3Scale(
                        reinterpret_cast<nw4r::math::VEC3*>(&offset),
                        reinterpret_cast<const nw4r::math::VEC3*>(&offset),
                        scale);
                }

                attack->setOffset(i, &offset);
                work->setFloat(target.m_x, i + 0x21000006);
                work->setFloat(target.m_y, i + 0x2100000A);
            }
        }
    } else {
        for (i = 0; i < 4; ++i) {
            if (attack->isAttack(i, false)) {
                attack->clear(i);
                work->onFlag(0x22000016);
            }
        }
    }
}
