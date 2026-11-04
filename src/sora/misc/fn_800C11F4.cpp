#include <ty/ty_fig_listmng.h>
#include <gf/gf_file_io_handle.h>
#include <mu/menu.h>
#include <stdio.h>
#pragma force_active on

extern "C" {
int fn_800AD954(void*);
char* fn_800AE578(void*, unsigned short);
extern char lbl_80456EC0[];
extern char lbl_80456ED0[];
}

extern "C" int fn_800C11F4(char* self)
{
    if (*(tyFigListDataManager**)(self + 0x228) &&
        !(*(tyFigListDataManager**)(self + 0x228))->isLoadFinish()) {
        return *(int*)(self + 0x10c);
    }
    if (*(void**)(self + 0x2b8) &&
        !fn_800AD954(*(void**)(self + 0x2b8))) {
        return *(int*)(self + 0x10c);
    }

    char names[0xa0];
    int i;
    char* entry = self + 0x11c;
    char* figHandle = self + 0x234;
    char* sealHandle = self + 0x2c4;
    char* faceHandle = self + 0x34c;
    i = 0;
    for (; i < *(int*)(self + 0x21c); ++i) {
        switch (*(int*)entry) {
        case 0: {
            (*(tyFigListDataManager**)(self + 0x228))->getBilTexFileNameFigId(
                *(unsigned short*)(entry + 8), names);
            ((gfFileIOHandle*)figHandle)->readRequest(names, (HeapType)0x2b, 0, 0);
            break;
        }
        case 1: {
            sprintf(names + 0x20, lbl_80456EC0,
                *(char**)(fn_800AE578(*(void**)(self + 0x2b8), *(unsigned short*)(entry + 8)) + 8));
            ((gfFileIOHandle*)sealHandle)->readRequest(names + 0x20, (HeapType)0x2b, 0, 0);
            break;
        }
        case 2:
            break;
        case 3: {
            sprintf(names + 0x60, lbl_80456ED0, muMenu::exchangeGmCharacterKind2Something(
                muMenu::exchangeMuSelchkind2MuStockchkind(*(int*)(entry + 8))));
            ((gfFileIOHandle*)faceHandle)->readRequest(names + 0x60, (HeapType)0x2b, 0, 0);
            break;
        }
        }
        entry += 0x10;
        figHandle += 8;
        sealHandle += 8;
        faceHandle += 8;
    }
    return 1;
}
