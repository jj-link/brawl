#include <gr/gr_tengan_event.h>
#include <st/st_melee.h>
#include <ft/ft_manager.h>
#pragma force_active on

extern "C" void fn_27_10C18C(ftManager*);

extern "C" int fn_65_55AC(void* self) {
    char* p = (char*)self;
    switch (((grTenganEvent*)(p + 0x284))->getPhase()) {
    case 0: {
        p[0x957] = 1;
        p[0x956] = 1;
        p[0x955] = 1;
        p[0x954] = 1;
        Vec3f* pos = (Vec3f*)(p + 0x960);
        for (int i = 0; i < 4; i++, pos++) {
            stMelee::getPlayerPosition(i, pos);
        }
        ((grTenganEvent*)(p + 0x284))->setPhase(1);
        fn_27_10C18C(g_ftManager);
        break;
    }
    case 1:
        if (!((grTenganEvent*)(p + 0x3dc))->isEvent()) {
            *((unsigned char*)g_ftManager + 0x6c) &= ~0x10;
            ((grTenganEvent*)(p + 0x284))->end();
        }
        break;
    }
    return 0;
}