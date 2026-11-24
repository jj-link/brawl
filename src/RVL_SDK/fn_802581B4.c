#include <types.h>
#pragma force_active on

typedef struct {
    u32 len;
    u8 *data;
    u16 id;
    u8 type;
} Attr;
typedef struct {
    u32 handle;
    u32 used;
    u16 count;
    u16 pad;
    Attr attrs[25];
    u8 data[352];
} Record;

extern u8 lbl_8052D9C0[];
extern const char lbl_80484C58[];
extern void fn_80231A14(u32, const char *, u32, u32);

s32 fn_802581B4(u32 handle, u16 id)
{
    u16 i, j, k;
    Record *rec = (Record *)(lbl_8052D9C0 + 0x1224);
    Attr *attr;
    u32 len;
    u8 *data;

    for (i = 0; i < *(u16 *)(lbl_8052D9C0 + 0x1222); i++, rec++) {
        if (rec->handle == handle) {
            attr = rec->attrs;
            if (lbl_8052D9C0[0x4630] >= 3)
                fn_80231A14(0xA0002, lbl_80484C58, id, handle);
            for (i = 0; i < rec->count; i++, attr++) {
                if (attr->id == id) {
                    len = attr->len;
                    data = attr->data;
                    if (len != 0) {
                        for (j = 0; j < rec->count; j++) {
                            if (rec->attrs[j].data > data)
                                rec->attrs[j].data -= len;
                        }
                    }
                    rec->count--;
                    for (; i < rec->count; i++, attr++)
                        *attr = attr[1];
                    if (len != 0) {
                        u16 count = rec->used - ((data + len) - rec->data);
                        for (k = 0; k < count; k++) {
                            *data = *(data + len);
                            data++;
                        }
                        rec->used -= len;
                    }
                    return 1;
                }
            }
        }
    }
    return 0;
}
