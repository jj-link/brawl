#include <types.h>
typedef struct OSModuleHeader OSModuleHeader;
typedef int bool;
#include <revolution/OS/OSLink.h>
#include <revolution/OS/OSCache.h>
#pragma force_active on

typedef struct ImportEntry {
    u32 id;
    u32 offset;
} ImportEntry;

typedef struct RelocEntry {
    u16 offset;
    u8 type;
    u8 section;
    u32 addend;
} RelocEntry;

typedef struct SectionInfo {
    u32 offset;
    u32 size;
} SectionInfo;

extern void fn_801DD69C(OSModuleHeader*, OSModuleHeader*);
extern void fn_801DD6A0(OSModuleHeader*, OSModuleHeader*);
extern void OSReport(const char* msg, ...);
extern char lbl_80468980[];

int fn_801DD6A4(OSModuleHeader* arg0, OSModuleHeader* arg1)
{
    u32 id;
    RelocEntry* rel;
    SectionInfo* exec;
    u32 addr;
    u32 t;
    u32 tmp;
    u32 secOff;
    s32 val;
    ImportEntry* imp;
    SectionInfo* sec;

    if (arg0 != NULL) {
        id = arg0->id;
    } else {
        id = 0;
    }
    for (imp = (ImportEntry*)arg1->impOffset; imp < (ImportEntry*)(arg1->impOffset + arg1->impSize); imp++) {
        if (imp->id == id) {
            goto found;
        }
    }
    return 0;

found:
    fn_801DD69C(arg0, arg1);
    exec = NULL;
    for (rel = (RelocEntry*)imp->offset; rel->type != 0xCB; rel++) {
        addr += rel->offset;
        if (id != 0) {
            tmp = arg0->sectionInfoOffset;
            val = *(u32*)(tmp + rel->section * 8) & ~1U;
        } else {
            val = 0;
        }
        switch (rel->type) {
        case 0:
            break;
        case 1:
            *(u32*)addr = val + rel->addend;
            break;
        case 2:
            *(u32*)addr = (*(u32*)addr & 0xFC000003) | ((val + rel->addend) & 0x03FFFFFC);
            break;
        case 3:
            *(u16*)addr = val + rel->addend;
            break;
        case 4:
            *(u16*)addr = val + rel->addend;
            break;
        case 5:
            *(u16*)addr = (val + rel->addend) >> 16;
            break;
        case 6:
            t = val + rel->addend;
            *(u16*)addr = (t >> 16) + ((t >> 15) & 1);
            break;
        case 7:
        case 8:
        case 9:
            *(u32*)addr = (*(u32*)addr & 0xFFFF0003) | ((val + rel->addend) & 0xFFFC);
            break;
        case 0xA:
            *(u32*)addr = (*(u32*)addr & 0xFC000003) | (((val + rel->addend) - addr) & 0x03FFFFFC);
            break;
        case 0xB:
        case 0xC:
        case 0xD:
            *(u32*)addr = (*(u32*)addr & 0xFFFF0003) | (((val + rel->addend) - addr) & 0xFFFC);
            break;
        case 0xC9:
            break;
        case 0xCA:
            secOff = rel->section * 8;
            tmp = arg1->sectionInfoOffset;
            sec = (SectionInfo*)(tmp + secOff);
            addr = *(u32*)(tmp + secOff) & ~1U;
            if (exec != NULL) {
                tmp = exec->offset & ~1U;
                DCFlushRange((void*)tmp, exec->size);
                ICInvalidateRange((void*)tmp, exec->size);
            }
            if (sec->offset & 1) {
                exec = sec;
            } else {
                exec = NULL;
            }
            break;
        default:
            OSReport(lbl_80468980);
            break;
        }
    }
    if (exec != NULL) {
        tmp = exec->offset & ~1U;
        DCFlushRange((void*)tmp, exec->size);
        ICInvalidateRange((void*)tmp, exec->size);
    }
    fn_801DD6A0(arg0, arg1);
    return 1;
}
