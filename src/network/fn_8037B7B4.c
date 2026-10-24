#pragma force_active on

typedef struct {
    void* unk0;
    char* unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    char pad18[8];
    int unk20;
} NetBuf;

typedef struct {
    char pad[0x190];
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    char pad1a0[8];
    int (*method)(void*, void*, char*, int, char*, int*);
} NetObj;

extern int fn_8037B644(void*, void*, int);
extern char* fn_8035DFF8(char*, int);
extern int strlen(char*);

int fn_8037B7B4(void* arg0, char* arg1, int arg2) {
    int sp8;
    int written;
    int chunk;
    int ret;
    int ok;
    char* p;
    int t;
    NetBuf* buf = (NetBuf*)arg0;

    sp8 = 0;
    written = 0;

    if (arg0 == 0) return 0;
    if (arg1 == 0) return 0;
    if (arg2 < 0) return 0;

    if (buf->unk20 != 0) return 0;

    if (((NetObj*)buf->unk0)->unk194 == 0 || ((NetObj*)buf->unk0)->unk19c == 0) {
        return fn_8037B644(arg0, arg1, arg2);
    }
    if (arg2 == 0) {
        arg2 = strlen(arg1);
    }
    if (arg2 == 0) return 1;

    sp8 = buf->unk8 - buf->unkC;

    do {
        chunk = (arg2 < 0x3F01) ? arg2 : 0x3F01;
        ret = ((NetObj*)buf->unk0)->method((NetObj*)buf->unk0,
                (void*)((char*)((NetObj*)buf->unk0) + 0x190),
                arg1 + written, arg2, buf->unk4 + buf->unkC, &sp8);
        if (ret == 2) {
            t = buf->unk14;
            if (arg0 == 0) {
                ok = 0;
            } else if (t <= 0) {
                ok = 0;
            } else {
                chunk = buf->unk8 + t;
                p = fn_8035DFF8(buf->unk4, chunk);
                if (p == 0) {
                    ok = 0;
                } else {
                    buf->unk4 = p;
                    buf->unk8 = chunk;
                    ok = 1;
                }
            }
            if (ok == 0) return 0;
            sp8 = buf->unk8 - buf->unkC;
        } else if (ret == 1) {
            written += chunk;
            buf->unkC = buf->unk8 - sp8;
        } else {
            return 0;
        }
    } while (written < arg2);
    return 1;
}
