#pragma force_active on
typedef unsigned char u8;

typedef struct NetworkData {
    u8 pad[0x468];
    int values[120];
    u8 ids[256];
} NetworkData;

extern NetworkData *lbl_805A0F88;
extern void *lbl_80533730[32];
extern u8 *fn_80374C28(void *);

static void *find_id(u8 id)
{
    int i;

    if (lbl_805A0F88 == 0)
        return 0;

    for (i = 0; i < 32; ++i) {
        if (lbl_80533730[i] != 0 &&
            id == fn_80374C28(lbl_80533730[i])[1])
            return lbl_80533730[i];
    }

    return 0;
}

void **fn_8033AD60(int value, int count)
{
    u8 i;

    for (i = 0; i < count; ++i) {
        if (value == lbl_805A0F88->values[i])
            break;
    }

    if (i >= count)
        return 0;

    return &lbl_80533730[
        fn_80374C28(find_id(lbl_805A0F88->ids[i]))[0]];
}
