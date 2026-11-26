#include <types.h>
#include <revolution/OS/OSInterrupt.h>
#pragma force_active on

typedef struct Slot {
    u8 pad00[0x30];
    u8 state[0x20];
    s16 *samples;
    u32 length;
    s32 id;
    u8 start;
    s8 volume;
    s8 timeout;
    u8 pad5f[9];
} Slot;

extern Slot *lbl_805A0E98;
extern int fn_8021AE80(int);
extern int fn_8021C69C(int);
extern void fn_80210430(void *, int, s16 *, int, void *);
extern void fn_8021C720(int, void *, int);

void fn_8027AD1C(void)
{
    Slot *slot = lbl_805A0E98;
    int i;
    if (slot != 0) {
        for (i = 0; i < 4; i++, slot++) {
            if (slot->samples != 0 && fn_8021AE80(i)) {
                BOOL enabled = OSDisableInterrupts();
                if (fn_8021C69C(i)) {
                    s16 samples[40];
                    u8 data[20];
                    u32 n = 40;
                    s16 *src = slot->samples;
                    s16 *dst = samples;
                    int volume = slot->volume;
                    u32 count = slot->length >> 1;
                    if (count <= 40)
                        n = count;
                    { int j; for (j = 0; j < n; j++)
                        *dst++ = (*src++ * volume) / 10; }
                    if (count <= 40) {
                        n = 40 - count;
                        { int j; for (j = 0; j < n; j++)
                            *dst++ = 0; }
                    }
                    fn_80210430(slot->state, slot->start == 0, samples, 40, data);
                    fn_8021C720(i, data, 20);
                    slot->start = 0;
                    slot->timeout = 0;
                    slot->samples += 40;
                    slot->length -= 80;
                    if ((s32)slot->length <= 0) {
                        slot->id = -1;
                        slot->samples = 0;
                    }
                } else {
                    slot->timeout++;
                    if (slot->timeout > 300)
                        slot->samples = 0;
                }
                OSRestoreInterrupts(enabled);
            }
        }
    }
}
