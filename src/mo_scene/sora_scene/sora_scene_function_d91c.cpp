#pragma force_active on

#include <gf/gf_application.h>
#include <gf/gf_scene.h>
#include <gm/gm_global.h>

extern "C" {
    int fn_1_3E50(void* loader);
    void* fn_800AFBFC(const void* name, unsigned int size, void* archive, unsigned int heap);
    void* fn_1_DB54(void* self, int arg);
    unsigned char* fn_80023AC8(void);
    void OSReport(const char* msg, ...);
    extern char lbl_1_data_4408[];
}

extern "C" int fn_1_D91C(char* self) {
    char* ssd;
    char* base = lbl_1_data_4408;
    if (*(void**)(self + 0x3AC) == 0) {
        if (fn_1_3E50(*(void**)(self + 0x454)) == 0) {
            return 0;
        }
        *(void**)(self + 0x364) = fn_800AFBFC(base + 0x40, 0x70, *(void**)(self + 0x450), 0xA);
        *(void**)(self + 0x3AC) = fn_1_DB54(self, 1);
        g_gfApplication->unkD0.endKeepScreen();
        if (*(int*)(self + 0x444) == 0) {
            unsigned char* p = fn_80023AC8();
            *(unsigned char*)(self + 0x449) = p[0x2C];
            *(unsigned char*)(self + 0x44A) = p[0x2D];
            *(unsigned char*)(self + 0x44B) = p[0x2E];
            *(unsigned char*)(self + 0x44C) = p[0x2F];
            p = fn_80023AC8();
            p[0x2C] = 0xFF;
            p[0x2D] = 0xFF;
            p[0x2E] = 0xFF;
            p[0x2F] = 0xFF;
        }
    }

    char* sub = *(char**)(self + 0x3AC);
    int r0;
    if (*(int*)(sub + 0x40) == 2) {
        r0 = *(int*)(sub + 0x274);
    } else if (*(int*)(sub + 0x224) != 0xB) {
        r0 = 0;
    } else {
        r0 = *(int*)(sub + 0x274);
    }

    switch (r0) {
    case 1: {
        int r30;
        char* fmt = base + 0x50;
        char* s = base + 0x70;
        if (*(int*)(sub + 0x254) == 3) {
            s = base + 0x6C;
        }
        OSReport(fmt, s);
        {
            char* s2 = *(char**)(self + 0x3AC);
            int t = *(int*)(s2 + 0x254);
            int v;
            if (t == 0) {
                v = 0x42;
            } else if (t == 1) {
                v = *(int*)(s2 + 0x258);
            } else {
                v = 0;
            }
            OSReport(base + 0x74, v);
        }
        OSReport(base + 0x8C, *(unsigned char*)(*(char**)(self + 0x3AC) + 0x25C));
        {
            int* s5 = *(int**)(self + 0x3AC);
            int k = s5[0x254 / 4];
            if (k == 3) {
                r30 = 3;
            } else {
                ssd = (char*)g_GameGlobal->m_selStageData;
                int v = (k == 0) ? 0x42 : ((k == 1) ? s5[0x258 / 4] : 0);
                *(short*)(ssd + 0x22) = (short)v;
                r30 = 1;
                ssd[0x24] = *(unsigned char*)(*(char**)(self + 0x3AC) + 0x25C);
            }
            gfSceneManager* mgr = gfSceneManager::getInstance();
            mgr->unk1 = r30;
            mgr->processStep = 2;
        }
        break;
    }
    case 2: {
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
        break;
    }
    case 3: {
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 2;
        mgr->processStep = 2;
        break;
    }
    }
    return 0;
}
