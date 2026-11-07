#include <ft/ft_common_data_accesser.h>
#include <it/it_manager.h>
#include <gf/gf_module.h>
#include <types.h>
#pragma force_active on

struct Node {
    Node* next;
    char pad04[0x14];
    int key;
    char value[0x14];
    unsigned char type;
    unsigned char id;
    unsigned char kind;
    unsigned char flags : 7;
    unsigned char other : 1;
};
struct Owner { char pad[0x1094]; Node* head; };
struct ItKindTable { itKind* kinds; s32 count; };
struct FtDataWithTable { u8 pad[0x60]; ItKindTable* table; };
extern "C" gfModuleManager* lbl_805A0038;
extern "C" itManager* lbl_27_bss_6A34;
extern "C" const char* lbl_27_rodata_1320[];
extern "C" unsigned int lbl_27_rodata_1C60[];
extern "C" unsigned int lbl_27_rodata_1D3C[];
class sndSystem;
extern sndSystem* g_sndSystem;
extern "C" int fn_80073D08(sndSystem*, unsigned int);

inline Node* findNode(Owner* self, int id, int flags, int key, unsigned int type, int kind) {
    Node* n = self->head;
    while (n) {
        if ((n->id == 0xFF || n->id == id) &&
            (n->key == -1 || n->key == key) &&
            (n->type == 0xFF || n->type == type) &&
            (n->kind == 0xFF || n->kind == kind) &&
            n->flags == flags) return n;
        n = n->next;
    }
    return 0;
}
extern "C" int fn_27_143B54(Owner* self, ftKind key, int id, int kind, int flags, unsigned int type, unsigned int sound) {
    switch (flags) {
    case 0: {
        const char* name = lbl_27_rodata_1320[key];
        if (name && !lbl_805A0038->isLoaded(name)) return 0;
        return 1;
    }
    case 1: {
        if (!findNode(self, 0xff, flags, key, type, 0xff)) return 0;
        FtDataWithTable* data = reinterpret_cast<FtDataWithTable*>(g_ftCommonDataAccesser.getData(key));
        if (data->table != NULL) {
            for (s32 i = 0; i < data->table->count; i++) {
                if (lbl_27_bss_6A34 != NULL) {
                    if (!itManager::getInstance()->isCompItemKindArchive(data->table->kinds[i], 0, true)) {
                        itManager::getInstance()->preloadItemKindArchive(data->table->kinds[i], 0, (itArchive::Type)0, true);
                        return 0;
                    }
                }
            }
        }
        return 1;
    }
    case 3:
        if (sound == 1) return fn_80073D08(g_sndSystem, lbl_27_rodata_1C60[key]);
        return 1;
    case 2:
        if (sound == 1) return fn_80073D08(g_sndSystem, lbl_27_rodata_1C60[28]);
        return 1;
    case 9:
        if (sound == 1) return fn_80073D08(g_sndSystem, lbl_27_rodata_1D3C[key]);
        return 1;
    case 4: case 5: case 6: case 7: case 8:
    case 10: case 11: case 12: case 13: case 14:
        return findNode(self, id, flags, key, type, kind) != NULL;
    default: return 0;
    }
}