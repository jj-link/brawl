#include <ef/ef_screen.h>
#include <so/so_world.h>
#pragma force_active on

extern "C" {
extern const float lbl_27_rodata_3934;
extern char lbl_27_data_4CA48[];
void __dt__15stCommonGimmickFv(void* self, int flag);
void __dl__FPv(void* p);
}

extern "C" void* __dt__7stMeleeFv(void* self, int destroyFlag) {
    if (self != 0) {
        *(void**)((char*)self + 0x3C) = lbl_27_data_4CA48;
        g_soWorld->m_gravityUp = lbl_27_rodata_3934;
        g_soWorld->m_gravityDown = lbl_27_rodata_3934;
        *(int*)((char*)g_efScreen + 0x1DC) = 0;
        {
            void* p = *(void**)((char*)self + 0x1C8);
            if (p != 0) {
                __dl__FPv(p);
            }
        }
        __dt__15stCommonGimmickFv(self, 0);
        if (destroyFlag > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
