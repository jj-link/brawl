#include <types.h>
#include <gm/gm_global.h>
#include <gf/gf_file_io_handle.h>
#include <mu/menu.h>
#pragma force_active on

struct MenuFileState {
    char pad0[0xA8];
    s32 unkA8[4];
    char pad1[0x445C - 0xB8];
    u8 unk445C[8];
    u8 unk4464[4];
    gfFileIOHandle handles[12];
    s32 unk4498;
    s32 unk449C[4];
};

extern "C" char lbl_8045A428[];
extern "C" const float lbl_805A2468;
extern "C" int sprintf(char*, const char*, ...);

extern "C" void fn_800E5E34(MenuFileState* self, s32 arg1)
{
    char* names = lbl_8045A428;
    u8* results = (u8*)g_GameGlobal->m_resultInfo;
    u8* var29;
    u8* var28;
    u32 i;

    self->unk4498 = arg1;
    if (arg1 == 0) {
        u8* rec = (u8*)g_GameGlobal->getGlobalRecordMenuDatap();
        if ((rec[0x28] >> 7) & 1) {
            self->handles[0].readRequest(&names[0x5BC], (HeapType)0x2B, 0, 0);
        } else {
            self->handles[0].readRequest(&names[0x5EC], (HeapType)0x2B, 0, 0);
        }
        self->handles[1].readRequest(&names[0x618], (HeapType)0x2B, 0, 0);
        self->handles[2].readRequest(&names[0x638], (HeapType)0x2B, 0, 0);
        self->handles[3].readRequest(&names[0x658], (HeapType)0x2B, 0, 0);
        self->handles[4].readRequest(&names[0x680], (HeapType)0x2B, 0, 0);
        self->handles[5].readRequest(&names[0x69C], (HeapType)0x2B, 0, 0);
        self->handles[6].readRequest(&names[0x6B4], (HeapType)0x2B, 0, 0);
        self->handles[7].readRequest(&names[0x6CC], (HeapType)0x2B, 0, 0);
    } else {
        self->unk445C[0] = 1;
        self->unk445C[1] = 1;
        self->unk445C[2] = 1;
        self->unk445C[3] = 1;
        self->unk445C[4] = 1;
        self->unk445C[5] = 1;
        self->unk445C[6] = 1;
        self->unk445C[7] = 1;
    }

    var28 = results + 0x24;
    var29 = (u8*)self;
    i = 0;
    do {
        u8* p4;
        u8* p5;
        s32 j;
        s32 var7 = 1;
        if (*(s32*)(var29 + 0xA8) != 3) {
            p4 = (u8*)self;
            p5 = results;
            for (j = 0; j < i; j++) {
                if (*(s32*)(p4 + 0xA8) != 3 && var28[0] == p5[0x24]) {
                    *(s32*)(var29 + 0x449C) = j;
                    var7 = 0;
                    break;
                }
                p4 += 4;
                p5 += 0x2AC;
            }
            if (var7 != 0) {
                s32 stock = muMenu::exchangeGmCharacterKind2MuStockchkind(var28[0]);
                s32 fileKind = muMenu::exchangeGmCharacterKind2Something(stock);
                u32 n = (u32)((f32)(fileKind * 10 + 1) - lbl_805A2468);
                char buf[0x40];
                sprintf(buf, &names[0x6E8], n);
                self->handles[8 + i].readRequest(buf, (HeapType)0x2A, 0, 0);
                *(s32*)(var29 + 0x449C) = i;
            } else {
                self->unk4464[i] = 1;
            }
        } else {
            self->unk4464[i] = 1;
            *(s32*)(var29 + 0x449C) = 0;
        }
        var29 += 4;
        i++;
        var28 += 0x2AC;
    } while (i < 4);
    muMenu::loadMenuSound();
}
