#include <types.h>
#include <revolution/DVD/dvd.h>
#include <revolution/DVD/dvd_broadway.h>
#include <revolution/OS/OSInterrupt.h>
#include <revolution/OS/OSTime.h>
#pragma force_active on

typedef __typeof__(__DVDLayoutFormat) u32v;

typedef struct {
    u32 command; // at 0x0
    u32 param1;  // at 0x4
    u32 param2;  // at 0x8
    u32 intType; // at 0xC
    u32 tick;    // at 0x10
} CmdInfo;

typedef struct {
    u8 pad[0x1c];
    CmdInfo info[5];
} ErrorInfo;

#define MAX_TRANSFER_SIZE 0x80000

extern ErrorInfo lbl_804E4580;
extern u32v lbl_805A0900;
extern DVDCommandBlock DummyCommandBlock_804E4260;
extern DVDCommandBlock* executing_805A0990;
extern DVDDiskID lbl_804E4300;
extern void (*lbl_805A0994)(DVDCommandBlock*);
extern void (*lbl_8059EAE0)(DVDCommandBlock*, DVDLowCallback);

BOOL fn_801FEA54(DVDLowCallback callback);
BOOL fn_801FCB9C(DVDDiskID* out, DVDLowCallback callback);
BOOL fn_801FE5D0(u32 offset, DVDLowCallback callback);
BOOL fn_801FD98C(BOOL eject, BOOL kill, DVDLowCallback callback);
BOOL fn_801FDF78(u32 enable, u32 size, DVDLowCallback callback);
BOOL fn_801FDB20(DVDDriveInfo* out, DVDLowCallback callback);
BOOL fn_801FDDF0(BOOL enable);
BOOL fn_801FDDFC(DVDLowCallback callback);
BOOL fn_801FE420(void* dst, u32 size, u32 offset, DVDLowCallback callback);
BOOL fn_801FD7F8(void* dst, u32 size, u32 offset, DVDLowCallback callback);
BOOL fn_801FCD24(u32 offset, const void* ticket, u32 certsSize,
                 const void* certs, void* tmd, DVDLowCallback callback);
BOOL fn_801FD694(DVDLowCallback callback);
BOOL fn_801FE768(DVDLowCallback callback);
BOOL fn_801FE2A0(u32 speed, DVDLowCallback callback);
BOOL fn_801FD1F0(u32 offset, void* a, void* b, DVDLowCallback callback);
BOOL fn_801FD3FC(u32 offset, void* a, void* b, void* c, void* d, void* e,
                 void* f, void* g, DVDLowCallback callback);
BOOL fn_801FCF8C(u32 offset, void* a, s32 b, void* c, s32 d, void* e,
                 DVDLowCallback callback);
void fn_801F9688(void);
void fn_801F9F60(u32 intType);

static inline void StampCommand(u32 command, u32 param1, u32 param2) {
    BOOL enabled;

    enabled = OSDisableInterrupts();
    if (lbl_805A0900 >= 5) {
        lbl_805A0900 = 0;
    }
    lbl_804E4580.info[lbl_805A0900].command = command;
    lbl_804E4580.info[lbl_805A0900].param1 = param1;
    lbl_804E4580.info[lbl_805A0900].param2 = param2;
    lbl_804E4580.info[lbl_805A0900].tick = OSGetTick();
    lbl_805A0900 = lbl_805A0900 + 1;
    OSRestoreInterrupts(enabled);
}

static inline void ReadTransfer(DVDCommandBlock* block,
                                BOOL (*read)(void*, u32, u32, DVDLowCallback)) {
    u32 offset = block->offset;
    char* buffer = (char*)block->addr;
    u32 total = block->transferTotal;

    buffer += total;
    read(buffer, block->transferSize, offset + DVD_LOW_OFFSET(total),
         fn_801F9F60);
}

