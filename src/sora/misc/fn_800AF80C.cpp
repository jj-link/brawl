#include <types.h>
#pragma force_active on

extern u8 lbl_80455458[];

class muMenu {
public:
    u8 exchangeMuSelchkind2GmCharacterKind(int, int, int);
};

u8 muMenu::exchangeMuSelchkind2GmCharacterKind(int arg0, int arg1, int arg2) {
    u8 v;
    v = lbl_80455458[((int)this) << 4];
    if (v == 0xFF) {
        v = 0x3E;
    }
    return v;
}
