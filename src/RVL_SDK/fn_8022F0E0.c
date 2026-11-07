#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct Header {
    struct Header *next;
    u8 pool;
    u8 pad;
    u8 status;
    u8 pad2;
} Header;

extern u8 lbl_804FD448[];
extern char lbl_8047FAB0[];
extern void fn_80230570(u16, char *);
extern void fn_8023052C(void);
extern void fn_80230508(void);

void fn_8022F0E0(void *buffer) {
    Header *header;
    u16 offset;
    u8 bad;
    u8 *end;
    u8 *entry;
    u16 count;
    char *base = lbl_8047FAB0;

    if (buffer == 0) {
        goto block_10;
    }
    header = (Header *)((u8 *)buffer - 8);
    if ((u32)header & 1) {
        offset = 0;
    } else if (header->pool < 9) {
        offset = *(u16 *)(lbl_804FD448 + 0x289E8 + ((header->pool << 4) & 0xFF0));
    } else {
        offset = 0;
    }
    end = (u8 *)buffer + offset;
    if ((u32)end & 1) {
        bad = 1;
    } else {
        bad = *(u32 *)end != 0xDDBADDBA;
    }
    if (bad == 0) {
        goto check_status;
    }
block_10:
    fn_80230570(0xFFFF, base + 0x30);
    return;
check_status:
    if (header->status != 1) {
        fn_80230570(0xFFFC, base + 0x48);
        return;
    }
    if (header->pool >= 9) {
        fn_80230570(0xFFFD, base + 0x5C);
        return;
    }
    fn_8023052C();
    entry = lbl_804FD448 + 0x30000 + (header->pool << 4);
    if (*(Header **)(entry - 0x761C) != 0) {
        (*(Header **)(entry - 0x761C))->next = header;
    } else {
        *(Header **)(entry - 0x7620) = header;
    }
    *(Header **)(entry - 0x761C) = header;
    header->next = 0;
    header->status = 0;
    header->pad = 0xF0;
    count = *(u16 *)(entry - 0x7614);
    if (count != 0) {
        *(u16 *)(entry - 0x7614) = count - 1;
    }
    fn_80230508();
}
