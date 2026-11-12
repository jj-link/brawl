#include <types.h>
#include <gf/gf_model.h>
#include <gr/collision/gr_collision_handle.h>
#include <nw4r/g3d/g3d_resmdl.h>
#pragma force_active on

class Object_vptr_0 {
public:
    virtual void slot0();
    virtual void slot1(int, int, int);
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6(int, int);
    virtual void slot7();
    virtual void slot8(float);
};

struct Entry {
    char pad00[12];
    unsigned int state : 8;
    unsigned int other : 24;
    float value;
    char pad14[8];
    Object_vptr_0* model;
    char pad20[2];
    u16 node;
};

struct Resource {
    char pad00[12];
    char* data;
};

struct TableEntry {
    char pad00[20];
    u32 field14;
    u32 field18;
};

struct AnimResource {
    char pad00[4];
    u8 count;
    char pad05[11];
};

struct AnimEntry {
    u32 name;
    u32 field04;
    u16 frame;
    u16 field0a;
    u32 data;
};

struct FlagBits {
    u16 hi : 6;
    u16 b9 : 1;
    u16 b8 : 1;
    u16 lo : 8;
};

struct Record {
    char pad00[0x24];
    int state;
    int frame;
    int index;
    Resource* resource;
    Entry** entries;
    u32 count;
    int timer;
    int field40;
    Object_vptr_0* model;
    gfModelAnimation* anim;
    void* effect;
    char pad50[6];
    u16 flags;
    u8 mode;
    u8 delay;
    u8 frameCount;
    u8 frameMax;
    grCollisionHandle collision;
    int collisionEnabled;
    void* collisionData;
    char pad6c[4];
    void (*callback)(Object_vptr_0*, void*);
    void* callbackArg;
    char pad78[4];
    int result;
};

extern "C" {
void fn_80062954(Record*, int, int);
void fn_8005A98C(Entry*);
Entry* fn_8005C650(void*, u8);
int fn_8005C8F0(Entry*);
void fn_8005C9B4(Entry*);
void fn_8006242C(Record*);
void fn_80062734(Record*, int);
void fn_8006526C(void*, int);
void fn_801AF9F4(void*);
void nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(void*, bool);
void* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(
    const nw4r::g3d::ResMdl*, const char*);
}

extern const float lbl_805A1958;
extern float lbl_805A195C;

