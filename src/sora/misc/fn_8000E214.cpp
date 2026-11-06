#include <gf/gf_copyefb.h>
#include <gf/gf_3d_scene_event.h>
#include <gf/gf_camera.h>
#pragma force_active on
class Class_80466320;
class Class_80466278 {
public:
virtual void fn_801AC270(); virtual void fn_801AB9D8(); virtual void fn_801AC1AC(); virtual void fn_801AC328(); virtual void fn_801AC2F8(); virtual void fn_801AB788(); virtual void fn_801AAC9C(); virtual void fn_801AAE34(); virtual void fn_801AAFDC(); virtual void fn_801AAFE8(); virtual void fn_801AAA70(); virtual void fn_801ABE70(unsigned int, Class_80466320*); virtual void fn_801ABFFC(unsigned int);
char pad[0xe0]; unsigned int count;
};
class Class_80466320 {
public:
virtual void fn_801ADE54(); virtual void fn_801AC4A8(); virtual void fn_801AD064(); virtual void fn_801ADEEC(); virtual void fn_801ADEBC(); virtual void fn_801AB788(); virtual void fn_801AAC9C(); virtual void fn_801AAE34(); virtual void fn_801AAFDC(); virtual void fn_801AAFE8(); virtual void fn_801AAA70(); virtual void fn_801ABE70(unsigned int, void*); virtual void fn_801ABFFC(unsigned int);
char pad[0xe0]; unsigned int count;
};
struct Layer { Class_80466278* a; Class_80466320* b; char pad[5]; unsigned char flags; unsigned short active; char tail[8]; };
struct Capture { unsigned char enabled; signed char index; };
struct Root { char pad0[0x64]; union { int state; struct { signed int high : 8; unsigned int low : 24; } bits; }; char pad68[0x324]; Layer layers[9]; char flags; char flags2; char pad466[2]; gfSceneRootEventList events; char pad46c[0x8c]; Capture capture[9]; };
struct Dimensions { char pad[0x34]; unsigned short w; unsigned short h; };
struct Entry { unsigned char index; char pad[3]; void* item; };
struct Queue { unsigned char count; char pad[3]; Entry entries[1]; };
extern Queue lbl_80494E00; extern void* lbl_805A0110; extern void* g_efScreen;
extern "C" {
void fn_801F55EC(int); void fn_8000F4F0(Root*); void fn_8000EB1C(Root*); void fn_8000FD34(int); Dimensions* fn_80023AC8(); void fn_80010598(unsigned short, unsigned short); void fn_801ACBEC(Class_80466278*); void fn_801ACC64(Class_80466278*); void fn_801ACD50(Class_80466278*); void fn_801A12AC(int); void fn_801ACE98(Class_80466278*); void fn_8005AD04(); void fn_8005B838(void*, int); void fn_8005DC24(void*, unsigned char); void fn_801F0AF0(); void fn_80025314();
}
extern "C" void fn_8000E214(Root* self) {
    gfCopyEFBMgr* copy = gfCopyEFBMgr::getInstance();
    fn_801F55EC(0);
    self->layers[6].flags &= ~0x10;
    self->layers[3].flags &= ~0x10;
    gfCopyEFBMgr* current = gfCopyEFBMgr::getInstance();
    if (current) {
        switch (*(unsigned char*)((char*)current + 0x68)) {
        case 1: self->layers[6].flags |= 0x10; break;
        case 2: self->layers[3].flags |= 0x10; break;
        }
    }
    if ((self->flags >> 6) & 1) fn_8000F4F0(self);
    self->events.notify(0);
    fn_8000EB1C(self);
    self->events.notify(0);
    for (unsigned int i = 0; i < 9; i++) {
        Layer* layer = &self->layers[(unsigned char)i];
        if ((unsigned char)i == 8 && self->bits.high)
            fn_8000FD34(self->state >> 24);
        if (layer->active) {
            if (copy && (unsigned char)i == 6) {
                Dimensions* d = fn_80023AC8();
                fn_80010598(d->w, d->h);
            }
            if ((layer->flags >> 6) & 1) {
                Dimensions* d = fn_80023AC8();
                fn_80010598(d->w, d->h);
            }
            if (((layer->flags >> 7) & 1) && layer->b->count) {
                layer->a->fn_801ABE70(layer->a->count, layer->b);
                fn_801ACBEC(layer->a);
                fn_801ACC64(layer->a);
                fn_801ACD50(layer->a);
                fn_801A12AC(0x7ff);
                fn_801ACE98(layer->a);
                Class_80466278* a = layer->a;
                while (a->count) {
                    if (a->count) a->fn_801ABFFC(a->count - 1);
                }
            }
        }
        if ((layer->flags >> 5) & 1) {
            if ((unsigned char)i == 0) {
                if (!lbl_805A0110) fn_8005AD04();
                fn_8005B838(lbl_805A0110, 0);
            } else if ((unsigned char)i == 4) {
                if (!lbl_805A0110) fn_8005AD04();
                fn_8005B838(lbl_805A0110, 1);
            } else if ((unsigned char)i == 7) {
                if (!lbl_805A0110) fn_8005AD04();
                fn_8005B838(lbl_805A0110, 2);
            }
        }
        if (((layer->flags >> 4) & 1) && copy && !((self->flags2 >> 5) & 1)) {
            unsigned int color = *(unsigned int*)((char*)copy + 0x6c);
            GXSetZMode(0, GX_LEQUAL, 0);
            fn_801F0AF0();
            GXColor c = *(GXColor*)&color;
            copy->drawCopyEFB(0, &c);
            GXSetZMode(1, GX_LEQUAL, 1);
        }
        fn_8005DC24(g_efScreen, (unsigned char)i);
        if (self->capture[(unsigned char)i].enabled &&
            self->capture[(unsigned char)i].index >= 0 && copy)
            copy->getEFB(self->capture[(unsigned char)i].index);
        if ((unsigned char)i == 0) fn_80025314();
    }
    Queue* entry;
    Queue* queue = &lbl_80494E00;
    if (queue->count) {
        entry = queue;
        unsigned int i = 0;
        while (i < queue->count) {
            Class_80466320* b = self->layers[entry->entries[0].index].b;
            b->fn_801ABE70(b->count, entry->entries[0].item);
            entry = (Queue*)((char*)entry + 8);
            i++;
        }
        queue->count = 0;
    }
    ((gfCamera*)gfCameraManager::getManager())->setGX();
}