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
extern char lbl_804689A8[];

int fn_801DDC70(OSModuleHeader* arg0, OSModuleHeader* arg1)
{
    ImportEntry* imp;
    RelocEntry* rel;
    SectionInfo* exec;
    SectionInfo* sec;
    u32 end;
    u32 id;
    u32 addr;
    u32 tmp;
    u32 secOff;
    s32 val;

    id = arg0->id;
    end = arg1->impOffset + arg1->impSize;
    for (imp = (ImportEntry*)arg1->impOffset; (u32)imp < end; imp++) {
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
        secOff = rel->section * 8;
        val = 0;
        switch (rel->type) {
        case 0:
            break;
        case 1:
            *(u32*)addr = 0;
            break;
        case 2:
            *(u32*)addr &= 0xFC000003;
            break;
        case 3:
            *(u16*)addr = 0;
            break;
        case 4:
            *(u16*)addr = 0;
            break;
        case 5:
            *(u16*)addr = 0;
            break;
        case 6:
            *(u16*)addr = 0;
            break;
        case 7:
        case 8:
        case 9:
            *(u32*)addr &= 0xFFFF0003;
            break;
        case 0xA:
            if ((u8)arg1->unresolvedSection != 0) {
                val = arg1->unresolvedOffset - addr;
            }
            *(u32*)addr = (*(u32*)addr & 0xFC000003) | (val & 0x03FFFFFC);
            break;
        case 0xB:
        case 0xC:
        case 0xD:
            *(u32*)addr &= 0xFFFF0003;
            break;
        case 0xC9:
            break;
        case 0xCA:
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
            OSReport(lbl_804689A8, rel->type);
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
