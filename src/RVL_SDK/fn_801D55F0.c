#pragma force_active on
typedef unsigned int u32;

extern void DCFlushRange(void*, u32);
extern u32 fn_801D713C(void);
extern u32 fn_801D7154(void);
extern void fn_801D77A0(u32, u32);
extern u32 fn_801DF7FC(void);
extern int lbl_804DD120[8];

static inline void clear_range(void* start, u32 len)
{
    u32 flush;

    if (len > 0x40000U) {
        flush = (u32)start + (len - 0x40000U);
    } else {
        flush = (u32)start;
    }

    fn_801D77A0((u32)start, len);
    DCFlushRange((void*)flush, 0x40000);
}

static inline void clear_all(void)
{
    u32 len = fn_801D713C() - fn_801D7154();
    clear_range((void*)fn_801D7154(), len);
}

static inline void clear_all_first(void)
{
    u32 flush;
    u32 len;
    void* start;

    len = fn_801D713C() - fn_801D7154();
    start = (void*)fn_801D7154();

    if (len > 0x40000U) {
        flush = (u32)start + (len - 0x40000U);
    } else {
        flush = (u32)start;
    }

    fn_801D77A0((u32)start, len);
    DCFlushRange((void*)flush, 0x40000);
}

void fn_801D55F0(void)
{
    u32 len;
    void* end;

    if ((fn_801DF7FC() >> 31) == 0) {
        clear_all_first();
        return;
    }

    if (lbl_804DD120[3] == 0 || (lbl_804DD120[3] & 0x30000000)) {
        clear_all();
        return;
    }

    if (fn_801D7154() < (u32)lbl_804DD120[3]) {
        if (fn_801D713C() <= (u32)lbl_804DD120[3]) {
            clear_all();
            return;
        }

        len = (u32)lbl_804DD120[3] - fn_801D7154();
        clear_range((void*)fn_801D7154(), len);

        end = (void*)lbl_804DD120[4];
        if (fn_801D713C() > (u32)end) {
            len = fn_801D713C() - (u32)end;
            clear_range((void*)end, len);
        }
    }
}
