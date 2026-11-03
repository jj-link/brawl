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
typedef struct Queue {
    void *head;
    void *tail;
    u16 count;
} Queue;

extern u8 lbl_804FD448[];
extern char lbl_8047FB60[];
extern char lbl_8047FB9C[];
extern void fn_80230570(u16, char *);
extern void fn_8023052C(void);
extern void fn_80230508(void);

void fn_8022F63C(Queue *queue, void *buffer) {
    Header *header = (Header *)((u8 *)buffer - 8);
    u16 offset;
    u8 bad;
    u8 *end;
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
    if (bad) {
        fn_80230570(0xFFFF, lbl_8047FB60);
    } else if (header->status != 1) {
        fn_80230570(0xFFF9, lbl_8047FB9C);
    } else {
        fn_8023052C();
        if (queue->head) {
            header->next = (Header *)((u8 *)queue->head - 8);
            queue->head = buffer;
        } else {
            queue->head = buffer;
            queue->tail = buffer;
            header->next = 0;
        }
        queue->count++;
        header->status = 2;
        fn_80230508();
    }
}