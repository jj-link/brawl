#pragma force_active on
typedef struct Context {
    char pad0[0x10];
    int field10;
    char pad14[0x28];
    int state;
    char pad40[0xC];
    int socket;
    int error;
    char pad54[0xCC];
    int failed;
    char pad124[0x48];
    int field16C;
    char pad170[0xC];
    int field17C;
} Context;

extern int send(int sockfd, const void *buf, unsigned int len, int flags);
extern int fn_8035C658(int);

int fn_8037C104(Context *self, char *buffer, int count) {
    int result;
    int error;

    if (buffer == 0 || count == 0) {
        return 0;
    }
    result = send(self->socket, buffer, count, 0);
    if (result == -1) {
        error = fn_8035C658(self->socket);
        if (error == -6 || error == -0x1A || error == -0x4C) {
            return 0;
        }
        self->error = error;
        self->failed = 1;
        self->state = 5;
        return -1;
    }
    if (self->field10 == 6 && self->field17C == 0) {
        self->field16C += result;
    }
    return result;
}