extern "C" int fn_80061944(Record* self, float rate) {
    TableEntry* table =
        (TableEntry*)(self->resource->data + self->index * 16);
    AnimResource* res;
    u32 offset;
    union {
        u32 off;
        Entry* entry;
    } work;
    int waiting = 0;

    if (self->collisionEnabled) {
        if (!self->collision.isValid()) {
            fn_80062954(self, 1, 1);
        } else {
            void* col = *(void**)((char*)self + 0x5c);
            if (!((*(u8*)((char*)col + 0x2c) >> 7) & 1) ||
                !((*(u8*)((char*)self->collisionData + 0x54) >> 4) & 1)) {
                fn_80062954(self, 1, 1);
            } else if (*(int*)((char*)col + 0x10) == 0) {
                fn_80062954(self, 1, 1);
            }
        }
    }

    if (self->mode & 1) {
        if (self->mode & 2) {
            self->mode = 0;
            for (u32 i = 0; i < self->count; ++i) {
                Entry* entry = self->entries[i];
                if (entry)
                    entry->state = 2;
            }
        }
    } else if (self->mode & 4) {
        self->mode = 1;
        for (u32 i = 0; i < self->count; ++i) {
            if (self->entries[i])
                fn_8005A98C(self->entries[i]);
        }
    }

    if (!(self->mode & 1)) {
        if (self->delay) {
            --self->delay;
            waiting = 1;
        } else {
            if (self->frameCount != self->frameMax) {
                self->frameCount = self->frameMax;
                if (self->frameMax > 1)
                    self->delay = self->frameMax - 1;
                for (u32 i = 0; i < self->count; ++i) {
                    if (self->entries[i])
                        *((u8*)self->entries[i] + 0x0f) = self->frameCount;
                }
            } else if (self->frameCount > 1) {
                self->delay = self->frameCount - 1;
            }

            if ((u32)self->state < 2 && (self->mode & 0x28) != 8 &&
                self->model && table->field18) {
                u32 i = 0;
                offset = 0;
                res = (AnimResource*)(self->resource->data + table->field18);
                AnimEntry* item = (AnimEntry*)((char*)res + 0x10);
                for (; i < res->count;
                     offset += 4, ++i, item = (AnimEntry*)((char*)item + 0x10)) {
                    if (item->frame == self->frame && item->data) {
                        *(Entry**)((char*)self->entries + offset) =
                            fn_8005C650((char*)res + item->data,
                                (self->flags & 0x100) ? 2
                                    : (((FlagBits*)&self->flags)->b9 ^ 1));
                        if (*(Entry**)((char*)self->entries + offset)) {
                            if (self->flags & 0x400)
                                *((u8*)*(Entry**)((char*)self->entries + offset) + 0x0d) |= 0x20;

                            const char* name = (const char*)res + item->name;
                            work.entry = *(Entry**)((char*)self->entries + offset);
                            Object_vptr_0* model = self->model;
                            work.entry->model = model;
                            void* resource = *(void**)((char*)model + 0xe8);
                            void* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(
                                (nw4r::g3d::ResMdl*)&resource, name);
                            work.entry->node = node ? *(u32*)((char*)node + 0x0c) : 0;

                            if (self->flags & 0x8000)
                                *((u8*)*(Entry**)((char*)self->entries + offset) + 0x0d) &= ~0x40;
                            *((u8*)*(Entry**)((char*)self->entries + offset) + 0x0f) = self->frameCount;
                        }
                    }
                }
            }
        }
    }

    if (self->frameCount > 1)
        rate *= lbl_805A195C / (float)self->frameCount;

    switch (self->state) {
    case 0:
        if ((self->mode & 0x28) != 8) {
            if (!waiting && !(self->mode & 1) && self->frame >= 0) {
                if (self->model && !(self->flags & 0x8000)) {
                    nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(
                        self->model, true);
                    if (self->effect)
                        fn_8006526C(self->effect, 1);
                }
                if (table->field14 && self->entries) {
                    Entry* entry = self->entries[self->count - 1];
                    if (entry) {
                        entry->state = 1;
                        entry->value = lbl_805A1958;
                        if (self->flags & 0x8000)
                            *((u8*)self->entries[self->count - 1] + 0x0d) &= ~0x40;
                    }
                }
                fn_8006242C(self);
                self->state = 1;
            }
            break;
        }
        self->state = 1;
    case 1: {
        if (self->mode & 0x20) {
            if (self->entries) {
                for (u32 i = 0; i < self->count; ++i) {
                    if (self->entries[i])
                        fn_8005C9B4(self->entries[i]);
                }
            }
            self->mode &= ~0x20;
        }

        int finished = 1;
        if (!(self->mode & 0x10)) {
            fn_8006242C(self);
            if (self->model) {
                if (self->timer) {
                    if (self->mode & 1) {
                        if (self->anim && !(self->flags & 0x7e))
                            self->anim->setUpdateRate(lbl_805A1958);
                    } else {
                        if (self->anim) {
                            if (!(self->flags & 0x7e)) {
                                self->anim->setUpdateRate(rate);
                            } else {
                                if (!(self->flags & 2) && self->anim->m_anmObjChrRes)
                                    self->anim->m_anmObjChrRes->SetUpdateRate(rate);
                                if (!(self->flags & 4) && self->anim->m_anmObjVisRes)
                                    self->anim->m_anmObjVisRes->SetUpdateRate(rate);
                                if (!(self->flags & 8) && self->anim->m_anmObjTexPatRes)
                                    self->anim->m_anmObjTexPatRes->SetUpdateRate(rate);
                                if (!(self->flags & 0x10) && self->anim->m_anmObjTexSrtRes)
                                    self->anim->m_anmObjTexSrtRes->SetUpdateRate(rate);
                                if (!(self->flags & 0x20) && self->anim->m_anmObjMatClrRes)
                                    self->anim->m_anmObjMatClrRes->SetUpdateRate(rate);
                                if (!(self->flags & 0x40) && self->anim->m_anmObjShpRes)
                                    self->anim->m_anmObjShpRes->SetUpdateRate(rate);
                            }
                        }
                        if (waiting) {
                            finished = 0;
                        } else if (self->timer > 0) {
                            if (--self->timer > 0)
                                finished = 0;
                        } else if (self->timer < 0) {
                            finished = 0;
                        }
                    }

                    fn_801AF9F4(self->model);
                    self->model->slot6(2, 0);
                    self->model->slot1(1, 0, 0);
                    self->model->slot6(2, 1);
                    if ((self->flags & 0x80) && self->callback)
                        self->callback(self->model, self->callbackArg);
                }

                if (!self->timer) {
                    nwSMSetVisibility__FPQ34nw4r3g3d12ScnMdlSimpleb(
                        self->model, false);
                    if (self->effect)
                        fn_8006526C(self->effect, 0);
                }
            }
        }

        if (!(self->mode & 1)) {
            if (self->entries) {
                for (u32 i = 0; i < self->count; ++i) {
                    if (self->entries[i] && fn_8005C8F0(self->entries[i])) {
                        finished = 0;
                        break;
                    }
                }
            }
            if (finished) {
                self->state = 2;
                self->mode |= 0x10;
            }
        }
        break;
    }
    case 3:
        fn_80062734(self, 1);
        self->result = 0;
        return 1;
    default:
        break;
    }

    if (!waiting && !(self->mode & 1))
        ++self->frame;
    return 0;
}
