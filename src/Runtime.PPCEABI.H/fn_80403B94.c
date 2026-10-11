typedef unsigned long u32;
typedef signed long s32;

struct TRKEvent {
    u32 type;
    u32 value;
    u32 buffer_id;
};

extern u32 gTRKCPUState[];
extern void fn_80400EB4(struct TRKEvent* event, u32 type);
extern int fn_80400ECC(struct TRKEvent* event);
extern int fn_804030F8(const char* name, unsigned char mode, u32* handle,
                       int* io_result);
extern int fn_80403010(u32 handle, int* io_result);
extern int fn_80402F00(u32 handle, s32* position, unsigned char whence,
                       int* io_result);
extern int fn_80403394(u32 handle, void* buffer, u32* count, int* io_result,
                       int reply, int read);
extern void TRK_flush_cache(void* address, u32 size);

int TRKTargetSupportRequest(void) {
    u32* count;
    int command = (int)gTRKCPUState[3];
    int error;
    struct TRKEvent event;
    int io_result;
    s32 position;

    if (command != 0xD1 && command != 0xD0 && command != 0xD2 &&
        command != 0xD3 && command != 0xD4) {
        fn_80400EB4(&event, 4);
        fn_80400ECC(&event);
        return 0;
    }

    if (command == 0xD2) {
        error = fn_804030F8((const char*)gTRKCPUState[4],
                            (unsigned char)gTRKCPUState[5],
                            (u32*)gTRKCPUState[6], &io_result);
        if (io_result == 0 && error != 0) {
            io_result = 1;
        }
        gTRKCPUState[3] = io_result;
    } else if (command == 0xD3) {
        error = fn_80403010(gTRKCPUState[4], &io_result);
        if (io_result == 0 && error != 0) {
            io_result = 1;
        }
        gTRKCPUState[3] = io_result;
    } else if (command == 0xD4) {
        position = *(s32*)gTRKCPUState[5];
        error = fn_80402F00(gTRKCPUState[4], &position,
                            (unsigned char)gTRKCPUState[6], &io_result);
        if (io_result == 0 && error != 0) {
            io_result = 1;
        }
        gTRKCPUState[3] = io_result;
        *(s32*)gTRKCPUState[5] = position;
    } else {
        count = (u32*)gTRKCPUState[5];

        error = fn_80403394(gTRKCPUState[4], (void*)gTRKCPUState[6], count,
                            &io_result, 1, command == 0xD1);
        if (io_result == 0 && error != 0) {
            io_result = 1;
        }
        gTRKCPUState[3] = io_result;
        if (command == 0xD1) {
            TRK_flush_cache((void*)gTRKCPUState[6], *count);
        }
    }

    gTRKCPUState[0x80 / sizeof(u32)] += 4;
    return error;
}
