#include <gf/gf_task.h>
#include <gm/gm_global.h>
#include <sr/sr_common.h>
#pragma force_active on

extern "C" void __ct__6gfTaskFPCcQ26gfTask8Categoryiib(void*, const char*, int, int, int, bool);
extern char lbl_8042E8A8[];
extern char lbl_8042E8FC[];
extern int lbl_8059CE48;
extern gfTask* lbl_805A00F0;
extern gfTask* lbl_805A00F4;

extern "C" gfTask* fn_8005A0E4(int heap) {
    if (lbl_805A00F4) return 0;
    ((unsigned char*)g_GameGlobal->m_appData)[0x28] |= 0x20;
    lbl_8059CE48 = heap;
    gfTask* t = (gfTask*)operator new(0x48, (Heaps::HeapType)heap);
    if (t) {
        __ct__6gfTaskFPCcQ26gfTask8Categoryiib(t, lbl_8042E8A8, 0, 14, 6, true);
        *(char**)((char*)t + 0x3c) = lbl_8042E8FC;
        *(int*)((char*)t + 0x40) = -1;
        *(int*)((char*)t + 0x44) = 0;
        lbl_805A00F0 = t;
    }
    lbl_805A00F4 = t;
    t->init();
    return lbl_805A00F4;
}