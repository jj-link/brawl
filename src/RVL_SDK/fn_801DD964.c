#include <types.h>
typedef struct OSModuleHeader OSModuleHeader;
typedef int bool;
#include <revolution/OS/OSLink.h>
#include <internal/mem.h>
#pragma force_active on

typedef struct ImportEntry {
    u32 id;
    u32 offset;
} ImportEntry;

typedef struct SectionInfo {
    u32 offset;
    u32 size;
} SectionInfo;

extern void fn_801DD6A4(OSModuleHeader*, OSModuleHeader*);
extern void fn_801DD694(OSModuleHeader*);

int fn_801DD964(OSModuleHeader* module, void* bss, int fixed)
{
    OSModuleHeader* prev;
    OSModuleHeader* p;
    ImportEntry* imp;
    ImportEntry* end;
    ImportEntry* start;
    ImportEntry* scan;
    u32 offset;
    u32 i;
    SectionInfo* sec;
    u32 base;

    module->bssSection = 0;
    if (module->version > 3 ||
        (module->version >= 2 &&
         ((module->moduleAlign != 0 && (u32)module % module->moduleAlign != 0) ||
          (module->bssAlign != 0 && (u32)bss % module->bssAlign != 0))))
        return 0;

    prev = *(OSModuleHeader**)0x800030CC;
    if (prev == NULL)
        *(OSModuleHeader**)0x800030C8 = module;
    else
        prev->linkNext = (u32)module;
    module->linkPrev = (u32)prev;
    module->linkNext = 0;
    *(OSModuleHeader**)0x800030CC = module;

    module->sectionInfoOffset += (u32)module;
    module->relOffset += (u32)module;
    module->impOffset += (u32)module;
    if (module->version >= 3)
        module->commandOffset += (u32)module;

    for (i = 1, offset = 8; i < module->numSections; offset += 8, i++) {
        sec = (SectionInfo*)(module->sectionInfoOffset + offset);
        if (sec->offset != 0) {
            sec->offset += (u32)module;
        } else if (sec->size != 0) {
            module->bssSection = i;
            sec->offset = (u32)bss;
        }
    }

    imp = (ImportEntry*)module->impOffset;
    while ((u32)imp < module->impOffset + module->impSize) {
        imp->offset += (u32)module;
        imp++;
    }

    if ((u8)module->prologSection != 0)
        module->prologOffset += ((u32*)module->sectionInfoOffset)[(u8)module->prologSection * 2] & ~1U;
    if ((u8)module->epilogSection != 0)
        module->epilogOffset += ((u32*)module->sectionInfoOffset)[(u8)module->epilogSection * 2] & ~1U;
    if ((u8)module->unresolvedSection != 0)
        module->unresolvedOffset += ((u32*)module->sectionInfoOffset)[(u8)module->unresolvedSection * 2] & ~1U;

    base = *(u32*)0x800030D0;
    if (base != 0)
        module->nameOffset += base;

    fn_801DD6A4(NULL, module);
    p = *(OSModuleHeader**)0x800030C8;
    while (p != NULL) {
        fn_801DD6A4(module, p);
        if (p != module)
            fn_801DD6A4(p, module);
        p = (OSModuleHeader*)p->linkNext;
    }

    if (fixed != 0) {
        start = (ImportEntry*)module->impOffset;
        end = (ImportEntry*)((u32)start + module->impSize);
        for (scan = start; scan < end; scan++) {
            if (scan->id == 0 || scan->id == module->id) {
                module->impSize = (u32)scan - (u32)start;
                break;
            }
        }
    }

    memset(bss, 0, module->bssSize);
    fn_801DD694(module);
    return 1;
}
