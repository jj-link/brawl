#include <ft/ft_common_data_accesser.h>
#include <ft/ft_slot_manager.h>
#include <it/it_manager.h>
#include <so/so_common_data_accesser.h>
#include <types.h>

#pragma force_active on

struct ItKindTable {
    itKind* kinds;
    s32 count;
};

struct FtDataWithTable {
    u8 pad[0x60];
    ItKindTable* table;
};

struct Self {
    u8 pad[0x24];
    unsigned long value;
};

struct Event {
    u8 pad[0x18];
    ftKind kind;
    u32 archive[1];
    int value;
    u8 pad24[0xc];
    u8 b30;
    u8 b31;
    u8 b32;
    u8 b33;
};

extern "C" {
void* fn_27_7013C(u32*, const char*);
void* fn_27_70070(u32*, int, unsigned long, unsigned long, unsigned long);
void* fn_27_700D0(u32*, int, int, int*, int, int);
void* fn_27_6FF4C(u32*, unsigned long);
void* fn_27_1455E0(void*);
void fn_27_1455FC(ftKind, void*);
bool fn_27_145694(int);
void fn_27_1E864C(void*, int, unsigned char);
void fn_27_1220DC(ftSlotManager*, u8, u8, int, ftKind, u8, int);

extern itManager* lbl_27_bss_6A34;
extern char lbl_27_data_2B998[];
extern char lbl_27_data_2B9A4[];
}

extern "C" void fn_27_143EFC(Self* self, Event* event) {
    switch ((event->b33 >> 1) & 0x7f) {
    case 15: {
        self = (Self*)fn_27_7013C(event->archive, lbl_27_data_2B998);
        ((void**)&g_soCommonDataAccesser)[0] =
            fn_27_70070(event->archive, 3, 0, 0, -1);
        ((void**)&g_soCommonDataAccesser)[1] =
            fn_27_70070(event->archive, 4, 0, 0, -1);
        g_soCommonDataAccesser.setupCommonParam((soCommonParam**)self);
        fn_27_1455E0(self);

        int size;
        void* p = fn_27_700D0(event->archive, 1, 1, &size, 0, -1);
        fn_27_1E864C(p, size, 0);
        break;
    }
    case 1: {
        FtDataWithTable* data;
        s32 i;
        s32 offset;
        fn_27_6FF4C(event->archive, self->value);
        fn_27_1455FC(event->kind,
                     fn_27_7013C(event->archive, lbl_27_data_2B9A4));

        data = (FtDataWithTable*)event->kind;
        if (fn_27_145694((int)data) == 1) {
            data = reinterpret_cast<FtDataWithTable*>(
                g_ftCommonDataAccesser.getData((ftKind)data));
            if (data->table != NULL) {
                ItKindTable* table;
                i = 0;
                for (offset = 0; i < (table = data->table)->count; offset += 4, i++) {
                    if (lbl_27_bss_6A34 != NULL) {
                        if (!itManager::getInstance()->isCompItemKindArchive(
                                *(itKind*)((char*)table->kinds + offset), 0, true)) {
                            itManager::getInstance()->preloadItemKindArchive(
                                *(itKind*)((char*)data->table->kinds + offset),
                                0, (itArchive::Type)0, true);
                        }
                    }
                }
            }
        }
        break;
    }
    case 10: {
        int size = 0;
        if (fn_27_700D0(event->archive, 1, 0, &size, 0, -1)) {
            fn_27_6FF4C(event->archive, self->value);
        }
        break;
    }
    }

    fn_27_1220DC(g_ftSlotManager, event->b31, event->b32,
                 (event->b33 >> 1) & 0x7f, event->kind,
                 event->b30, event->value);
}