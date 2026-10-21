#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;

typedef struct {
    u8 result;
    u8 status;
    u8 address[6];
    u16 value;
} Result;

typedef void (*Callback)(Result *);

extern char lbl_80529CF8[];
extern void fn_80232020(void *);
extern void *memcpy(void *, const void *, unsigned long);

void fn_80238968(u8 *arg0)
{
    Result result;
    Callback callback = *(Callback *)(lbl_80529CF8 + 0x5C4);
    char *entry = lbl_80529CF8 + 0x34;
    u16 id;
    u8 i;

    fn_80232020(lbl_80529CF8 + 0x5AC);
    *(Callback *)(lbl_80529CF8 + 0x5C4) = 0;

    if (callback != 0) {
        result.status = arg0[0];
        if (result.status == 0) {
            result.result = 0;
            id = arg0[1] + (arg0[2] << 8);
            result.value = arg0[3] + (arg0[4] << 8);

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
