#include <types.h>
#include <it/it_manager.h>
#include <so/so_archive_db.h>
#include <snd/snd_system.h>
#include <st/stage.h>

#pragma force_active on

struct ItSetupInfo {
    s32 w[7];
};

struct Self {
    s32 m_state;       // 0x00
    u8 m_flag;         // 0x04
    s32 m_id;          // 0x08
    s32 m_variant;     // 0x0C
    u32 m_archive10;   // 0x10
    u32 m_archive14;   // 0x14
    u32 m_archive18;   // 0x18
    u32 m_soundGroup;  // 0x1C
    s32 m_soundHandle; // 0x20
    s32 m_unk24;       // 0x24
    s32 m_timer;       // 0x28
    void* m_data;      // 0x2C
};

extern "C" {
extern ItSetupInfo lbl_27_bss_6A38;
extern void* lbl_27_bss_5668;
extern char lbl_27_data_790B0[];
extern char lbl_805A00C0[];
extern char g_HeapInfos[];
s32 fn_27_2A0D38(itManager* mgr, s32 id);
s32 fn_800455E0(void* mgr, s32 id);
s32 fn_800453AC(void* mgr, void* name, u32 heap, s32 a, s32 b, s32 c, s32 d, void* table, s32 flag);
u32 fn_80073D08(sndSystem* snd, u32 id);
s32 fn_80073D18(sndSystem* snd, u32 id);
int __cntlzw(unsigned int);
}

extern "C" Self* fn_27_2B1E80(Self* self, s32 state, s32 id, s32 variant, const char* nameA, const char* nameB, const char* nameC, s32 soundGroup) {
    ItSetupInfo info;
    s32 outBrres;
    s32 outParam;
    s32 hasNameC;
    s32 heapId;
    s32 r;

    self->m_data = lbl_27_data_790B0;
    self->m_state = state;
    self->m_flag = 0;
    self->m_id = id;
    self->m_variant = variant;
    self->m_archive10 = 0xFFFF;
    self->m_archive14 = 0xFFFF;
    self->m_archive18 = 0xFFFF;
    self->m_soundGroup = soundGroup;
    self->m_soundHandle = -1;
    self->m_unk24 = 0;
    self->m_timer = 0;

    itManager::getInstance();
    info = lbl_27_bss_6A38;
    hasNameC = 0;
    if (nameC != NULL && *nameC != 0) {
        hasNameC = 1;
    }

    r = fn_27_2A0D38(itManager::getInstance(), self->m_id);

    if (self->m_state == 3 && r != 4 && r != 6 && r != 7) {
        if (r == 1 || (u32)(r - 6) <= 1U) {
            self->m_state = 2;
        } else {
            self->m_state = 0;
        }
    }

    heapId = 8;
    if (r == 2) {
        if (self->m_id == 0xA1 && *(s32*)(g_HeapInfos + 0x1F0) != 0) {
            heapId = 0x1F;
        } else if (*(s32*)(g_HeapInfos + 0x230) != 0) {
            heapId = 0x23;
        }
    } else if (r == 3) {
        if (*(s32*)(g_HeapInfos + 0x260) != 0) {
            heapId = 0x26;
        }
    }

    if (self->m_soundGroup != -1) {
        if (((unsigned int)__cntlzw(fn_80073D08(g_sndSystem, self->m_soundGroup))) >> 5 == 0) {
            if (fn_80073D18(g_sndSystem, self->m_soundGroup) == 0) {
                self->m_soundHandle = g_sndSystem->loadSoundGroup((SndGroupID)self->m_soundGroup, 2, true);
                self->m_timer = 0x3C;
            }
        }
    }

    if (r == 8 || r == 0 || r == 5) {
        self->m_state = 4;
        if (*(u8*)((char*)itManager::getInstance() + 0x149D) == 0 && lbl_27_bss_5668 != NULL) {
            outBrres = 0;
            outParam = 0;
            ((Stage*)lbl_27_bss_5668)->getItemPac((gfArchive**)&outBrres, (gfArchive**)&outParam, (itKind)self->m_id, self->m_variant);
            if (outBrres != 0) {
                self->m_archive14 = fn_800455E0(soArchiveDb::getManager(2), outBrres);
            }
            if (outParam != 0) {
                self->m_archive18 = fn_800455E0(soArchiveDb::getManager(2), outParam);
            }
        }
    } else if (r == 1 || r == 6 || r == 6) {
        if (hasNameC != 0) {
            if (info.w[1] != 0) {
                self->m_archive14 = fn_800455E0(soArchiveDb::getManager(2), info.w[1]);
            }
        }
        if (info.w[0] != 0) {
            self->m_archive18 = fn_800455E0(soArchiveDb::getManager(2), info.w[0]);
        }
    }

    if (self->m_archive18 == 0xFFFF) {
        self->m_archive18 = fn_800453AC(soArchiveDb::getManager(2), (void*)nameB, heapId, 0, 0, 0, 0xFF, (void*)lbl_805A00C0, 1);
    }

    if (hasNameC == 0) {
        self->m_archive14 = 0xFFFF;
    } else if (self->m_archive14 == 0xFFFF) {
        self->m_archive14 = fn_800453AC(soArchiveDb::getManager(2), (void*)nameC, heapId, 0, 0, 0, 0xFF, (void*)lbl_805A00C0, 1);
    }

    if (info.w[2] != 0) {
        self->m_archive10 = fn_800455E0(soArchiveDb::getManager(2), info.w[2]);
    } else {
        self->m_archive10 = fn_800453AC(soArchiveDb::getManager(2), (void*)nameA, 8, 0, 0, 0, 0xFF, (void*)lbl_805A00C0, 1);
    }

    return self;
}
