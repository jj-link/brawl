#include <gf/gf_application.h>
#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on
extern "C" {
int fn_1_3E50(void*);
void fn_1_3F04(void*, void*, void*, int);
void fn_1_3F84(void*, void*, int);
void* fn_800AFBFC(const void*, unsigned int, void*, unsigned int);
void* fn_1_D3A4(void*);
unsigned char* fn_80023AC8();
extern const char lbl_1_data_4364[];
int fn_1_D240(void* self) {
    unsigned char* s = (unsigned char*)self;
    void* task = *(void**)(s + 0x400);
    if (!task) {
        int ready = !fn_1_3E50(*(void**)(s + 0x414)) ? 0 : fn_1_3E50(*(void**)(s + 0x418));
        if (ready) {
            fn_1_3F04(*(void**)(s + 0x414), *(void**)(s + 0x3b0), *(void**)(s + 0x410), 20);
            fn_1_3F84(*(void**)(s + 0x418), *(void**)(s + 0x3ac), 10);
            *(void**)(s + 0x35c) = fn_800AFBFC(lbl_1_data_4364, 300, *(void**)(s + 0x410), 10);
            *(void**)(s + 0x400) = fn_1_D3A4(self);
            g_gfApplication->unkD0.endKeepScreen();
            unsigned char* p = fn_80023AC8();
            s[0x409] = p[0x2c];
            s[0x40a] = p[0x2d];
            s[0x40b] = p[0x2e];
            s[0x40c] = p[0x2f];
            p = fn_80023AC8();
            p[0x2c] = 255;
            p[0x2d] = 255;
            p[0x2e] = 255;
            p[0x2f] = 255;
        }
    } else {
        switch (*(int*)((char*)task + 0x40)) {
        case 2: { gfSceneManager* m = gfSceneManager::getInstance(); m->unk1 = 1; m->processStep = 2; break; }
        case 4: { gfSceneManager* m = gfSceneManager::getInstance(); m->unk1 = 0; m->processStep = 2; break; }
        case 5: { gfSceneManager* m = gfSceneManager::getInstance(); m->unk1 = 2; m->processStep = 2; break; }
        }
    }
    return 0;
}
}