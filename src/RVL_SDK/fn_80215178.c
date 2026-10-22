#pragma force_active on
typedef unsigned int u32;

typedef struct Request {
    char pad[0x100];
    int field100;
    int field104;
    int field108;
} Request;

extern int lbl_805A0C1C;
extern Request *fn_802137A4(int, int, int);
extern void fn_80213C80(void);
extern int fn_80212630(int, void *, u32, int, int);

int fn_80215178(int fd, void *buffer, u32 length, int a3, int a4) {
    Request *request;

    if (buffer == 0 || ((u32)buffer & 0x1F)) {
        return -0x65;
    }

    request = fn_802137A4(lbl_805A0C1C, 0x140, 0x20);
    if (request == 0) {
        return -0x76;
    }

    request->field100 = a3;
    request->field104 = a4;
    request->field108 = 0;
    return fn_80212630(fd, buffer, length, (int)fn_80213C80, (int)request);
}
