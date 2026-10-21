#pragma force_active on
typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad[6];
    u8 flag;
    u8 value;
    u8 tail[3];
} Entry;

typedef struct {
    u8 a, b, c;
} Rule;

extern Entry lbl_80529994[];
extern Rule *lbl_8059EDA8;
extern int fn_80232068(void *, int);

void fn_80234904(int arg0, u32 arg1, u32 arg2, int arg3)
{
    u8 i;
    u8 j;
    u8 value;

    if (arg0 == 0) {
        for (i = 0; i < ((u8 *)lbl_80529994)[0x4D]; i++) {
            if (fn_80232068(&lbl_80529994[i], arg3) == 0) {
                lbl_80529994[i].flag = 1;
                for (j = 1; j <= lbl_8059EDA8->b; j++) {
                    if ((arg2 == lbl_8059EDA8[j].b ||
                         lbl_8059EDA8[j].b == 0xFF) &&
                        arg1 == lbl_8059EDA8[j].a) {
                        value = lbl_8059EDA8[j].c;
                        if (value > lbl_80529994[i].value) {
                            lbl_80529994[i].value = value;
                        }
                        break;
                    }
                }
                break;
            }
        }
    }
}
