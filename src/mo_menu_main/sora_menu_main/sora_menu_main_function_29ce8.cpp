#include <types.h>
#include <mu/menu.h>
#include <mu/mu_msg.h>
#pragma force_active on

extern "C" int exchangeMuCharKindToMuStockchkind__6muMenuFiii(int);
extern "C" char lbl_2_data_34DC;

extern "C" void fn_2_29CE8(u8* self, int enabled) {
    int index = *(int*)(self + 0x694);
    const char* name;
    if (enabled && index < *(int*)(*(u8**)(self + 0x6a4) + 0x8c) - 1) {
        name = muMenu::exchangeMuStockchkind2MuCharName(exchangeMuCharKindToMuStockchkind__6muMenuFiii((*(int**)(self + 0x6a4))[index + 1]));
    } else {
        name = &lbl_2_data_34DC;
    }
    (*(MuMsg**)(self + 0x678))->printf(*(unsigned long*)(self + 0x66c) + 3, name);
    if (enabled && index > 0) {
        name = muMenu::exchangeMuStockchkind2MuCharName(exchangeMuCharKindToMuStockchkind__6muMenuFiii((*(int**)(self + 0x6a4))[index - 1]));
    } else {
        name = &lbl_2_data_34DC;
    }
    (*(MuMsg**)(self + 0x678))->printf(*(unsigned long*)(self + 0x66c) + 2, name);
}