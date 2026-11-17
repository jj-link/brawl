#include <gf/gf_archive.h>
#include <types.h>
#pragma force_active on

extern "C" char lbl_80461030[];
extern "C" void fn_80014ED4(gfArchive*, const char*, s32, s32);
extern "C" u16 fn_8014E1EC(void);
extern "C" u16* getData__9gfArchiveF11ARCNodeTypeiPiUs(
    gfArchive*, s32, u16, u32*, u16);

static inline s32 findLine(u16* data, u32 size, s32 remaining, u32& idx) {
    idx = 0;
    while (idx < size && remaining > 0) {
        if (data[idx++] == 0) {
            remaining--;
            if (remaining == 0) {
                break;
            }
        }
    }
    return remaining;
}

extern "C" u32 fn_8014F320(s32* arg0, s32 arg1, u16* arg2, u32 arg3) {
    u32 idx;
    u16* data;
    u32 count;
    u32 size;
    s32 remaining;

    memset(arg2, 0, arg3 * 2);
    count = 0;
    gfArchive archive;
    fn_80014ED4(&archive, lbl_80461030, arg0[1], 0);

    data = getData__9gfArchiveF11ARCNodeTypeiPiUs(
        &archive, 1, fn_8014E1EC(), &size, 0xFFFE);
    if (data == 0) {
        data = getData__9gfArchiveF11ARCNodeTypeiPiUs(
            &archive, 1, 1, &size, 0xFFFE);
    }

    if (data != 0) {
        remaining = findLine(data, size, arg1 - 1, idx);
        if (remaining == 0) {
            while (idx < size) {
                u16 t = data[idx];
                if (t == 0) {
                    break;
                }
                if (t == 0xD) {
                    arg2[count] = 0xA;
                } else {
                    arg2[count] = t;
                }
                count++;
                idx++;
                if (count >= arg3) {
                    break;
                }
            }
        }
    }

    return count;
}