void fn_801F99B0(DVDCommandBlock* block) {
    u32 stampCommand;
    u32 param2;
    u32 param1;
    u32 command;
    u32 total;
    u32 addr;
    u32 transferSize;
    DVDCommandBlock* current;
    char* temp;

    lbl_805A0994 = fn_801F99B0;

    command = block->command;
    switch (command) {
    case 2:
    case 3:
    case 5:
    case 13:
    case 14:
    case 15:
    case 16:
    case 34:
    case 37:
    case 41:
    case 42:
        param2 = block->length;
        param1 = block->offset;
        StampCommand(command, param1, param2);
        break;
    default:
        break;
    }

    switch (block->command) {
    case 5:
        fn_801FEA54(NULL);
        block->transferSize = sizeof(DVDDiskID);
        fn_801FCB9C(block->addr, fn_801F9F60);
        break;
    case 1:
    case 4:
        if (block->length == 0) {
            current = executing_805A0990;
            executing_805A0990 = &DummyCommandBlock_804E4260;

            current->state = DVD_STATE_IDLE;
            if (current->callback != NULL) {
                current->callback(DVD_RESULT_OK, current);
            }
            fn_801F9688();
        } else {
            fn_801FEA54(NULL);

            transferSize = block->length - block->transferTotal;
            if (transferSize > MAX_TRANSFER_SIZE) {
                transferSize = MAX_TRANSFER_SIZE;
            }
            block->transferSize = transferSize;

            stampCommand = block->command;
            StampCommand(stampCommand,
                         block->offset + DVD_LOW_OFFSET(block->transferTotal),
                         transferSize);

            ReadTransfer(block, fn_801FE420);
        }
        break;
    case 2:
        fn_801FEA54(NULL);
        fn_801FE5D0(block->offset, fn_801F9F60);
        break;
    case 3:
        fn_801FD98C(FALSE, FALSE, fn_801F9F60);
        break;
    case 15:
        fn_801FD98C(FALSE, FALSE, fn_801F9F60);
        break;
    case 13:
        fn_801FEA54(NULL);
        fn_801FDF78(block->offset, block->length, fn_801F9F60);
        break;
    case 14:
        fn_801FEA54(NULL);
        block->transferSize = sizeof(DVDDriveInfo);
        fn_801FDB20(block->addr, fn_801F9F60);
        break;
    case 16:
        fn_801FEA54(NULL);
        fn_801FD98C(FALSE, FALSE, fn_801F9F60);
        break;
    case 32:
        fn_801FDDF0(TRUE);
        fn_801FDDFC(fn_801F9F60);
        break;
    case 33:
        if (block->length == 0) {
            current = executing_805A0990;
            executing_805A0990 = &DummyCommandBlock_804E4260;

            current->state = DVD_STATE_IDLE;
            if (current->callback != NULL) {
                current->callback(DVD_RESULT_OK, current);
            }
            fn_801F9688();
        } else {
            fn_801FEA54(NULL);

            transferSize = block->length - block->transferTotal;
            if (transferSize > MAX_TRANSFER_SIZE) {
                transferSize = MAX_TRANSFER_SIZE;
            }
            block->transferSize = transferSize;

            stampCommand = block->command;
            StampCommand(stampCommand,
                         block->offset + DVD_LOW_OFFSET(block->transferTotal),
                         transferSize);

            ReadTransfer(block, fn_801FD7F8);
        }
        break;
    case 34:
        fn_801FEA54(NULL);
        fn_801FCD24(block->offset, NULL, 0, NULL, block->addr, fn_801F9F60);
        break;
    case 35:
        fn_801FEA54(NULL);
        fn_801FD694(fn_801F9F60);
        break;
    case 38:
        fn_801FE768(fn_801F9F60);
        break;
    case 36:
        fn_801FE768(fn_801F9F60);
        break;
    case 37:
        fn_801FEA54(NULL);
        fn_801FE2A0(DVD_LOW_SPEED(2), fn_801F9F60);
        break;
    case 40:
        fn_801FEA54(NULL);
        block->addr = &lbl_804E4300;
        block->transferSize = sizeof(DVDDiskID);
        fn_801FCB9C(block->addr, fn_801F9F60);
        break;
    case 41:
        fn_801FEA54(NULL);
        temp = (char*)block->addr;
        if (*(s32*)(temp + 0x3A0) == 0 && *(s32*)(temp + 0x4DC0) == 0) {
            fn_801FD1F0(block->offset, temp + 0x3A0, temp + 0x4DC0,
                        fn_801F9F60);
        } else {
            fn_801FD3FC(block->offset, temp, temp + 0x3A0, temp + 0x3C0,
                        temp + 0x4DC0, temp + 0x4DE0, temp + 0x5DE0,
                        temp + 0x5E00, fn_801F9F60);
        }
        break;
    case 42:
        fn_801FEA54(NULL);
        temp = (char*)block->addr;
        fn_801FCF8C(block->offset, temp + 0x2C0, *(s32*)(temp + 0x3A0),
                    temp + 0x3C0, *(s32*)(temp + 0x4DC0), temp + 0x4DE0,
                    fn_801F9F60);
        break;
    default:
        lbl_8059EAE0(block, fn_801F9F60);
        break;
    }
}
