#pragma force_active on
typedef struct {
    unsigned char count;
    unsigned char pad1[3];
    int values[1];
    unsigned char pad8[0x287E8 - 8];
    int field287E8;
    unsigned char pad287EC[0x28802 - 0x287EC];
    unsigned char field28802;
    unsigned char pad28803[9];
    short field2880C;
    unsigned char pad2880E[0x28848 - 0x2880E];
    int field28848;
    unsigned char pad2884C[0x28AE0 - 0x2884C];
} State;

extern State lbl_804FD448;

void *memset(void *, int, unsigned long);
int fn_801DCF24(void);
void fn_8022EB98(void);
void fn_8022FDBC(void);

void fn_80230314(void)
{
    int result;

    memset(&lbl_804FD448, 0, 0x28AE0);
    fn_8022EB98();
    fn_8022FDBC();
    lbl_804FD448.field28802 = 1;
    lbl_804FD448.field287E8 = 0;
    lbl_804FD448.field28848 = 0;
    lbl_804FD448.field2880C = 0;
    lbl_804FD448.count = 0;
    result = fn_801DCF24();
    lbl_804FD448.values[lbl_804FD448.count] = result;
    lbl_804FD448.count++;
}
