#include <gf/gf_application.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_keep_fb.h>
#include <gf/gf_scene.h>
#include <types.h>
#pragma force_active on

extern "C" {
void fn_1_E0A0(void* self);
void fn_800B00B0(void* a, gfFileIOHandle* h);
void* fn_800C001C(void* a, void* b, void* c, int d, void* e, int f);
void Init__Q34nw4r3g3d7ResFileFPv(void* self);
void* getInstance__9itManagerFv(void);
}

struct SceneObjUnk360 {
    char pad0[0x48];
    void* unk48;
};

struct SceneObj {
    char pad0[0x35C];
    int state;
    SceneObjUnk360* unk360;
    void* unk364;
    void* unk368;
    void* unk36C;
    char pad1[0x434 - 0x370];
    gfFileIOHandle handles[3];
};

extern "C" int fn_1_E268(SceneObj* self) {
    switch (self->state) {
    case 0: {
        int i = 0;
        gfFileIOHandle* h = self->handles;
        int ok;
        for (; i < 3; i++, h++) {
            if (!h->isReady()) {
                ok = 0;
                goto done;
            }
        }
        ok = 1;
    done:
        if (ok) {
            self->state = 2;
        }
        break;
    }
    case 1:
        self->state = 2;
        break;
    case 2: {
        void* var30 = 0;
        void* buf;
        void* sp8;
        void* b2;
        void* it;
        fn_800B00B0(self->unk360, &self->handles[2]);
        self->handles[2].release();
        sp8 = 0;
        if (self->handles[0].getReturnStatus() == 0x15) {
            buf = 0;
        } else {
            buf = self->handles[0].getBuffer();
            self->handles[0].release();
        }
        if (buf != 0) {
            sp8 = buf;
            Init__Q34nw4r3g3d7ResFileFPv(&sp8);
        }
        self->unk364 = sp8;
        if (self->handles[1].getReturnStatus() == 0x15) {
            b2 = 0;
        } else {
            b2 = self->handles[1].getBuffer();
            self->handles[1].release();
        }
        self->unk368 = b2;
        it = getInstance__9itManagerFv();
        {
            void* p = *(void**)((char*)it + 0x14B8);
            if (p != 0) {
                var30 = *(void**)((char*)p + 4);
            }
        }
        self->unk36C = fn_800C001C(&self->unk364, self->unk368, self->unk360->unk48, 1, var30, 0xA);
        fn_1_E0A0(self);
        g_gfApplication->unkD0.endKeepScreen();
        self->state = 3;
        break;
    }
    case 3: {
        gfSceneManager* mgr = (gfSceneManager*)self->unk36C;
        if (*(int*)((char*)mgr + 0x10C) == 5) {
            gfSceneManager* m = gfSceneManager::getInstance();
            m->unk1 = 0;
            m->processStep = 2;
        }
        break;
    }
    }
    return 0;
}
