#pragma force_active on

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;
typedef int SCItemID;

#define TRUE 1
#define FALSE 0
#define NULL 0

#define SC_CONF_MIN_SIZE 0xC
#define SC_CONF_MAX_SIZE 0x4000
#define SC_ITEM_MAX 0x24

typedef struct SCConfItem {
    u8 desc;
    char name[];
} SCConfItem;

typedef struct SCItem {
    char UNK_0x0[0x8];
    u8 primType;
    u8 arrayType;
    u32 nameLen;
    u32 dataLen;
    const char* name;
    u8* data;
    u32 itemLen;
} SCItem;

typedef struct SCNameAndID {
    const char* name;
    SCItemID id;
} SCNameAndID;

extern int fn_8020E98C(const SCConfItem *, SCItem *);
extern int fn_803F6150(const void *, const void *, unsigned long);
extern void *memcpy(void *, const void *, unsigned long);
extern void *memset(void *, int, unsigned long);
extern unsigned long strlen(const char *);

extern SCNameAndID lbl_8047C398[];
extern char lbl_8059EC78[5];
extern char lbl_8059EC80[5];
extern u32 lbl_805A0BC4;
extern u32 lbl_805A0BC8;
extern u32 lbl_805A0BC0;
extern u32 lbl_805A0BBC;

static BOOL ParseGetBEValue(const u8* start, const u8* end, u32* out,
                            u32 size) {
    u32 imm = 0;

    if (start + size > end) {
        return FALSE;
    }

    for (; size > 0; start++, size--) {
        imm = imm << 8 | *start;
    }

    *out = imm;
    return TRUE;
}

int fn_8020E740(u8* conf, u32 size)
{
    int i;

    u8* confBegin;
    u8* confEnd;
    u32 itemOffset;

    u32 numItems;
    u16* confItems;
    u32 itemRest;

    u8* confLutEnd;
    u8* confLutBegin;

    SCNameAndID* tblIter;
    SCNameAndID* tblEnd;
    const char* itName;

    tblIter = lbl_8047C398;

    /**
     * Config parameters
     */

    if (size < SC_CONF_MIN_SIZE) {
        goto _error;
    }

    if (size > SC_CONF_MAX_SIZE) {
        goto _error;
    }

    confBegin = conf;
    confEnd = conf + size - sizeof(u32);
    lbl_805A0BC4 = SC_ITEM_MAX;

    /**
     * File magic
     */

    if (fn_803F6150(conf, lbl_8059EC78, sizeof(u32)) != 0) {
        goto _error;
    }

    if (fn_803F6150(confEnd, lbl_8059EC80, sizeof(u32)) != 0) {
        goto _error;
    }

    conf += sizeof(u32);

    if (size < SC_CONF_MAX_SIZE) {
        u32 confRest = SC_CONF_MAX_SIZE - size;
        memset(confEnd, 0, confRest);
        confEnd += confRest;
        memcpy(confEnd, lbl_8059EC80, sizeof(u32));
    }

    /**
     * Item count
     */

    if (!ParseGetBEValue(conf, confEnd, &numItems, sizeof(u16))) {
        goto _error;
    }

    conf += sizeof(u16);

    /**
     * Item data
     */

    confItems = (u16*)conf;
    itemOffset = (u8*)(confItems + numItems + 1) - confBegin;

    for (i = 0; i < numItems; i++) {
        SCItem item;

        if (itemOffset > size) {
            goto _error;
        }

        if ((u8*)&confItems[i] - confBegin > size) {
            goto _error;
        }

        if (itemOffset != confItems[i]) {
            goto _error;
        }

        if (!fn_8020E98C((SCConfItem*)(confBegin + itemOffset), &item)) {
            goto _error;
        }

        itemOffset += item.itemLen;
    }

    if (itemOffset > size || itemOffset != confItems[i]) {
        goto _error;
    }

    /**
     * Item lookup table
     */

    confLutEnd = confEnd - (SC_ITEM_MAX - 1) * sizeof(u16);

    if (confBegin + itemOffset > confLutEnd) {
        goto _error;
    }

    itemRest = confLutEnd - (confBegin + itemOffset);
    memset(confLutEnd, 0, confEnd - confLutEnd);

    // First LUT entry (grows upward)
    confLutBegin = confEnd - sizeof(u16);

    /**
     * Build lookup table
     */

    for (tblEnd = &tblIter[lbl_805A0BC4];
         tblIter < tblEnd && (itName = tblIter->name) != (void*)NULL;
         tblIter++) {

        u32 itNameLen = strlen(itName);

        for (i = 0; i < numItems; i++) {
            SCConfItem* itData = (SCConfItem*)(confBegin + confItems[i]);

            // Item length doesn't include terminator
            if (itNameLen != (itData->desc & 0b00011111) + 1) {
                continue;
            }

            if (fn_803F6150(itName, itData->name, itNameLen) != 0) {
                continue;
            }

            // LUT items are in reverse order
            ((u16*)confLutBegin)[-tblIter->id] =
                (u8*)(confItems + i) - confBegin;

            break;
        }
    }

    lbl_805A0BC8 = confLutBegin - confBegin;
    lbl_805A0BC0 = numItems;
    lbl_805A0BBC = itemRest;
    return 0;

_error:
    return 2;
}
