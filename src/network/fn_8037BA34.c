#pragma force_active on

typedef struct {
    void* unk0;
    char* unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
} NetBuf;

typedef struct {
    char pad[0x3C];
    int unk3C;
    char pad40[0xE0];
    int unk120;
} NetObj;

extern char* fn_8035DFF8(char*, int);

int fn_8037BA34(void* arg0, char arg1) {
    NetBuf* buf = (NetBuf*)arg0;
    int new_cap;
    char* p;
    int ok;
    int t;

    if (arg0 == 0) return 0;
    if (buf->unk20 != 0) return 0;

    if (buf->unkC + 1 >= buf->unk8) {
        if (buf->unk18 != 0) {
            ((NetObj*)buf->unk0)->unk120 = 1;
            ((NetObj*)buf->unk0)->unk3C = 2;
            return 0;
        }
        ok = 0;
        t = buf->unk14;
        if (arg0 == 0) {
            ok = 0;
        } else if (t <= 0) {
            ok = 0;
        } else {
            new_cap = buf->unk8 + t;
            p = fn_8035DFF8(buf->unk4, new_cap);
            if (p == 0) {
                ok = 0;
            } else {
                buf->unk4 = p;
                ok = 1;
                buf->unk8 = new_cap;
            }
        }
        if (ok == 0) {
            ((NetObj*)buf->unk0)->unk120 = 1;
            ((NetObj*)buf->unk0)->unk3C = 1;
            return 0;
        }
    }
    buf->unk4[buf->unkC] = arg1;
    buf->unkC = buf->unkC + 1;
    buf->unk4[buf->unkC] = 0;
    return 1;
}
