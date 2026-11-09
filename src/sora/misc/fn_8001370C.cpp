#include <types.h>
#include <gf/gf_archive.h>
#include <gf/gf_archive_manager.h>
#pragma force_active on

extern char lbl_8042093C[];

struct ArcWord8 {
    u32 a : 8;
    u32 rest : 24;
};

struct ArcByte9 {
    u8 a : 4;
    u8 b : 1;
    u8 c : 2;
    u8 d : 1;
};

gfArchive::gfArchive()
{
    *(u32*)((char*)this + 0x00) = 0;
    ((ArcWord8*)((char*)this + 0x08))->a = 0;
    *(u32*)((char*)this + 0x04) = 0;
    *(u16*)((char*)this + 0x0A) = 0;
    ((ArcByte9*)((char*)this + 0x09))->a = 0;
    ((ArcByte9*)((char*)this + 0x09))->b = 1;
    ((ArcByte9*)((char*)this + 0x09))->c = 0;
    *(u16*)((char*)this + 0x0C) = 0;
    *(u16*)((char*)this + 0x0E) = 0;
    *(u32*)((char*)this + 0x10) = 0;
    *(u32*)((char*)this + 0x14) = 0;
    *(u32*)((char*)this + 0x18) = 0;
    *(u32*)((char*)this + 0x1C) = 0;
    *(u32*)((char*)this + 0x20) = 0;
    *(u32*)((char*)this + 0x24) = 0;
    *(u32*)((char*)this + 0x68) = 0;
    *(u32*)((char*)this + 0x6C) = 0;
    *(u32*)((char*)this + 0x70) = 0x15;
    *(u32*)((char*)this + 0x74) = 0x10000000;
    *(void**)((char*)this + 0x78) = lbl_8042093C;
    *(gfArchive**)((char*)this + 0x7C) = this;
    *(u8*)((char*)this + 0x28) = 0;
    g_gfArchiveManager->pushback(this);
}
