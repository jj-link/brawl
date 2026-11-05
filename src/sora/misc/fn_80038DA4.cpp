#include <gf/gf_file_io_handle.h>
#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

struct Context {
    char pad0[0x44];
    gfFileIOHandle handle;
    char pad48[0x14];
    unsigned char done;
    char pad5d[3];
    int result;
    char pad64[0x8c];
    unsigned int command;
};
struct State {
    char pad[8];
    unsigned char flag;
};
extern "C" {
extern OSMutex lbl_80497740;
extern State lbl_804976D8;
int fn_8003A23C(Context*, void*);
int fn_8003A6F0(Context*, void*);
int fn_8003AD48(Context*, void*);
int fn_8003B760(Context*, void*);
int fn_8003BBDC(Context*, void*);
int fn_8003C000(Context*, void*);
int fn_8003C4E4(Context*, void*, int, int);
int fn_8003C934(Context*, void*);

void fn_80038DA4(Context* self) {
    OSLockMutex(&lbl_80497740);
    while (!self->handle.isReady()) {
        OSSleepTicks((OS_BUS_CLOCK_SPEED / 4) / 1000);
    }
    self->result = -1;
    switch (self->command) {
    case 1:
        self->result = fn_8003A23C(self, &self->command);
        break;
    case 2:
        lbl_804976D8.flag = 0;
        self->result = fn_8003A6F0(self, &self->command);
        lbl_804976D8.flag = 1;
        break;
    case 3:
        self->result = fn_8003AD48(self, &self->command);
        break;
    case 4:
        self->result = fn_8003B760(self, &self->command);
        break;
    case 5:
        self->result = fn_8003BBDC(self, &self->command);
        break;
    case 6:
        self->result = fn_8003C000(self, &self->command);
        break;
    case 7:
        self->result = fn_8003C4E4(self, &self->command, 0, 1);
        break;
    case 8:
        lbl_804976D8.flag = 0;
        self->result = fn_8003C934(self, &self->command);
        lbl_804976D8.flag = 1;
        break;
    }
    while (!self->handle.isReady()) {
        OSSleepTicks((OS_BUS_CLOCK_SPEED / 4) / 1000);
    }
    self->done = 1;
    OSUnlockMutex(&lbl_80497740);
}
}