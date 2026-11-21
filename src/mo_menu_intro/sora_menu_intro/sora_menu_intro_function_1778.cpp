#include <gf/gf_file_io_handle.h>
#include <gf/gf_application.h>
#include <gf/gf_scene.h>
#include <mu/menu.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <snd/snd_system.h>
#include <stdio.h>

#pragma force_active on

extern "C" {
void fn_13_1430(void*, const void*, int, void*);
void fn_13_C04(void*);
void fn_13_1520(void*, int);
void* __dynamic_cast(void*, long, const void*, const void*, long);
MuObject* create__8MuObjectFPPQ34nw4r3g3d7ResFileiciQ25Heaps8HeapType(
    nw4r::g3d::ResFile**, int, int, int, HeapType);

extern char lbl_13_rodata_20[];
extern char lbl_13_data_14C[];
extern char lbl_13_data_188[];
extern char lbl_13_data_1B8[];
extern float lbl_13_rodata_48;
}

struct SoundEntry {
    SndID id;
    unsigned int duration;
};

struct Intro {
    char pad0[0x40];
    void* res40;
    char pad44[0x18];
    nw4r::g3d::ResFile* res5c;
    MuObject* object60;
    char pad64[0xc];
    MuObject* object70;
    char pad74[0x38];
    int choice;
    int mode;
    char padb4[0x30];
    int state;
    gfFileIOHandle handles[8];
    unsigned char loaded;
    char pad109[3];
    SoundEntry sounds[16];
    int soundCount;
    int soundIndex;
    int soundFrame;

    int readyFiles();
};

#define SCENE \
    ((char*)__dynamic_cast(gfSceneManager::getInstance()->m_currentScene, \
                           4, lbl_13_data_188, lbl_13_data_1B8, 0))

#define GROUP(s) \
    (*(nw4r::g3d::ScnGroup**)(*(char**)(*(char**)((s) + 0x398)) + 0x48))

inline int Intro::readyFiles() {
    gfFileIOHandle* h = handles;
    for (int i = 0; i < 8; ++i, ++h) {
        if (!h->isReady())
            return false;
    }
    return muMenu::isLoadFinishMenuSound();
}

inline void updateSound(Intro* self) {
    SoundEntry* sound = &self->sounds[self->soundIndex];

    if (self->soundFrame <= 0)
        g_sndSystem->playSE(sound->id, -1, 0, 0, -1);

    ++self->soundFrame;
    if ((unsigned int)self->soundFrame >= sound->duration) {
        ++self->soundIndex;
        if (self->soundIndex < self->soundCount)
            self->soundFrame = 0;
    }

    if (self->soundIndex >= self->soundCount) {
        SCENE;
        gfSceneManager* mgr = gfSceneManager::getInstance();
        mgr->unk1 = 0;
        mgr->processStep = 2;
    }
}

inline void loadResource(gfFileIOHandle* handle, void*& resource) {
    resource = 0;
    void* buffer;
    if (handle->getReturnStatus() == 0x15)
        buffer = 0;
    else {
        buffer = handle->getBuffer();
        handle->release();
    }
    if (buffer) {
        resource = buffer;
        nw4r::g3d::ResFile::Init(&resource);
    }
}

inline void setIntroAnimation(MuObject* obj, const char* name) {
    obj->changeNodeAnimNIf(name);
    obj->changeVisAnimNIf(name);
    obj->changeTexPatAnimNIf(name);
    obj->changeClrAnimNIf(name);
    obj->m_modelAnim->setUpdateRate(lbl_13_rodata_48);
}

inline void setupIntro(MuObject* obj, int choice) {
    char name[32];
    sprintf(name, lbl_13_data_14C, choice + 1);
    setIntroAnimation(obj, name);
    nw4r::g3d::ScnMdl* model = obj->m_sceneModel;
    nw4r::g3d::ScnGroup* group = GROUP(SCENE);
    group->Insert(group->sceneItemsCount, model);
}

inline void insertObject(MuObject* obj) {
    nw4r::g3d::ScnMdl* model = obj->m_sceneModel;
    nw4r::g3d::ScnGroup* group = GROUP(SCENE);
    group->Insert(group->sceneItemsCount, model);
}

inline void startIntroRumble() {
    int controller = *(unsigned char*)(SCENE + 0x39d);
    if (controller == 0x78)
        controller = -1;
    muMenu::startRumbleController(
        *(int*)(SCENE + 0x394), 0x14, controller);
}

extern "C" void fn_13_1778(Intro* self) {
    if (!self->loaded) {
        void* rc;
        void* r8;
        int i = 0;
        gfFileIOHandle* h = self->handles;
        int ready;
        for (; i < 8; ++i, ++h) {
            if (!h->isReady()) {
                ready = 0;
                goto not_ready;
            }
        }
        ready = muMenu::isLoadFinishMenuSound();
    not_ready:
        if (!ready)
            return;

        loadResource(&self->handles[0], r8);

        self->res40 = r8;
        fn_13_1430(self, lbl_13_rodata_20, 1, &self->res40);

        int n = -1;
        if (self->mode >= 2)
            n = self->mode - 2;

        if (n < 0) {
            fn_13_C04(self);
        } else {
            loadResource(&self->handles[5], rc);

            self->res5c = (nw4r::g3d::ResFile*)rc;
            self->object70 =
                create__8MuObjectFPPQ34nw4r3g3d7ResFileiciQ25Heaps8HeapType(
                    &self->res5c, 0x12, 0, 0, (HeapType)0x2a);
        }

        g_gfApplication->unkD0.endKeepScreen();

        setupIntro(self->object60, self->choice);

        int n2 = -1;
        if (self->mode >= 2)
            n2 = self->mode - 2;

        if (n2 < 0) {
            fn_13_1520(self, self->choice);
        } else {
            MuObject* obj = self->object70;
            obj->m_modelAnim->m_anmObjChrRes->SetUpdateRate(
                lbl_13_rodata_48);
            obj->m_modelAnim->m_anmObjMatClrRes->SetUpdateRate(
                lbl_13_rodata_48);
            insertObject(obj);
        }

        startIntroRumble();
        g_sndSystem->playSE((SndID)0x2b, -1, 0, 0, -1);
        self->state = 0;
        self->loaded = 1;
    } else {
        updateSound(self);
    }
}
