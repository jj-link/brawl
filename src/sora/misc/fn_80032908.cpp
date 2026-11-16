#include <gf/gf_file_io_handle.h>
#include <gf/gf_shutdown_manager.h>
#include <string.h>
#include <types.h>

#pragma force_active on

struct Entry {
    int id;
    char name[14];
    unsigned char flag;
    char pad13;
};

struct Self {
    char pad0[8];
    gfFileIOHandle handle;
    char pad1[0xA0 - 8 - sizeof(gfFileIOHandle)];
    int a0;
    char pad2[0xF0 - 0xA4];
    int f0;
    int f4;
    char padF8[2];
    unsigned char faByte;
    char padFB[5];
    int f100;
    int f104;
    char pad108[4];
    void* f10c;
    int f110;
};

extern "C" {
extern Entry lbl_80422F70[];
extern char lbl_80422FD4[];
extern char lbl_8059C670[7];
void fn_801FB1DC();
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

static inline bool isShuttingDown() {
    if (g_gfShutdownManager.unkD == true || g_gfShutdownManager.unkC) {
        return false;
    }
    bool result = false;
    if (g_gfShutdownManager.m_reset || g_gfShutdownManager.m_powerOff || g_gfShutdownManager.m_returnToWiiMenu) {
        result = true;
    }
    return result;
}

extern "C" void fn_80032908(Self* self) {
    char path[0x80];
    switch (self->f4) {
    case 0: {
        Entry* found = findEntry(self->f104);
        if (found == NULL) {
            self->f0 = 0;
            self->a0 = 3;
            return;
        }
        int idx = self->f100;
        strcpy(path, lbl_8059C670);
        strcat(path, found->name);
        if (found->flag != 0) {
            strcat(path, lbl_80422FD4 + idx * 6);
        }
        int size = 0;
        if (self->f104 == 1) {
            size = self->f110 * self->faByte;
        }
        self->handle.writeRequest(path, self->f10c, self->f110, size);
        self->f4 = 1;
        return;
    }
    case 1: {
        if (self->handle.isReady()) {
            if (self->handle.getReturnStatus() == 0) {
                self->f4 = 2;
                return;
            }
            self->f0 = 0;
            self->a0 = 3;
            return;
        }
        if (isShuttingDown()) {
            fn_801FB1DC();
        }
        return;
    }
    case 2: {
        Entry* found = findEntry2(self->f104);
        if (found->flag != 0) {
            if (self->f100 == 0) {
                self->f100++;
                self->f4 = 0;
                return;
            }
        }
        self->f0 = 0;
        self->a0 = 0;
        break;
    }
    }
}
