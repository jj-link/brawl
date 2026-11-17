#pragma force_active on
typedef struct {
    char data[0x578];
    int len;
} Msg;

extern int fn_8035D728(void);
extern int sendto(int, const void *, int, int, const void *, int);
extern void *memcpy(void *, const void *, unsigned int);

void fn_8037ABA0(char *self) {
    Msg msg;

    msg.len = 0;
    msg.data[0] = 8;
    memcpy(msg.data + 1, self + 0x84, 4);
    msg.len = 5;
    sendto(*(int *)self, msg.data, msg.len, 0, self + 0xCC, 8);
    *(int *)(self + 0xB0) = fn_8035D728();
}