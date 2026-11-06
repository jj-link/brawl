#include <types.h>
#include <gf/gf_file_io_handle.h>
#include <mu/menu.h>
#pragma force_active on
extern "C" char lbl_3_data_B38[];
extern "C" const float lbl_3_rodata_84B0;
extern "C" int sprintf(char*, const char*, ...);

struct Entry { int kind; char pad[0x28]; };
struct State {
    char pad0[0x120];
    Entry entries1[4];
    char entries2[0x94];
    unsigned char mode;
    char pad1[0x300-0x265];
    unsigned int count1;
    unsigned int count2;
    char pad2[0x342-0x308];
    unsigned char ready1[4];
    unsigned char ready2[4];
    gfFileIOHandle handles[10];
};

extern "C" void fn_3_ACD4(State* self) {
    char buf[0x40];
    char* names = lbl_3_data_B38;
    self->handles[0].readRequest(names + 0x4c, (HeapType)0x2b, 0, 0);
    self->handles[1].readRequest(names + 0x68, (HeapType)0x2b, 0, 0);
    unsigned int i;
    char* p = (char*)self;
    for (i = 0; i < self->count1; p += 0x2c, i++) {
        int kind = muMenu::exchangeMuSelchkind2MuStockchkind(*(int*)(p + 0x120));
        int value = muMenu::exchangeGmCharacterKind2Something(kind) * 10 + 1;
        sprintf(buf, names + 0x88, (unsigned int)((float)value - lbl_3_rodata_84B0));
        self->handles[i + 2].readRequest(buf, (HeapType)0x2b, 0, 0);
    }
    for (i = self->count1; i < 4; i++) self->ready1[i] = 1;
    if (self->mode == 1) {
        p = (char*)self;
        for (i = 0; i < self->count2; p += 0x2c, i++) {
            int kind = muMenu::exchangeMuSelchkind2MuStockchkind(*(int*)(p + 0x1d0));
            int value = muMenu::exchangeGmCharacterKind2Something(kind) * 10 + 1;
            sprintf(buf, names + 0x88, (unsigned int)((float)value - lbl_3_rodata_84B0));
            self->handles[i + 6].readRequest(buf, (HeapType)0x2b, 0, 0);
        }
        for (i = self->count2; i < 4; i++) self->ready2[i] = 1;
    } else {
        self->ready2[0] = 1;
        self->ready2[1] = 1;
        self->ready2[2] = 1;
        self->ready2[3] = 1;
    }
}