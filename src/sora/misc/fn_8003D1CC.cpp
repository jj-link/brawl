#include <gf/gf_heap_manager.h>
#include <revolution/OS/OSMutex.h>
#include <string.h>
#pragma force_active on

struct State {
    char pad[0x340];
    char key[0x10];
    char* input;
    unsigned int size;
    Heaps::HeapType heap;
    int mode;
    unsigned char done;
    char pad361[3];
    int result;
    char* output;
    unsigned int outputSize;
};

extern "C" {
extern OSMutex* lbl_805A00B0;

void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
int fn_80211080();
void fn_802110D4();
int fn_8021188C(int, void*, void*, unsigned int, void*);
int fn_80211924(int, void*, void*, unsigned int, void*);

void fn_8003D1CC(State* self, char* buffer) {
    if (self->mode != 0) {
        self->result = -1;
        self->outputSize = self->size;
        if (self->mode == 1 && (self->size & 15))
            self->outputSize = self->size + (16 - (self->size & 15));

        buffer = (char*)gfHeapManager::alloc(self->heap, 0x4000, 0x40);
        self->output = (char*)gfHeapManager::alloc(self->heap, self->outputSize, 0x40);

        if (buffer && self->output) {
            if (!lbl_805A00B0) {
                OSMutex* mutex = (OSMutex*)__nw__FUlQ25Heaps8HeapType(0x18, 2);
                if (mutex)
                    OSInitMutex(mutex);
                lbl_805A00B0 = mutex;
            }

            OSLockMutex(lbl_805A00B0);
            if (fn_80211080() == 0) {
                unsigned int offset;
                unsigned int total = self->outputSize;
                int error = 0;
                unsigned int count = total >> 14;
                if (total & 0x3fff)
                    count++;
                unsigned int i = 0;
                offset = 0;

                for (; i < count; offset += 0x4000, i++) {
                    unsigned int chunk = 0x4000;
                    if ((i + 1) * 0x4000 > self->outputSize) {
                        chunk = self->outputSize - offset;
                        memset(buffer, 0, 0x4000);
                        memcpy(buffer, self->input + offset, self->size - offset);
                    } else {
                        memcpy(buffer, self->input + offset, 0x4000);
                    }

                    if (self->mode == 1) {
                        if (fn_8021188C(6, self->key, buffer, chunk,
                                        self->output + offset)) {
                            error = 1;
                            break;
                        }
                    } else {
                        if (fn_80211924(6, self->key, buffer, chunk,
                                        self->output + offset)) {
                            error = 1;
                            break;
                        }
                    }
                }

                if (!error)
                    self->result = 0;
                fn_802110D4();
            }
            OSUnlockMutex(lbl_805A00B0);
        } else {
            self->result = -2;
        }

        if (self->result != 0 && self->output) {
            gfHeapManager::free(self->output);
            self->output = 0;
        }
        if (buffer)
            gfHeapManager::free(buffer);
        self->done = 1;
    }
}
}
