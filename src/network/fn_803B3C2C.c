#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Vol {
    u16 sectorSize;
    u8 pad2[4];
    u8 count;
} Vol;

typedef struct Buf {
    u8 pad0[8];
    void *data;
} Buf;

typedef struct Sub {
    u8 pad[0x38];
} Sub;

typedef struct Obj {
    u32 unk0;
    Vol *unk4;
    Sub sub;
    u32 unk40;
    s32 unk44;
    u16 unk48;
    u16 unk4A;
    u8 pad4C[0x20];
    u8 unk6C;
} Obj;

extern s32 fn_803B7080(void *, u32, s32, void *);
extern s32 fn_803AFD48(Vol *, s32, Buf **);
extern void fn_803AFE4C(Vol *, Buf *);
extern void fn_803A976C(void *, s32, u32);
extern s32 fn_803C0440(Vol *, void *, u32, s32, u16, u32 *, s32);

s32 fn_803B3C2C(Obj *arg0, s32 arg1) {
    Buf *buf;
    u32 written;
    s32 r;
    u32 i;
    u32 newVal;
    u32 oldVal;

    oldVal = arg0->unk40;
    newVal = arg0->unk0 >> arg0->unk6C;
    if (newVal != oldVal) {
        arg0->unk40 = newVal;
        r = fn_803B7080(&arg0->sub, newVal, 0, &arg0->unk44);
        if (r != 0) {
            return r;
        }
        if ((u32)(arg0->unk44 + 0x10000) == 0xFFFF && arg1 != 0) {
            r = fn_803B7080(&arg0->sub, newVal, 1, &arg0->unk44);
            if (r != 0) {
                return r;
            }
            if ((u32)(arg0->unk44 + 0x10000) != 0xFFFF && (u32)(oldVal + 0x10000) != 0xFFFF) {
                r = fn_803AFD48(arg0->unk4, -1, &buf);
                if (r != 0) {
                    return r;
                }
                fn_803A976C(buf->data, 0, arg0->unk4->sectorSize);
                for (i = 0; i < arg0->unk4->count; i++) {
                    r = fn_803C0440(arg0->unk4, buf->data, arg0->unk44 + i, 0, arg0->unk4->sectorSize, &written, 0);
                    if (r != 0) {
                        fn_803AFE4C(arg0->unk4, buf);
                        return r;
                    }
                    if (written != arg0->unk4->sectorSize) {
                        fn_803AFE4C(arg0->unk4, buf);
                        return 0x11;
                    }
                }
                fn_803AFE4C(arg0->unk4, buf);
            }
        }
    }
    arg0->unk48 = (u16)(((arg0->unk0 & arg0->unk4A) << 5) & 0xFFE0);
    return 0;
}
