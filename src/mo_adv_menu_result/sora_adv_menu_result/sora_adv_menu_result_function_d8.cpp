#pragma force_active on

#include <gf/gf_task.h>
#include <gf/gf_archive.h>
#include <sr/sr_common.h>
#include <mu/menu.h>

extern "C" {
extern char lbl_34_data_0[];
extern char lbl_34_data_10[];
extern char lbl_34_data_70[];

void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, gfTask::Category, int, int, bool);
void fn_800B96E8(void*, int);
void* fn_1_3C68(void*, int, void*, void*, int);
}

extern "C" void* fn_34_D8(void* p)
{
    char* self = (char*)p;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        p, lbl_34_data_0, gfTask::Category_Menu, 15, 8, true);

    *(void**)(self + 0x3C) = lbl_34_data_70;
    *(int*)(self + 0x40) = 0;
    *(int*)(self + 0x44) = 0;
    *(int*)(self + 0x48) = 60;
    fn_800B96E8(self + 0x4C, 255);

    *(int*)(self + 0xFC) = 0;
    *(int*)(self + 0x100) = 0;
    *(int*)(self + 0x104) = 0;
    *(int*)(self + 0x108) = 0;
    *(int*)(self + 0x10C) = 0;
    *(int*)(self + 0x110) = 0;
    *(int*)(self + 0x114) = 0;
    *(int*)(self + 0x118) = 0;
    *(int*)(self + 0x11C) = 0;
    *(int*)(self + 0x120) = 0;
    *(int*)(self + 0x128) = 0;
    *(int*)(self + 0x134) = 0;
    *(int*)(self + 0x1B8) = 0;
    *(int*)(self + 0x1BC) = 0;
    *(int*)(self + 0x1C0) = 6;
    *(int*)(self + 0x1C4) = 0;
    *(int*)(self + 0x598) = 0;
    *(int*)(self + 0x59C) = 0;
    *(int*)(self + 0x5A8) = 0;
    *(int*)(self + 0x5AC) = 0;
    self[0x5A4] = 0;
    *(int*)(self + 0x130) = 0;
    *(int*)(self + 0x12C) = 0;
    for (int i = 0; i < 32; ++i) {
        ((int*)(self + 0x138))[i] = 0;
    }
    *(int*)(self + 0x5A0) = -1;

    *(gfArchive**)(self + 0x5A8) = new (Heaps::MenuResource) gfArchive;

    char* buf = (char*)operator new(0x20, Heaps::MenuResource);
    if (buf) {
        *(int*)(buf + 0x00) = 0;
        *(int*)(buf + 0x04) = 0;
        *(int*)(buf + 0x08) = 0;
        *(int*)(buf + 0x0C) = 0;
        *(int*)(buf + 0x10) = 0;
        unsigned int c = (unsigned char)buf[0x1C];
        *(int*)(buf + 0x18) = 0;
        c &= 0xFFFFFF1F;
        *(int*)(buf + 0x14) = 255;
        buf[0x1C] = (char)c;
    }

    *(void**)(self + 0x5AC) = buf;
    fn_1_3C68(buf, 0x2B, lbl_34_data_10,
              *(void**)(self + 0x5A8), 0x552800);
    muMenu::loadMenuSound();

    return p;
}
