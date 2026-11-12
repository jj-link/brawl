#include <gf/gf_scene.h>
#include <gm/gm_global.h>
#pragma force_active on

extern "C" {
extern unsigned char lbl_1_data_6CA0[];
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
unsigned int* fn_8004E6DC(GameGlobal*);
}

struct BootSequence {
    char pad[8];
    unsigned int state;
    unsigned int next;
    unsigned char param;
    char pad2[3];
    int result;
};

extern "C" void fn_1_21F3C(BootSequence* self) {
    char* base = (char*)lbl_1_data_6CA0;
    gfSceneManager* manager = gfSceneManager::getInstance();
    int again = 1;
    while (again) {
        again = 0;
        switch (self->state) {
        default:
        case 0:
            self->state = 5;
            again = 1;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(manager, base + 8, self->param);
            self->state = 2;
            break;
        case 2:
            again = 1;
            self->state = self->next;
            break;
        case 5:
            setNextScene__14gfSceneManagerFv(manager, base + 24, 0);
            self->state = 6;
            break;
        case 6:
            self->state = 1;
            again = 1;
            self->next = 3;
            self->param = 2;
            break;
        case 3:
            setNextScene__14gfSceneManagerFv(manager, base + 32, 0);
            self->state = 4;
            break;
        case 4:
            if (self->result == 2)
                self->state = 8;
            else
                self->state = 7;
            again = 1;
            break;
        case 8:
            ((unsigned char*)g_GameGlobal->m_appData)[0x28] |= 0x40;
            setNextSequence__14gfSceneManagerFv(manager, base + 40, 42);
            break;
        case 7:
            {
                unsigned int* count = fn_8004E6DC(g_GameGlobal);
                if (*count < 0x05F5E0FFU)
                    ++*count;
                ((unsigned char*)g_GameGlobal->m_appData)[0x28] |= 0x40;
                setNextSequence__14gfSceneManagerFv(manager, base + 52, 20);
            }
            break;
        }
    }
}
