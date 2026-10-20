#pragma force_active on
struct Scene {
    char pad0[8];
    int state;
    char padC[8];
    int mode;
    int value;
    bool flag;
};

struct Application {
    char pad0[0x110];
    unsigned char flag;
};

struct SceneManager {
    char pad0[0x31C];
    int layout;
};

extern "C" {
    unsigned long OSGetTick();
    void srandi__Fl(long);
    void fn_8004D010(void*);
    SceneManager* getInstance__14gfSceneManagerFv();
    extern void* g_GameGlobal;
    extern Application* g_gfApplication;
    void fn_1_22134(Scene* self);
}

void fn_1_22134(Scene* self) {
    self->state = 2;
    self->value = 0;
    srandi__Fl(OSGetTick());
    fn_8004D010(g_GameGlobal);
    self->flag = g_gfApplication->flag != 0;
    g_gfApplication->flag = 0;
    switch (getInstance__14gfSceneManagerFv()->layout) {
    case 0:
    default:
        self->mode = 0;
        break;
    case 1:
        self->mode = 1;
        break;
    }
}
