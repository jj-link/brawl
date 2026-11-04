#include <revolution/OS/OSMutex.h>
#include <revolution/OS/OSCache.h>
#include <revolution/OS/OSError.h>
#pragma force_active on

extern char lbl_804927E0[];
extern int lbl_8059FE98;
extern OSMutex lbl_80563940;
extern int lbl_805A1234;
extern int *lbl_805A1238;
extern int *lbl_805A1240;

extern int fn_803CB620(int, unsigned int, int, int, unsigned int, void *, unsigned int, unsigned int, int, int *, int, int);
extern int fn_803CC5F0(void *, int);
extern int fn_80212D40(int, int, void *, unsigned int, void *, unsigned int);

typedef struct {
    int fd;
    unsigned int unk4[3];
    unsigned int unk10;
    unsigned int unk14[3];
    unsigned int limit;
    unsigned int state;
} Card;

int fn_803CBCD8(Card *card, unsigned int offset, void *data, unsigned int size, int callback, int arg)
{
    int response2[4];
    int response1[4];
    char *base = lbl_804927E0;
    int result;
    unsigned int blockSize = 0x200;
    unsigned int blocks;

    if (size <= 0x200U)
        blockSize = size;
    blocks = size >> 9;
    if (lbl_8059FE98 < 0) {
        result = (int)0xC1000000;
        goto done;
    }
    if (size != blockSize * blocks) {
        OSReport(base + 0x3B0, base + 0x438, size);
        result = -4;
        goto done;
    }
    if (offset != (offset & ~0x1FFU)) {
        OSReport(base + 0x454, base + 0x438, offset);
        result = -4;
        goto done;
    }
    if (card->limit != 0 && offset > card->limit) {
        OSReport(base + 0x3E0, base + 0x438, offset);
        result = -4;
        goto done;
    }
    if (card->state == 0) {
        OSReport(base + 0x3FC, base + 0x438);
        result = (int)0xC1000000;
        goto done;
    }
    OSLockMutex(&lbl_80563940);
    if (lbl_805A1234 != 0) {
        OSUnlockMutex(&lbl_80563940);
        result = (int)0xC1000000;
        goto done;
    }
    lbl_805A1234 = 1;
    OSUnlockMutex(&lbl_80563940);
    if (card->state == 2) {
        result = fn_803CB620(card->fd, 7, 3, 2, card->unk10, 0, 0, 0, 0, response1, 0, 0);
        if (result != 0) {
            OSReport(base + 0x338, result);
        } else {
            card->state = 1;
            result = fn_803CB620(card->fd, 0x10, 3, 1, 0x200, 0, 0, 0, 0, response2, 0, 0);
            if (result != 0) {
                OSReport(base + 0x358, base + 0x234, result);
            } else {
                result = fn_803CC5F0(card, 4);
                if (result != 0) {
                    OSReport(base + 0x358, base + 0x234, result);
                } else {
                    int rc;
                    int fd = card->fd;
                    *lbl_805A1238 = 1;
                    rc = fn_80212D40(fd, 6, lbl_805A1238, 4, 0, 0);
                    if (rc != 0) {
                        OSReport(base + 0x148);
                        rc = (int)0xC1000000;
                    }
                    result = rc;
                    if (rc != 0)
                        OSReport(base + 0x358, base + 0x234, rc);
                }
            }
        }
        if (result != 0) {
            lbl_805A1234 = 0;
            goto done;
        }
    }
    DCFlushRange(data, size);
    result = fn_803CB620(card->fd, 0x19, 3, 1, offset, data, blocks, blockSize, 1, lbl_805A1240, callback, arg);
    if (result != 0) {
        OSReport(base + 0x474, base + 0x438, result);
        lbl_805A1234 = 0;
    }
    if (callback == 0)
        lbl_805A1234 = 0;
done:
    return result;
}
