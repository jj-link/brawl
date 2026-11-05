#include <types.h>
#include <string.h>
#pragma force_active on

typedef struct Buffer {
    char *data;
    int capacity;
    int used;
    int field_c;
    int field_10;
    int field_14;
} Buffer;

typedef struct Context {
    char pad[0x10];
    u64 time;
    char pad18[0x24];
    void *array;
} Context;

extern int fn_8036A328(void *, Buffer *, const char *);
extern int fn_8036A384(void *, Buffer *, int);
extern int fn_8036A24C(void *, Buffer *, const void *, int);
extern int fn_8036A1A4(void *, Buffer *, int);
extern void fn_8035A5C8(void *, void *);
extern u64 fn_8035D258(int);
extern char lbl_8059F84C[4];
extern char lbl_8059F850[6];
extern char lbl_8059F858[7];

int fn_80370118(void *arg0, Context *arg1, int arg2, const char *arg3)
{
    Buffer buf;
    int len = strlen(arg3);
    int result;
    memset(&buf, 0, sizeof(buf));
    buf.field_10 = arg2;
    result = fn_8036A328(arg0, &buf, lbl_8059F84C);
    if (result != 0) return result;
    result = fn_8036A384(arg0, &buf, arg2);
    if (result != 0) return result;
    result = fn_8036A328(arg0, &buf, lbl_8059F850);
    if (result != 0) return result;
    result = fn_8036A384(arg0, &buf, len);
    if (result != 0) return result;
    result = fn_8036A328(arg0, &buf, lbl_8059F858);
    if (result != 0) return result;
    buf.field_14 = buf.used;
    result = fn_8036A24C(arg0, &buf, arg3, len);
    if (result != 0) return result;
    result = fn_8036A1A4(arg0, &buf, 0);
    if (result != 0) return result;
    fn_8035A5C8(arg1->array, &buf);
    arg1->time = fn_8035D258(0) + 300;
    return 0;
}