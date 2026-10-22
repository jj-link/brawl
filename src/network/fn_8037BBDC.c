#pragma force_active on
typedef struct Context {
    char pad0[0x3C];
    int state;
    char pad40[0xC];
    int socket;
    int error;
    char pad54[4];
    char *buffer;
    char pad5C[4];
    int size;
    int offset;
    char pad68[0xB8];
    int failed;
} Context;

extern int fn_8035C660(int, int, int *, int *);
extern int fn_8035C658(int);
extern int fn_8037C104(Context *, char *, int);

int fn_8037BBDC(Context *self)
{
    int ready;
    int error;
    int result;

    do {
        result = fn_8035C660(self->socket, 0, &ready, &error);
        if (result == -1 || (result == 1 && error != 0)) {
            self->failed = 1;
            self->state = 5;
            if (result == -1) {
                self->error = fn_8035C658(self->socket);
            } else {
                self->error = 0;
            }
            return 0;
        }

        if (result < 1 || ready == 0) {
            return 1;
        }

        result = fn_8037C104(self, self->buffer + self->offset,
                           self->size - self->offset);
        if (result == -1) {
            return 0;
        }

        self->offset += result;
    } while (self->offset < self->size);

    return 1;
}
