#pragma force_active on
typedef struct State {
    unsigned char pad[0x8C];
    int field_8C;
    int field_90;
    unsigned char tail[0x44];
} State;

extern unsigned int fn_8035D728(void);
extern int fn_80385A00(int, State *);
extern int fn_80385A04(State *);
extern int closesocket(int);

extern State lbl_80536220;
extern int lbl_8059FB70;
extern int lbl_8059FB74;
extern int lbl_8059FB78;
extern int lbl_805A1104;
extern unsigned int lbl_805A1108;
extern void (*lbl_805A110C)(int, State);

int fn_80386238(int arg0)
{
    int result = 1;

    if (arg0 != -1) {
        if (fn_8035D728() - lbl_805A1108 < 10000U) {
            result = fn_80385A00(arg0, &lbl_80536220);
        } else {
            result = 0;
        }

        if (result == 0) {
            int status = fn_80385A04(&lbl_80536220);
            lbl_805A110C(status, lbl_80536220);

            lbl_8059FB78 = lbl_80536220.field_8C;
            lbl_805A1104 = lbl_80536220.field_90;

            if (lbl_8059FB70 != -1) {
                closesocket(lbl_8059FB70);
            }
            lbl_8059FB70 = -1;

            if (lbl_8059FB74 != -1) {
                closesocket(lbl_8059FB74);
            }
            lbl_8059FB74 = -1;
        }
    }

    return result;
}
