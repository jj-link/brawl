#include <internal/mem.h>
#pragma force_active on

typedef struct {
    u8 result;
    u8 status;
    u8 value;
    u8 address[6];
} Result;

typedef void (*Callback)(Result *);

extern char lbl_80529CF8[];
extern char lbl_80480C44[];
extern void fn_80232020(void *);
extern void fn_80231A14(u32, const char *, u8, u8);

void fn_80239850(u8 *arg0)
{
    Result result;
    Callback callback = *(Callback *)(lbl_80529CF8 + 0x5FC);
    char *entry = lbl_80529CF8 + 0x34;
    u16 id;
    u8 i;

    fn_80232020(lbl_80529CF8 + 0x5C8);
    *(Callback *)(lbl_80529CF8 + 0x5FC) = 0;

    if (callback != 0) {
        result.status = arg0[0];
        if (result.status == 0) {
            result.result = 0;
            id = arg0[1] + (arg0[2] << 8);
            result.value = arg0[3];
            if (*(u8 *)(lbl_80529CF8 + 0x27C0) >= 4) {
                fn_80231A14(0xD0003, lbl_80480C44, result.value, result.status);
            }
            for (i = 0; i < 4; i++, entry += 0x11C) {
                if (*(u8 *)(entry + 0x119) != 0 &&
                    id == *(u16 *)entry) {
                    memcpy(result.address, entry + 8, 6);
                    break;
                }
            }
        } else {
            result.result = 10;
        }
        callback(&result);
    }
}
