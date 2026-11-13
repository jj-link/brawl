#include <types.h>
#include <string.h>
#pragma force_active on

extern char lbl_80489E48[];
extern char lbl_8059F0A4[5];
extern char lbl_8059F0AC[4];

typedef struct DwcFriendsMatchObj {
    s32 unk00;
    unsigned char pad04[0x1C - 0x04];
    unsigned char unk1C[0x24 - 0x1C];
    s32 unk24;
    s32 unk28;
    unsigned char pad2C[0xA0 - 0x2C];
    s32 unkA0;
    unsigned char padA4[0x370 - 0xA4];
    void *unk370;
    unsigned char pad374[0x375 - 0x374];
    unsigned char unk375;
    unsigned char pad376[0x38C - 0x376];
    unsigned char unk38C;
} DwcFriendsMatchObj;

extern DwcFriendsMatchObj *lbl_805A0F88;

extern int fn_803F6150(const void *, const void *, unsigned long);
extern unsigned long fn_803FC570(const char *, char **, int);
extern void fn_80335638(int, const char *, ...);
extern void fn_80341148(void *, int, const char *);

void fn_8033B8CC(void *arg0, void *arg1)
{
    char buf[12] = {0};
    const char *base = lbl_80489E48;
    char *str = *(char **)((char *)arg1 + 8);
    DwcFriendsMatchObj *obj;
    const DwcFriendsMatchObj *cobj;
    unsigned int len;

    if (fn_803F6150(str, lbl_8059F0A4, strlen(lbl_8059F0A4)) != 0) {
        fn_80335638(8, base + 0xA08, str);
        return;
    }

    str += strlen(lbl_8059F0A4);
    len = strchr(str, 'v') - str;
    strncpy(buf, str, len);

    if (len > 10 || fn_803FC570(buf, 0, 10) != 11) {
        fn_80335638(8, base + 0xA30, str);
        return;
    }

    str += len + 1;
    if (fn_803F6150(str, lbl_8059F0AC, strlen(lbl_8059F0AC)) == 0) {
        obj = lbl_805A0F88;
        cobj = lbl_805A0F88;
        if (obj->unk24 == 5)
            goto accepted;
        if (obj->unk24 != 6)
            goto rejected;
        if (obj->unk375 == 2)
            goto accepted;
        if (cobj->unk375 != 3)
            goto rejected;

accepted:
        {
            char *value = str + strlen(lbl_8059F0AC);
            fn_80341148(arg0, *(int *)arg1, value);
        }
        goto done;

rejected:
        fn_80335638(4, base + 0xA68);
    }

done:
    ;
}