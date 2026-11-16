#include <types.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_3d_scene.h>
#include <gf/gf_heap_manager.h>
#include <gf/gf_keep_fb.h>
#include <snd/snd_system.h>
#include <mu/mu_object.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <string.h>
#pragma force_active on

struct Self {
    char pad0[0x40];
    int state;
    int result;
    char pad48[0xF8-0x48];
    void* window;
    void* scn;
    char pad100[0x7D160-0x100];
    int index;
    int sort;
    int toggle;
    int mode;
    int reset;
    char pad7D174[0x7D528-0x7D174];
    int selection;
    char pad7D52C[2];
    u8 level;
    char pad7D52F[0x7D554-0x7D52F];
    MuObject* objects[20];
    char pad7D5A4[0x7D684-0x7D5A4];
    nw4r::g3d::ScnGroup* group;
    char pad7D688[0x7D6A0-0x7D688];
    char res[0xC4500-0x7D6A0];
    int error;
    char padC4504[0xC4588-0xC4504];
    int condition;
    char padC458C[0xC4644-0xC458C];
    int stateFlag;
    void* msg;
};
struct Tbl { int v[7]; };
extern "C" {
extern gfKeepFrameBuffer* lbl_805A0008;
extern const unsigned char lbl_5_data_48[];
extern const Tbl lbl_5_rodata_228;
void fn_5_11924(void*, gfPadStatus*, int);
void fn_800B5854(void*, int, int, int, int);
void fn_5_4080(void*);
void fn_5_49A4(void*, int);
void fn_5_66B0(void*, int, int);
void fn_5_718C(void*);
void fn_5_9F94(void*, int, int);
int fn_5_11624(void*);
void fn_8000D07C(void*, int);
void fn_8000D7B8(void*);
void fn_800BA2E8();
void* fn_801AB6CC(void*, unsigned int*, int);
void* getMsgData__5MuMsgFUlPPv(void*, unsigned long, u32*);
void* fn_800BF048(int, void*, unsigned long, void*, void*, int, int, int, int, int, int, int);
}
template<class T> static inline T& at(void* p, unsigned long off) { return *(T*)((char*)p + off); }
static inline void se(int id) { g_sndSystem->playSE((SndID)id, -1, 0, 0, -1); }
static inline void drainNode(nw4r::g3d::ScnGroup* p) {
    int c;
    while ((c = p->sceneItemsCount) != 0) {
        if (c != 0) p->Remove((u32)(c - 1));
    }
}
extern "C" void fn_5_8D44(Self* self) {
    int var31 = 0;
    int var30 = 0;
    int var29;
    int var28 = 0;
    unsigned int heapTmp;
    u32 msgSize;
    Tbl tbl = lbl_5_rodata_228;
    gfPadStatus status;
    char buf[0x100];
    g_gfPadSystem->getSysPadStatus(0xF0, &status);
    fn_5_11924(self, &status, 0);
    u32 pb = status.m_buttonsPressedThisFrame.bits;
    if (pb & 0x200) {
        se(0);
        fn_800B5854(self->objects[10], 1, 0x11, 1, 0);
        self->state = 8;
        var31 = 1;
    } else if (pb & 0x10) {
        se(0x1D98);
        int nc = (self->sort + 1) % 4;
        self->sort = nc;
        fn_800B5854(self->objects[19], nc, 0x13, 1, 0);
        self->reset = 0;
        drainNode(self->group);
        fn_5_4080(self);
        fn_5_49A4(self, 1);
    } else {
        u32 pb2 = status.m_buttonsPressedThisFrame2.bits;
        if (pb2 & 8) {
            se(0);
            fn_5_718C(self);
            fn_5_9F94(self, 3, 0);
            self->state = 4;
            var31 = 1;
        } else if (pb2 & 1) {
            if (self->selection != 0) {
                se(0);
                var30 = 1;
                var29 = self->selection - 1;
            }
        } else if (pb2 & 2) {
            if (self->selection != 6) {
                se(0);
                var30 = 1;
                var29 = self->selection + 1;
            }
        } else if (pb & 0x800) {
            if (self->error != 3) {
                int state = 0x13;
                if (self->selection == 2) state = 0x14;
                self->state = state;
            } else se(3);
        } else if (pb & 0x100) {
            switch (self->selection) {
            case 0: case 1:
                se(1); var28 = 1; break;
            case 2:
                if (self->error != 3) self->state = 0x14;
                else se(3);
                break;
            case 3:
                if (self->level != 0) {
                    se(0x1D95);
                    unsigned char old = self->level;
                    self->level = old - 1;
                    fn_5_66B0(self, 1, old);
                }
                break;
            case 4:
                if (self->level < lbl_5_data_48[self->index]) {
                    se(0x1D94);
                    unsigned char old = self->level;
                    self->level = old + 1;
                    fn_5_66B0(self, 1, old);
                }
                break;
            case 5:
                se(0x1D97);
                self->toggle = (self->toggle == 0);
                self->reset = 0;
                drainNode(self->group);
                fn_5_4080(self);
                fn_5_49A4(self, 1);
                break;
            case 6:
                if (self->mode == 2) {
                    se(0x1DA1);
                    self->mode = 0;
                } else {
                    se(0x1D96);
                    self->mode = self->mode + 1;
                }
                self->objects[16]->setFrameVisible((float)self->mode);
                self->reset = 0;
                drainNode(self->group);
                fn_5_4080(self);
                fn_5_49A4(self, 1);
                fn_5_49A4(self, 1);
                break;
            }
        } else if (pb & 0x1000) {
            se(1);
            if (self->selection == 1) var28 = 1;
            else { var29 = 1; var30 = 1; }
        }
    }
    if (var28 != 0) {
        if (fn_5_11624(self) == 0) {
            self->state = 0x16;
            memset(buf, 0, 0x100);
            void* msgData = getMsgData__5MuMsgFUlPPv(self->msg, 4, &msgSize);
            memcpy(buf, msgData, msgSize);
            void* heap = gfHeapManager::getMEMAllocator((Heaps::HeapType)0x2A);
            void* scn = fn_801AB6CC(heap, &heapTmp, 1);
            self->scn = scn;
            g_gfSceneRoot->add((gfSceneRoot::LayerType)8, (nw4r::g3d::ScnMdl*)scn);
            self->window = fn_800BF048(0, buf, msgSize + 1, self->res,
                self->scn, 0x1A, 0, 0x2A, 0x2B, 0, 0, 0xF0);
        } else {
            if (self->selection == 0) se(1);
            else se(0x1D99);
            fn_800BA2E8();
            drainNode(at<nw4r::g3d::ScnGroup*>(g_gfSceneRoot, 0x450));
            drainNode(at<nw4r::g3d::ScnGroup*>(g_gfSceneRoot, 0x3C0));
            if (self->selection == 0) {
                self->stateFlag = 4;
                self->result = 3;
                self->state = 0x19;
                lbl_805A0008->startKeepScreen();
                fn_8000D07C(g_gfSceneRoot, 0);
                g_gfSceneRoot->removeResAnmScn();
                fn_8000D7B8(g_gfSceneRoot);
            } else {
                self->result = 2;
                self->state = 0x19;
                fn_8000D07C(g_gfSceneRoot, 0);
                g_gfSceneRoot->removeResAnmScn();
                fn_8000D7B8(g_gfSceneRoot);
            }
        }
    }
    if (var31 != 0 || var30 != 0) {
        int m = self->selection;
        int r4;
        if (m == 2) r4 = (self->condition == 2) ? 2 : 0;
        else if ((m == 3 && self->level == 0) ||
                 (m == 4 && self->level == lbl_5_data_48[self->index])) r4 = 3;
        else r4 = 0;
        fn_800B5854(self->objects[tbl.v[m]], r4, 0x11, 0, 0);
    }
    if (var30 != 0) {
        self->selection = var29;
        if (var29 == 6)
            self->objects[16]->setFrameVisible((float)self->mode);
        int m = self->selection;
        int r4;
        if (m == 2) r4 = (self->condition == 2) ? 3 : 1;
        else if ((m == 3 && self->level == 0) ||
                 (m == 4 && self->level == lbl_5_data_48[self->index])) r4 = 2;
        else r4 = 1;
        fn_800B5854(self->objects[tbl.v[m]], r4, 0x11, 1, 0);
    }
}
