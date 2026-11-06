#pragma force_active on

#include <mu/menu.h>
#include <gf/gf_file_io_handle.h>
#include <stdio.h>
#include <string.h>

extern "C" {
extern const float lbl_3_rodata_84B0;
extern const char lbl_3_data_BC0[];
}

extern "C" void fn_3_D7EC(
    void* arg0, int arg1, int arg2, int arg3,
    unsigned int count, const void* input)
{
    char* self = (char*)arg0;
    *(int*)(self + 0x30c) = arg1;
    *(int*)(self + 0x310) = arg2;
    *(int*)(self + 0x314) = arg3;
    *(unsigned int*)(self + 0x304) = count;

    char path[64];
    const char* src = (const char*)input;
    char* dest = self + 0x1b4;
    char* cursor = self;

    for (unsigned int i = 0; i < *(unsigned int*)(self + 0x304); ++i) {
        memcpy(dest, src, 0x2c);
        self[0x346 + i] = 0;

        int kind = muMenu::exchangeMuSelchkind2MuStockchkind(
            *(int*)(cursor + 0x1d0));
        kind = muMenu::exchangeGmCharacterKind2Something(kind);

        // CodeWarrior supplies the signed-integer conversion bias.
        sprintf(
            path, lbl_3_data_BC0,
            (unsigned int)((float)(kind * 10 + 1) - lbl_3_rodata_84B0));

        ((gfFileIOHandle*)(self + 0x34c) + (i + 6))->readRequest(
            path, (Heaps::HeapType)0x2b, 0, 0);

        src += 0x2c;
        dest += 0x2c;
        cursor += 0x2c;
    }

    for (unsigned int i = *(unsigned int*)(self + 0x304); i < 4; ++i) {
        self[0x346 + i] = 1;
    }

    self[0x264] = 1;
}
