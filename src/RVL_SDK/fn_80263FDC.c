#include <types.h>
#pragma force_active on

void fn_80263FDC(void* self, s32 arg1, s32 arg2)
{
    u8* p = (u8*)self;
    switch (arg1) {
    case 0:
        *(u8**)(p + 0x440) = p + 0x460;
        *(u8**)(p + 0x448) = p + 0x1570;
        *(u8**)(p + 0x444) = p + 0x1460;
        break;
    case 1:
        *(u8**)(p + 0x440) = p + 0x860;
        *(u8**)(p + 0x448) = p + 0x1580;
        *(u8**)(p + 0x444) = p + 0x14A4;
        break;
    }
    switch (arg2) {
    case 0:
        *(u8**)(p + 0x450) = p + 0xC60;
        *(u8**)(p + 0x458) = p + 0x1590;
        *(u8**)(p + 0x454) = p + 0x14E8;
        return;
    case 1:
        *(u8**)(p + 0x450) = p + 0x1060;
        *(u8**)(p + 0x458) = p + 0x1690;
        *(u8**)(p + 0x454) = p + 0x152C;
        return;
    }
}
