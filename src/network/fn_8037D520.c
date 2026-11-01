#pragma force_active on

typedef unsigned int u32;
typedef unsigned short u16;

typedef struct {
    unsigned char pad[0x19C];
    int flag;
} Object;

extern void *memcpy(void *, const void *, u32);
extern u16 SONtoHs(u16);
extern void fn_80361680(void *, void *, void *, u32);
extern void fn_8037B570(void *, void *, void *, u32);
extern int fn_8037D738(void *, void *, void *);

int fn_8037D520(Object *obj, unsigned char **objp, unsigned char *src,
                int *remaining, unsigned char *dst, int *position)
{
    unsigned char *recordObj;
    int inputOffset = 0;
    int outputOffset = 0;
    int one = 1;
    unsigned char *record;
    u16 payloadLength;
    int recordType;
    int result;
    int local[10];

    if (objp != 0) {
        recordObj = *objp;
        if (recordObj != 0)
            goto have_record_obj;
    }

    memcpy(dst, src, *remaining);
    *position = *remaining;
    *remaining = 0;
    return 1;

have_record_obj:
    if (recordObj == 0)
        return 3;

    while (inputOffset < *remaining) {
        if ((u32)(*remaining - inputOffset) < 5)
            break;

        record = src + inputOffset;
        payloadLength = SONtoHs((u16)(((u16)record[4] << 8) | record[3]));

        if (*remaining < inputOffset + payloadLength + 5)
            break;

        if (obj->flag && *position - outputOffset < payloadLength) {
            *remaining = inputOffset;
            *position = outputOffset;
            result = 2;
            if (outputOffset > 0)
                result = 1;
            return result;
        }

        recordType = record[0];
        switch (recordType) {
        case 0x16:
            inputOffset += 5;
            if (obj->flag)
                fn_80361680(recordObj + 0x4A2,
                            src + inputOffset, src + inputOffset,
                            payloadLength);
            fn_8037B570(obj, local, src + inputOffset, payloadLength);
            result = fn_8037D738(obj, objp, local);
            if (result != 1)
                return result;
            break;

        case 0x17:
            inputOffset += 5;
            if (obj->flag)
                fn_80361680(recordObj + 0x4A2,
                            src + inputOffset, src + inputOffset,
                            payloadLength);
            memcpy(dst + outputOffset, src + inputOffset,
                   payloadLength - 0x10);
            outputOffset += payloadLength - 0x10;
            break;

        case 0x14:
            obj->flag = one;
            inputOffset += 5;
            break;

        case 0x15:
            inputOffset += 5;
            break;

        default:
            return 3;
        }

        inputOffset += payloadLength;
    }

    *remaining = inputOffset;
    *position = outputOffset;
    if (*remaining < 0)
        return 3;
    return 1;
}
