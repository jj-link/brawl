#pragma force_active on
#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <string.h>

struct Entry {
    int id;
    char name[12];
    u16 unk10;
    u8 hasSub;
    u8 unk13;
};

struct Loader {
    u8 pad0[8];
    gfFileIOHandle handle;
    u8 pad1[0x94];
    int status;
    u8 pad2[0x4C];
    int result;
    int state;
    u8 pad3[2];
    u8 fa;
    u8 pad4[5];
    int counter;
    int id;
    int heap;
};

extern "C" {
extern Entry lbl_80422F70[];
extern char lbl_8059C670[7];
extern char lbl_80422FD4[];
int fn_8004EAEC();
int fn_8004EAF8(void* p);
int fn_8004EFA0();
u32 NETCalcCRC32(void* data, s32 len);
}

static unsigned int calc(int mode, unsigned int n) {
    unsigned int size = 0;
    if (mode == 0 || mode == 2) {
        size = n + 4;
        if (size & 31) size += 32 - (size & 31);
    } else if (mode == 1) {
        size = (n + 4) * 51;
        if (size & 31) size += 32 - (size & 31);
    }
    return size;
}

static inline Entry* findEntry(int id) {
    Entry* found = 0;
    Entry* p = lbl_80422F70;
    int i = 0;
    for (int n = 5; n > 0; n--) {
        if (id == p->id) {
            found = &lbl_80422F70[i];
            break;
        }
        p++;
        i++;
    }
    return found;
}

static inline Entry* findEntry2(int id) {
    Entry* p = lbl_80422F70;
    Entry* found = 0;
    int i = 0;
    for (int n = 5; n > 0; n--) {
        if (id == p->id) {
            found = &lbl_80422F70[i];
            break;
        }
        p++;
        i++;
    }
    return found;
}

static inline void makePath(char* path, Entry* entry, Loader* self) {
    int counter = self->counter;
    strcpy(path, lbl_8059C670);
    strcat(path, entry->name);
    if (entry->hasSub != 0) {
        strcat(path, lbl_80422FD4 + counter * 6);
    }
}

static unsigned int getDataSize(Loader* self, int id) {
    unsigned int size = 0;
    if (id == 0) {
        size = calc(self->id, fn_8004EAEC());
    } else if (id == 2) {
        size = calc(self->id, 0x2804);
    } else if (id == 1) {
        size = fn_8004EFA0() + 4;
    }
    return size;
}

extern "C" void fn_80032B64(Loader* self) {
    char path[0x80];
    int off;

    switch (self->state) {
    case 0: {
        Entry* entry = findEntry(self->id);
        if (entry == 0) {
            self->result = 0;
            self->status = 3;
            break;
        }
        makePath(path, entry, self);
        unsigned int size = 0;
        off = 0;
        if (self->id == 0) {
            size = calc(self->id, fn_8004EAEC());
        } else if (self->id == 2) {
            size = calc(self->id, 0x2804);
        } else if (self->id == 1) {
            size = fn_8004EFA0() + 4;
            off = size * self->fa;
        }
        if (size == 0) {
            self->result = 0;
            self->status = 3;
            break;
        }
        self->handle.readRequest(path, (Heaps::HeapType)self->heap, size, off);
        self->state = 1;
        break;
    }
    case 1: {
        if (!self->handle.isReady()) {
            break;
        }
        if (self->handle.getReturnStatus() == 0) {
            int id = self->id;
            unsigned int size = getDataSize(self, id);
            unsigned int total = self->handle.getSize();
            void* buf = self->handle.getBuffer();
            if (size <= total && (total = *(unsigned int*)(size + (unsigned int)buf - 4), (size = NETCalcCRC32(buf, size - 4), size == total))) {
                self->result = 0;
                self->status = 0;
                if (id == 0 && fn_8004EAF8(buf) == 0) {
                    self->result = 0;
                    self->status = 3;
                    gfHeapManager::free(self->handle.getBuffer());
                }
            } else {
                gfHeapManager::free(self->handle.getBuffer());
                self->state = 2;
            }
        } else {
            self->state = 2;
        }
        break;
    }
    case 2: {
        Entry* entry = findEntry2(self->id);
        if (entry->hasSub != 0) {
            if (self->counter == 0) {
                self->counter = self->counter + 1;
                self->state = 0;
                break;
            }
        }
        self->result = 0;
        self->status = 3;
        break;
    }
    }
}
