#pragma force_active on
#include <gf/gf_heap_manager.h>
#include <st/st_melee.h>
#include <snd/snd_3d_generator.h>

extern "C" {
void fn_85_3924(void*, void*);
void fn_27_232C18(void*);
void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
void* fn_27_22A914(void*);
void fn_27_22AB74(void*);
void __destroy_arr(void*, void (*)(void*, int), unsigned long, unsigned long);
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__7stMeleeFv(void*, int);
void __dl__FPv(void*);
extern void* lbl_27_bss_5780;
extern char lbl_85_data_438[];
}

struct Entry { char data[0x18]; };
struct Object {
    char pad0[0xa0];
    void* a0;
    char padA4[0x141];
    unsigned char flag1e5;
    unsigned char flag1e6;
    char pad1e7[0x9];
    void* p1f0;
    void* p1f4;
    void* p1f8;
    void* p1fc;
    void* p200;
    void* p204;
    int soundCount;
    int handles[8];
    snd3DGenerator sounds[8];
    char pad26C[0x54];
    unsigned int count;
    char pad2C4[0x230];
    Entry entries[1];
};

extern "C" void* fn_85_1A4(void* self_, int arg1) {
    Object* self = (Object*)self_;
    unsigned int i;
    Entry* entry;
    if (self_) {
        unsigned int count = self->count;
        *(void**)((char*)self + 0x3c) = (void*)lbl_85_data_438;
        if (count) {
            if (self->p1f4) {
                gfHeapManager::free(self->p1f4);
                self->p1f4 = 0;
                self->flag1e6 = 0;
            }
            if (self->p1f8) {
                gfHeapManager::free(self->p1f8);
                self->p1f8 = 0;
            }
            if (self->p1fc) {
                gfHeapManager::free(self->p1fc);
                self->p1fc = 0;
            }
            if (self->p200) {
                gfHeapManager::free(self->p200);
                self->p200 = 0;
            }
            if (self->p204) {
                gfHeapManager::free(self->p204);
                self->p204 = 0;
            }
            entry = self->entries;
            for (i = 0; i < count; ++i, ++entry)
                fn_85_3924(self, entry);
            self->count = 0;
            fn_27_232C18(self->a0);
            if (lbl_27_bss_5780 == 0) {
                void* p = __nw__FUlQ25Heaps8HeapType(0x54, 2);
                if (p != 0) {
                    p = fn_27_22A914(p);
                }
                lbl_27_bss_5780 = p;
            }
            fn_27_22AB74(lbl_27_bss_5780);
        }
        Object* cursor = self;
        snd3DGenerator* sound = self->sounds;
        int j = 0;
        for (; j < self->soundCount; ++j) {
            sound->stopSE(cursor->handles[0], 0);
            cursor = (Object*)((char*)cursor + 4);
            sound++;
        }
        self->soundCount = 0;
        if (self->p1f0) {
            gfHeapManager::free(self->p1f0);
            self->p1f0 = 0;
            self->flag1e5 = 0;
        }
        if (self->p1f4) {
            gfHeapManager::free(self->p1f4);
            self->p1f4 = 0;
            self->flag1e6 = 0;
        }
        if (self->p1f8) {
            gfHeapManager::free(self->p1f8);
            self->p1f8 = 0;
        }
        if (self->p1fc) {
            gfHeapManager::free(self->p1fc);
            self->p1fc = 0;
        }
        if (self->p200) {
            gfHeapManager::free(self->p200);
            self->p200 = 0;
        }
        if (self->p204) {
            gfHeapManager::free(self->p204);
            self->p204 = 0;
        }
        ((stCommonGimmick*)self)->releaseArchive();
        __destroy_arr(self->sounds, __dt__14snd3DGeneratorFv, 8, 8);
        __dt__7stMeleeFv(self, 0);
        if (arg1 > 0) {
            __dl__FPv(self);
        }
    }
    return self_;
}