#pragma force_active on
#include <mu/mu_object.h>
#include <sr/sr_common.h>

extern "C" {
void fn_1_6D74(int, void*);
void fn_1_6D60(int, void*);
void fn_1_6DC0(int, void*);
void fn_1_6FC4(int);
void* fn_8018E204(void*, const char*);
void fn_801971D0(void*, void*);
void* getGlobalRecordMenuDatap__10GameGlobalFv(void* global);
char* strcpy(char*, const char*);
char* strcat(char*, const char*);
int sprintf(char*, const char*, ...);
}

extern void* g_GameGlobal;
extern char lbl_2_data_EF0[];
extern float lbl_2_rodata_2A0;

struct Entry {
    char pad[0x5C];
    virtual void destroy(int);
};

struct Self {
    char pad0[0x40];
    int mgr;                   // 0x40
    char pad1[0x5C];
    void* res;                 // 0xA0
    char pad2[0x44];
    MuObject* objs[117];       // 0xE8
    int idx;                   // 0x2BC
};

extern "C" void fn_2_9460(Self* self, int arg1, void* arg2) {
    char* base = lbl_2_data_EF0;
    char sp90[0x40];
    char sp50[0x40];
    char sp10[0x40];
    void* spC = 0;
    void* sp8;

    MuObject* p = self->objs[self->idx];
    if (p) {
        fn_1_6D74(self->mgr, p->m_sceneModel);
    }
    MuObject* q = self->objs[self->idx + 2];
    if (q) {
        fn_1_6D74(self->mgr, q->m_sceneModel);
    }
    fn_1_6FC4(self->mgr);

    self->res = *(void**)arg2;
    self->idx = self->idx + 1;
    if (self->idx >= 2) {
        self->idx = 0;
    }

    Entry* r = (Entry*)self->objs[self->idx];
    if (r) {
        if (r) {
            r->destroy(1);
        }
    }
    Entry* s = (Entry*)self->objs[self->idx + 2];
    if (s) {
        if (s) {
            s->destroy(1);
        }
    }

    sprintf(sp90, base + 0x2F0, arg1);
    MuObject* obj = MuObject::create((nw4r::g3d::ResFile*)&self->res, sp90, 0x10, (nw4r::g3d::ResFile*)0, (Heaps::HeapType)0x2a);
    strcpy(sp50, sp90);
    strcat(sp50, base + 0x2B4);
    obj->changeAnimN(sp50);
    if (obj->m_modelAnim) {
        obj->m_modelAnim->setUpdateRate(lbl_2_rodata_2A0);
    }
    self->objs[self->idx] = obj;
    fn_1_6D60(self->mgr, obj->m_sceneModel);
    obj->changeAnimN(sp90);

    sprintf(sp90, base + 0x308, arg1);
    MuObject* obj2 = MuObject::create((nw4r::g3d::ResFile*)&self->res, sp90, 0x18, (nw4r::g3d::ResFile*)0, (Heaps::HeapType)0x2a);
    strcpy(sp10, sp90);
    strcat(sp10, base + 0x2B4);
    obj2->changeAnimN(sp10);
    if (obj2->m_modelAnim) {
        obj2->m_modelAnim->setUpdateRate(lbl_2_rodata_2A0);
    }
    self->objs[self->idx + 2] = obj2;

    unsigned char* rec = (unsigned char*)getGlobalRecordMenuDatap__10GameGlobalFv(g_GameGlobal);
    const char* suffix;
    char* buffer = sp90;
    char* format = base + 0x324;
    sprintf(buffer, format, arg1, (suffix = base + 0x344, ((rec[0x28] >> 7) & 1) ? suffix = base + 0x33C : suffix));

    spC = fn_8018E204(&self->res, sp90);
    sp8 = spC;
    fn_801971D0(&spC, &sp8);
    fn_1_6DC0(self->mgr, &spC);
}
