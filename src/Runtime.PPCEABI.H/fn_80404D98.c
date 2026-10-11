typedef unsigned long u32;

struct TRKExceptionStatus {
    u32 words[3];
    unsigned char flags;
    unsigned char detected;
    unsigned short reserved;
};
struct TRKMemoryRange {
    unsigned char* first;
    unsigned char* last;
    int readable;
    int writable;
};

extern struct TRKExceptionStatus gTRKExceptionStatus_804947AC;
extern u32 gTRKCPUState[];
extern const struct TRKMemoryRange lbl_804204E0[1];
extern void* fn_8040593C(u32 address);
extern u32 fn_80403770(void);
extern void fn_80403780(void* destination, const void* source, u32 length,
                       u32 destination_msr, u32 source_msr);
extern void TRK_flush_cache(void* address, u32 length);
int fn_80404EE4(void* address, u32 length, int access);

int fn_80404D98(void* destination, u32 address, u32* size,
                int translate, int read) {
    struct TRKExceptionStatus saved;
    struct TRKExceptionStatus* status;
    void* translated;
    u32 debugger_msr;
    u32 target_msr;
    int result;
    int access;

    status = &gTRKExceptionStatus_804947AC;
    saved = *status;
    status->detected = 0;
    translated = fn_8040593C(address);
    access = read ? 0 : 1;
    result = fn_80404EE4(translated, *size, access);
    if (result != 0) {
        *size = 0;
    } else {
        debugger_msr = fn_80403770();
        target_msr = debugger_msr | (gTRKCPUState[0x1f8 / sizeof(u32)] & 0x10);
        if (read) {
            fn_80403780(destination, translated, *size,
                        debugger_msr, target_msr);
        } else {
            fn_80403780(translated, destination, *size,
                        target_msr, debugger_msr);
            TRK_flush_cache(translated, *size);
            if (address != (u32)translated) TRK_flush_cache((void*)address, *size);
        }
    }
    if (status->detected != 0) {
        *size = 0;
        result = 0x702;
    }
    gTRKExceptionStatus_804947AC = saved;
    return result;
}

/* Check the inclusive range, including the original recursive boundary rules. */
int fn_80404EE4(void* address, u32 length, int access) {
    register int result;
    u32 last;
    int i;

    last = length + (u32)address;
    result = 0x700;
    if (--last < (u32)address) return 0x700;
    for (i = 0; i < 1; ++i) {
        if ((unsigned char*)address <= lbl_804204E0[i].last && last >= (u32)lbl_804204E0[i].first) {
            if ((access == 0 && !lbl_804204E0[i].readable) ||
                (access == 1 && !lbl_804204E0[i].writable)) {
                result = 0x700;
            } else {
                result = 0;
                if ((unsigned char*)address < lbl_804204E0[i].first) {
                    result = fn_80404EE4(address, lbl_804204E0[i].first - (unsigned char*)address, access);
                }
                if (result == 0 && last > (u32)lbl_804204E0[i].last) {
                    result = fn_80404EE4(lbl_804204E0[i].last,
                                        last - (u32)lbl_804204E0[i].last, access);
                }
            }
            break;
        }
    }
    return result;
}
