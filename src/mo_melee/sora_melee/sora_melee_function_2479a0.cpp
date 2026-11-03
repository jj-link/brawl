#include <it/it_manager.h>
#include <ft/ft_manager.h>
#include <st/stage.h>
#include <ec/ec_mgr.h>
#pragma force_active on

struct Rodata3FF0 { float zero, one, half; };
extern "C" {
extern const Rodata3FF0 lbl_27_rodata_3FF0;
extern Stage* lbl_27_bss_5668;
void fn_27_247518(void*);
int fn_27_2A3EC8(itManager*, int);
int fn_27_2A5BB4(itManager*, int, int);
BaseItem* fn_27_2A66B8(itManager*, Vec3f*, Vec3f*, float, itKind, u32, int, int, soResourceModule*, u8, int, int, int, int);
float randf__Fv();
int getItemNum__9itManagerF6itKind(itManager*, itKind);
}

extern "C" void fn_27_2479A0(unsigned char* self) {
    const Rodata3FF0* values = &lbl_27_rodata_3FF0;
    if (self[0x43] != 1 && self[0x42] != 1 && self[0x40] != 0) {
        itManager* mgr = itManager::getInstance();
        switch ((*(unsigned char**)(self + 0x44))[0x10]) {
        case 0xaf:
        if (self[0x78] == 0 && mgr->isCompItemKindArchive((itKind)0x86, 0, true)) {
            int owner = -1;
            ftManager* fm = g_ftManager;
            for (int i = 0; i < 7; ++i) {
                Fighter* fighter = fm->getFighter(fm->getEntryId(i), -1);
                if (fighter && fighter->getFtKind() == (ftKind)0x2c) {
                    owner = fighter->m_taskId;
                    break;
                }
            }
            Vec3f pos;
            lbl_27_bss_5668->getRandItemPos(&pos);
            BaseItem* item = fn_27_2A66B8(mgr, &pos, &pos, values->one, (itKind)0x86, 0, -1, owner, 0, 0, 0xffff, 0, 0xffff, 0x14);
            if (item) {
                self[0x78] = 1;
                item->setVanishMode(false);
            }
        }
        default: break;
        }
        if (*(float*)(self + 0x70) > values->zero && fn_27_2A3EC8(mgr, 0x37)) {
            *(float*)(self + 0x70) -= values->one;
            if (*(float*)(self + 0x70) <= values->zero) {
                *(float*)(self + 0x70) = *(float*)(self + 0x74) * (values->half + values->half * randf__Fv());
                if (!fn_27_2A5BB4(mgr, 0x37, 1) && getItemNum__9itManagerF6itKind(mgr, (itKind)0x37) <= 0) {
                    Vec3f pos;
                    lbl_27_bss_5668->getRandItemPos(&pos);
                    g_ecMgr->setEffect((EfID)0x37, &pos);
                    mgr->createItem(&pos, values->one, (itKind)0x37, 0, -1, 0, 0, 0xffff, 0, 0xffff);
                }
            }
        }
        fn_27_247518(self);
    }
}
