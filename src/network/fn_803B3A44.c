#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct Obj {
    u8 pad[0x20a];
    u8 count;
    u8 pad2[0x10];
    u8 flags;
    u8 pad3[0x10];
    void *handle;
    u8 pad4[8];
    int data;
    u16 length;
} Obj;
typedef struct Req {
    u8 pad[0x44];
    int data;
    u16 length;
} Req;
extern u8 lbl_805A49D0;
extern int fn_803B5230(Req *, int);
extern int fn_803C0440(void *, u8 *, int, u16, int, u32 *, int);
extern int fn_803B0174(void *, int);

int fn_803B3A44(Obj *obj, Req *req) {
    u32 count;
    u8 byte = lbl_805A49D0;
    u32 i;
    void *handle = obj->handle;
    int result;
    if (handle == 0) return 10;
    if (obj == 0) return 10;
    if (req == 0) return 10;
    if (obj->count != 0 && !(obj->flags & 0x18)) {
        for (i = 1; i <= obj->count; i++) {
            result = fn_803B5230(req, 0);
            if (result != 0) return result;
            result = fn_803C0440(handle, &byte, req->data, req->length, 1, &count, 0);
            if (result != 0) return result;
            if (count != 1) return 17;
        }
    }
    result = fn_803C0440(handle, &byte, obj->data, obj->length, 1, &count, 0);
    if (result != 0) return result;
    if (count != 1) return 17;
    result = fn_803B0174(handle, 0);
    return result & ((-result | result) >> 31);
}