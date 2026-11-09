#pragma force_active on
#include <types.h>
#include <it/it_manager.h>
#include <em/em_manager.h>
#include <st/st_data_container.h>
#include <gf/gf_archive.h>

struct GameSub { char pad0[0x5FD]; u8 frame; char pad1[0x4916 - 0x5FE]; u8 stageFrame; };
struct GameGlobal { char pad0[0x30]; GameSub* sub; };
extern GameGlobal* g_GameGlobal;
extern emManager* lbl_41_bss_30;
extern u32 lbl_40_bss_8[];
extern "C" void fn_27_2ABCFC(itManager* self, u32 value);
extern "C" int fn_27_2A5908(itManager* self);

struct Stage_base { char pad[0x3c]; };
class Stage : public Stage_base {
public:
    virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3();
    virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7();
    virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11();
    virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15();
    virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19();
    virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23();
    virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27();
    virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31();
    virtual void s32();
    virtual void fn_40_8160(gfArchive** out1, gfArchive** out2, gfArchive** out3, gfArchive** out4, u16 index);
};

class Object_vptr_0 { public: virtual void destroy(bool); };

extern "C" int fn_40_5EC(Stage* self) {
    u8* bytes = (u8*)self;
    stDataContainerData* entry;
    stDataContainer* container;
    u32 idx;
    u32 i;
    u16 kind;
    u32 magic;
    gfArchive* sp14;
    gfArchive* sp10;
    gfArchive* spC;
    gfArchive* sp8;

    GameSub* gs = g_GameGlobal->sub;
    int frame = gs->frame;
    int value = frame - gs->stageFrame;
    int low = frame - 5;
    if (value < low) value = low;
    if (value < 0) value = 0;
    if (value > 14) value = 14;

    switch ((u8)value) {
    case 0: case 1: case 2:
        fn_27_2ABCFC(itManager::getInstance(), 0);
        break;
    case 3: case 4: case 5:
        fn_27_2ABCFC(itManager::getInstance(), 1);
        break;
    case 6: case 7: case 8:
        fn_27_2ABCFC(itManager::getInstance(), 2);
        break;
    case 9: case 10: case 11:
        fn_27_2ABCFC(itManager::getInstance(), 3);
        break;
    case 12: case 13: case 14:
        fn_27_2ABCFC(itManager::getInstance(), 4);
        break;
    }

    u8 state = *((u8*)(*(void**)(bytes + 0x524)) + 0x604);
    int result = 1;
    if (state != 3 && state != 4) {
        if (!lbl_41_bss_30) {
            result = 1;
        } else {
            if (!((bytes[0x550] >> 4) & 1)) {
                void* data = (*(gfArchive**)(bytes + 0x1A0))->getData(Data_Type_Misc, 7, 0xFFFE);
                if (data != 0) {
                    *(stDataMultiContainer**)(bytes + 0x558) =
                        stDataMultiContainer::create((stDataContainerData*)data, (HeapType)15);
                }
                stDataMultiContainer* multi = *(stDataMultiContainer**)(bytes + 0x558);
                if (multi != 0) {
                    if (g_BlocMagic.data == multi->m_filedata->m_MAGIC) {
                        magic = lbl_40_bss_8[9];
                        idx = 0;
                        while ((container = multi->searchContainer(magic, idx++)) != 0) {
                            for (i = 0; i < container->m_filedata->m_numFiles; i++) {
                                entry = container->getData(i);
                                kind = *(u16*)((u8*)entry + 0x1C);
                                self->fn_40_8160(&spC, &sp8, &sp10, &sp14, kind);
                                emManager::getInstance()->preloadArchive(sp8, spC, sp10, sp14, (EnemyKind)kind, true);
                                if ((s32)*(u16*)((u8*)entry + 0x1C) == 4)
                                    *(u32*)(bytes + 0x594) |= 0x80000000;
                                if ((s32)*(u16*)((u8*)entry + 0x1C) == 0x19)
                                    *(u32*)(bytes + 0x594) |= 0x40000000;
                            }
                        }
                    }
                    if (*(stDataMultiContainer**)(bytes + 0x558) != 0) {
                        ((Object_vptr_0*)*(stDataMultiContainer**)(bytes + 0x558))->destroy(true);
                    }
                    *(stDataMultiContainer**)(bytes + 0x558) = 0;
                }
                bytes[0x550] |= 0x10;
            }
            result = emManager::getInstance()->isCompArchiveAll() != 0;
        }
        if (result) {
            if ((*(u32*)(bytes + 0x594) >> 31) == 1) {
                if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x50, 0, true)) {
                    itManager::getInstance()->preloadItemKindArchive((itKind)0x50, 0, (itArchive::Type)0, true);
                }
                *(u32*)(bytes + 0x594) &= 0x7FFFFFFF;
            }
            if (((*(u32*)(bytes + 0x594) >> 30) & 1) == 1) {
                if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x52, 0, true)) {
                    itManager::getInstance()->preloadItemKindArchive((itKind)0x52, 0, (itArchive::Type)0, true);
                }
                if (!itManager::getInstance()->isCompItemKindArchive((itKind)0x51, 0, true)) {
                    itManager::getInstance()->preloadItemKindArchive((itKind)0x51, 0, (itArchive::Type)0, true);
                }
                *(u32*)(bytes + 0x594) &= 0xBFFFFFFF;
            }
            return fn_27_2A5908(itManager::getInstance());
        }
    }
    return result;
}
