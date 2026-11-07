#pragma force_active on
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u32 len; u8 *data; u16 id; u8 type; } Attr;
typedef struct { u32 handle; u32 used; u16 count; u16 pad; Attr attrs[25]; u8 data[352]; } Record;
extern u8 lbl_8052D9C0[];
extern char lbl_80484BE8[];
extern void fn_802581B4(u32, u16);
extern void fn_80231A14(u32, const char *, u32, u32);
extern void *memcpy(void *, const void *, unsigned long);
int fn_80257BC8(u32 handle, u16 id, u8 type, u32 len, u8 *data)
{
    u16 i, j, k;
    Record *rec = (Record *)(lbl_8052D9C0 + 0x1224);
    Attr *attr;
    for (i = 0; i < *(u16 *)(lbl_8052D9C0 + 0x1222); i++, rec++) {
        if (rec->handle == handle) {
            attr = rec->attrs;
            for (j = 0; j < rec->count; j++, attr++) {
                if (attr->id == id) {
                    fn_802581B4(handle, id);
                    break;
                }
                if (attr->id > id)
                    break;
            }
            k = rec->count;
            if (k == 25)
                return 0;
            if (j == k)
                attr = &rec->attrs[k];
            else {
                for (; k > j; k--)
                    rec->attrs[k] = rec->attrs[k - 1];
            }
            rec->count++;
            attr->id = id;
            attr->len = len;
            attr->type = type;
            if (rec->used + len >= 0x15e) {
                if (lbl_8052D9C0[0x4630] >= 2)
                    fn_80231A14(0xA0001, lbl_80484BE8, len, 0x15e - rec->used);
                len = 0x15e - rec->used;
                data[len] = 0;
                data[0x15f - rec->used] = 0;
            }
            if (len != 0 && data != 0) {
                memcpy(rec->data + rec->used, data, len);
                attr->data = rec->data + rec->used;
                rec->used += len;
            }
            if (handle == *(u32 *)(lbl_8052D9C0 + 0x121c) && id == 0x8001)
                lbl_8052D9C0[0x1220] = 1;
            return 1;
        }
    }
    return 0;
}