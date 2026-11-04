#include <types.h>
typedef struct OSModuleHeader OSModuleHeader;
typedef int bool;
#include <revolution/OS/OSLink.h>
#pragma force_active on

typedef struct ImportEntry {
    u32 id;
    u32 offset;
} ImportEntry;

extern void fn_801DDC70(OSModuleHeader*, OSModuleHeader*);
extern void fn_801DD698(OSModuleHeader*);

int fn_801DDEAC(OSModuleHeader* module)
{
    OSModuleHeader* next = (OSModuleHeader*)module->linkNext;
    OSModuleHeader* prev = (OSModuleHeader*)module->linkPrev;
    OSModuleHeader* p;
    u32 base;
    ImportEntry* imp;
    u32* sections;
    u32 offset;
    u32 i;

    if (next == 0)
        *(OSModuleHeader**)0x800030CC = prev;
    else
        next->linkPrev = (u32)prev;
    if (prev == 0)
        *(OSModuleHeader**)0x800030C8 = next;
    else
        prev->linkNext = (u32)next;

    p = *(OSModuleHeader**)0x800030C8;
    while (p != 0) {
        fn_801DDC70(module, p);
        p = (OSModuleHeader*)p->linkNext;
    }
    fn_801DD698(module);

    base = *(u32*)0x800030D0;
    if (base != 0)
        module->nameOffset -= base;

    if ((u8)module->prologSection != 0)
        module->prologOffset -= ((u32*)module->sectionInfoOffset)[(u8)module->prologSection * 2] & ~1U;
    if ((u8)module->epilogSection != 0)
        module->epilogOffset -= ((u32*)module->sectionInfoOffset)[(u8)module->epilogSection * 2] & ~1U;
    if ((u8)module->unresolvedSection != 0)
        module->unresolvedOffset -= ((u32*)module->sectionInfoOffset)[(u8)module->unresolvedSection * 2] & ~1U;

    imp = (ImportEntry*)module->impOffset;
    while ((u32)imp < module->impOffset + module->impSize) {
        imp->offset -= (u32)module;
        imp++;
    }

    for (i = 1, offset = 8; i < module->numSections; offset += 8, i++) {
        sections = (u32*)module->sectionInfoOffset;
        if (i == (u8)module->bssSection) {
            module->bssSection = 0;
            *(u32*)((u8*)sections + offset) = 0;
        } else if (*(u32*)((u8*)sections + offset) != 0) {
            *(u32*)((u8*)sections + offset) -= (u32)module;
        }
    }

    module->relOffset -= (u32)module;
    module->impOffset -= (u32)module;
    module->sectionInfoOffset -= (u32)module;
    return 1;
}
