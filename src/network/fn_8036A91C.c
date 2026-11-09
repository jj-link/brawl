#pragma force_active on

typedef struct MessageBuffer {
    char *text;
    int unk4;
    int length;
    int end;
} MessageBuffer;

extern char lbl_8059F6A0[6];
extern char lbl_8059F6A8[4];
extern char lbl_8059F6AC[6];
extern char *strchr(const char *, int);
extern int strncmp(const char *, const char *, unsigned long);
extern int atoi(const char *);
extern int fn_80372F14(const char *, const char *, char *, int);

int fn_8036A91C(void *ctx, MessageBuffer *buffer, char **msg, int *type, int *extra) {
    char buf[16];
    char *p;
    int value;

    *msg = 0;
    if (buffer->length < 5) {
        return 0;
    }
    p = strchr(buffer->text, 10);
    if (p != 0) {
        if (strncmp(p - 5, lbl_8059F6A0, 5) != 0) {
            return 3;
        }
        *p = 0;
        if (fn_80372F14(buffer->text, lbl_8059F6A8, buf, 0x10) == 0) {
            return 3;
        }
        *type = atoi(buf);
        if (fn_80372F14(buffer->text, lbl_8059F6AC, buf, 0x10) == 0) {
            return 3;
        }
        value = atoi(buf);
        if (buffer->length > value + (p - buffer->text) + 1) {
            if (p[value + 1] != 0) {
                return 3;
            }
            *msg = p + 1;
            *extra = value;
            buffer->end = value + (p - buffer->text) + 2;
        } else {
            *p = 10;
        }
    }
    return 0;
}
