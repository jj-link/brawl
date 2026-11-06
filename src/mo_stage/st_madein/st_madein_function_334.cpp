#include <st/st_melee.h>
#include <gr/gr_tengan_event.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" {
extern char lbl_65_data_4FC[];
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
}

extern "C" void* fn_65_334(void* self, int flag) {
    if (self) {
        *(char**)((char*)self + 0x3c) = lbl_65_data_4FC;
        *((unsigned char*)g_ftManager + 0x6c) &= ~0x10;
        ((stCommonGimmick*)self)->releaseArchive();
        ((grTenganEvent*)((char*)self + 0x68c))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x5e0))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x534))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x488))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x3dc))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x330))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x284))->~grTenganEvent();
        ((grTenganEvent*)((char*)self + 0x1d8))->~grTenganEvent();
        __dt__7stMeleeFv(self, 0);
        if (flag > 0) __dl__FPv(self);
    }
    return self;
}