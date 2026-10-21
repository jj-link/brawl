#pragma force_active on
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct Info {
    u16 count;
    u8 pad02[0x1E];
    u8 shift;
    u8 extra;
} Info;

typedef struct Data {
    u8 pad00[0x268];
    Info *info;
} Data;

typedef struct Object {
    u8 pad00[8];
    Data *data;
    u8 pad0C[0x10];
    u32 value;
    u32 pad20;
    u32 index;
    u16 remainder;
} Object;

extern void fn_803E15D8(void *, u32, u32 *);

void fn_803E46AC(Object *obj, u32 arg1)
{
    u32 value;
    int shift;
    Info *info;
    Info *info2;
    u32 bits;

    if (obj == 0) {
        info = 0;
    } else {
        info = obj->data->info;
    }

    fn_803E15D8((u8 *)obj->data + 4, arg1, &value);
    shift = info->shift + info->extra;

    if (value > (0xFFFFFFFFU >> shift)) {
        obj->value = 0xFFFFFFFFU;
        if (obj == 0) {
            info2 = 0;
        } else {
            info2 = obj->data->info;
        }
        bits = obj->value;
        obj->index = bits >> info2->shift;
        obj->remainder = bits & (info2->count - 1);
        return;
    }

    obj->value = value << shift;
    if (obj == 0) {
        info2 = 0;
    } else {
        info2 = obj->data->info;
    }
    bits = obj->value;
    obj->index = bits >> info2->shift;
    obj->remainder = bits & (info2->count - 1);
}
