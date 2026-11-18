#include <mt/mt_vector.h>
#include <it/it_manager.h>
#include <it/item.h>
#include <types.h>
#pragma force_active on

struct Stage_self {
    char _0[0x33c];
    float f33c;
    char _340[0x578 - 0x340];
    float f578;
    float f57c;
    float f580;
    float f584;
    char _588[0x590 - 0x588];
    float f590;
    char _594[0x5ac - 0x594];
    float f5ac;
    char _5b0[0x5d5 - 0x5b0];
    s8 b5d5;
    u8 b5d6;
    char _5d7;
    float f5d8;
    float f5dc;
    float f5e0;
    u32 i5e4;
    u32 i5e8;
    u32 i5ec;
};

typedef void (*ItemVFunc2)(BaseItem*, int, float);

extern "C" {
extern const float lbl_88_rodata_0[];
unsigned int fn_800516F0(void);
itManager* getInstance__9itManagerFv(void);
BaseItem* createItem__9itManagerFP5Vec3fP5Vec3ff6itKindUliP16soResourceModuleUciii(
    itManager* it, Vec3f* safePos, Vec3f* pos, float lr, itKind kind,
    u32 variation, int ownerTaskId, soResourceModule* mod, u8 groupNo,
    int brresId, int texResIndex, int texResId);
}

extern "C" void fn_88_2F18(Stage_self* self)
{
    BaseItem* item;
    const float* c = lbl_88_rodata_0;
    Vec3f pos, safePos;
    float var;
    float extent, ten, scale, limit, zero, upper, max, rate;

    switch (self->b5d5) {
    case 2:
        rate = c[26];
        max = c[32];
        if (self->f5ac < max * rate || (upper = c[36], self->f5ac > upper * rate))
            return;

        zero = c[0];
        ten = c[3];
        scale = c[39];
        extent = c[40];
        limit = c[38];
        Stage_self* slot;
        u8 cnt = 0;
        u8 i = 0;
        while (i != 3) {
            slot = (Stage_self*)((char*)self + (i << 2));
            float f2 = slot->f5d8;
            if (zero == f2) {
                cnt++;
                i++;
                continue;
            }
            if (f2 < self->f5ac + limit * rate) {
                if (self->f590 > zero)
                    var = upper + ((scale * (f2 - self->f5ac)) / max) / rate;
                else
                    var = self->f578 + (ten * f2) / rate;

                pos.m_x = var;
                pos.m_y = self->f33c - extent;
                pos.m_z = self->f580;
                safePos.m_x = var;
                safePos.m_y = extent + self->f33c;
                safePos.m_z = self->f580;
                if (self->f590 > zero) {
                    pos.m_x = (float)(double)var - self->f584;
                    safePos.m_x = (float)(double)var - self->f584;
                }

                u16 variation = fn_800516F0();
                itManager* mgr = itManager::getInstance();
                item = mgr->createItem(&safePos, &pos, c[22],
                                                   (itKind)0x17, variation, -1,
                                                   NULL, 0, 0xffff, 0, 0xffff);
                if (item == NULL)
                    return;

                item->action(0, c[22]);

                slot->f5d8 = zero;
                if (self->i5e4 == 0)
                    self->i5e4 = *(u32*)((char*)item + 0x8bc);
                else if (self->i5e8 == 0)
                    self->i5e8 = *(u32*)((char*)item + 0x8bc);
                else if (self->i5ec == 0)
                    self->i5ec = *(u32*)((char*)item + 0x8bc);
            }
            i++;
        }

        if (cnt == 3) {
            self->b5d5 = 0;
            self->b5d6 = self->b5d6 + 1;
        }
    }
}
