#include <gf/gf_scene.h>
#pragma force_active on

extern "C" {
extern char lbl_1_data_9150[];
void setNextScene__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void setNextSequence__14gfSceneManagerFv(gfSceneManager*, const char*, int);
void fn_800515E8();
void fn_80051680();
}

struct CoinShooterSequence {
    char pad[8];
    int state;
    int nextState;
    unsigned char sceneArg;
};

extern "C" void fn_1_3A3BC(CoinShooterSequence* self) {
    const char* base = lbl_1_data_9150;
    gfSceneManager* mgr = gfSceneManager::getInstance();
    int again = 1;
    while (again) {
        again = 0;
        switch (self->state) {
        default:
            self->state = 1;
            again = 1;
            self->nextState = 3;
            self->sceneArg = 0x10;
            break;
        case 1:
            setNextScene__14gfSceneManagerFv(mgr, base + 0x10, self->sceneArg);
            self->state = 2;
            break;
        case 2:
            again = 1;
            self->state = self->nextState;
            break;
        case 3:
            fn_800515E8();
            fn_80051680();
            setNextScene__14gfSceneManagerFv(mgr, base + 0x20, 0);
            self->state = 4;
            break;
        case 4:
            self->state = 5;
            again = 1;
            break;
        case 5:
            setNextSequence__14gfSceneManagerFv(mgr, base + 0x30, 0x11);
            self->state = 6;
            break;
        }
    }
}
