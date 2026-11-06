#include <types.h>
#include <revolution/GX/GXPixel.h>
#pragma force_active on

extern "C" u8 fn_80191124(u8**);

struct ZCompCache {
    u32 flags;
    u8 value;
    u8 padding[3];
};

extern ZCompCache lbl_805A0550;
extern u8 lbl_805A0538;

extern "C" void fn_8019F150(u8** p) {
    if (*p != 0) {
        u8 value = fn_80191124(p);
        if (!(lbl_805A0550.flags & 1) || lbl_805A0550.value != value) {
            lbl_805A0550.value = value;
            lbl_805A0550.flags |= 1;
            GXSetZCompLoc(value);
            lbl_805A0538 = 1;
        }
    }
}
