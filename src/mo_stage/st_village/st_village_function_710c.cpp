#include <it/it_manager.h>
#include <it/item.h>
#include <snd/snd_3d_generator.h>
#include <mt/mt_vector.h>
#pragma force_active on

extern float lbl_70_rodata_EC;
extern float lbl_70_rodata_F0;

#define V1(n) virtual void unused##n();
#define V2(n) V1(n##a) V1(n##b)
#define V4(n) V2(n##a) V2(n##b)
#define V8(n) V4(n##a) V4(n##b)
#define V16(n) V8(n##a) V8(n##b)
#define V32(n) V16(n##a) V16(n##b)
#define V64(n) V32(n##a) V32(n##b)

struct Ground_base {
    char pad[0x3c];
};

struct Ground : Ground_base {
    V32(a) V16(b)
    virtual void getNodePosition(Vec3f* pos, u32 nodeIndex, u32 unk);
    V64(c) V8(d) V2(e)
    virtual void fn_70_7838();
};

extern "C" void fn_70_710C(Ground* self) {
    Vec3f pos;
    if (*(u8*)((char*)self + 0x1e9) == 1) {
        self->getNodePosition(&pos, 0, *(u32*)((char*)self + 0xc4));
        snd3DGenerator* gen = (snd3DGenerator*)((char*)self + 0x200);
        gen->setPos(&pos);
        if (*(int*)((char*)self + 0x1e0) != 0) {
            itManager* mgr = itManager::getInstance();
            if (mgr != 0) {
                BaseItem* item = mgr->getItemFromInstanceId(*(int*)((char*)self + 0x1e0));
                if (item != 0) {
                    self->getNodePosition(&pos, 0, *(u32*)((char*)self + 0x1e4));
                    pos.m_y = pos.m_y - lbl_70_rodata_EC;
                    pos.m_z = pos.m_z + lbl_70_rodata_F0;
                    item->warp(&pos);
                }
            }
        }
    } else {
        self->fn_70_7838();
        if (*(int*)((char*)self + 0x14c) != 0) {
            *(u8*)((char*)self + 0x1e9) = 1;
        }
    }
}
