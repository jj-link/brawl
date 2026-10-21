#pragma force_active on

struct CameraParam {
    float value[16];
};

struct Stage {
    unsigned char pad[0x78];
    CameraParam* current;
    unsigned char initialized;
    unsigned char pad7d[3];
    CameraParam* allocated;
};

struct Controller {
    unsigned char pad[0x94];
    unsigned char unused : 2;
    unsigned char mode : 1;
    unsigned char rest : 5;
};

struct Mode {
    unsigned char pad[0xD];
    unsigned char flags;
};

struct Global {
    unsigned char pad[8];
    Mode* mode;
};

extern Global* g_GameGlobal;
extern Controller* g_cmAIController;

extern "C" void fn_27_222C9C(Stage*, float*);
extern "C" void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);

extern "C" void initCameraParam__5StageFv(Stage* self) {
    float params[32];
    fn_27_222C9C(self, params);

    CameraParam* camera =
        (CameraParam*)__nw__FUlQ25Heaps8HeapType(0x40, 15);

    if (camera) {
        camera->value[0] = params[16];
        camera->value[1] = params[17];
        camera->value[2] = params[18];
        camera->value[3] = params[19];
        camera->value[4] = params[22];
        camera->value[5] = params[23];
        camera->value[6] = params[20];
        camera->value[7] = params[21];
        camera->value[8] = params[24];
        camera->value[9] = params[25];
        camera->value[10] = params[26];
        camera->value[14] = params[27];
        camera->value[15] = params[28];
        camera->value[13] = params[29];
        camera->value[11] = params[30];
        camera->value[12] = params[31];

        self->initialized = 1;
        self->allocated = camera;
        self->current = camera;

        g_cmAIController->mode =
            ((g_GameGlobal->mode->flags >> 3) & 3) == 2;
    }
}
