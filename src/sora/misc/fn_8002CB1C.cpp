#pragma force_active on

struct gfScene {
    int id;
};

struct gfModuleManager;

extern "C" bool isLoaded__15gfModuleManagerFPCc(gfModuleManager*, const char*);
extern "C" int strcmp(const char*, const char*);

extern gfModuleManager* lbl_805A0038;

struct LoadRequest {
    const char* name;
    int scene;
    bool flag;
    unsigned char state;
    unsigned char pad[2];
};

struct SceneManager {
    unsigned char pad[0x290];
    LoadRequest requests[11];

    bool pendingUnload(const char* name) {
        for (int i = 0; i < 11; ++i) {
            if (requests[i].name && requests[i].state == 3 &&
                strcmp(requests[i].name, name) == 0) {
                return true;
            }
        }
        return false;
    }

    void addLoad(const char* name, int scene, bool flag) {
        for (int i = 0; i < 11; ++i) {
            if (!requests[i].name) {
                requests[i].name = name;
                requests[i].scene = scene;
                requests[i].flag = flag;
                requests[i].state = 1;
                break;
            }
        }
    }
};

extern SceneManager* lbl_805A0060;

extern "C" bool setLoadModule__7gfSceneFPCcb(
    gfScene* self, const char* name, bool flag
) {
    if (!isLoaded__15gfModuleManagerFPCc(lbl_805A0038, name) ||
        lbl_805A0060->pendingUnload(name) == true) {
        lbl_805A0060->addLoad(name, self->id, flag);
        return true;
    }
    return false;
}
