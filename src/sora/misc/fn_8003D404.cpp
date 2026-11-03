#include <gf/gf_pad_system.h>
#include <string.h>
#pragma force_active on
extern "C" int fn_8021A024(int, int*);
extern "C" char* lbl_8059C770;
struct Pair { int a; int b; };
struct Record {
    unsigned char first;
    char name[4];
    unsigned char mode;
    unsigned char other;
    char pad;
    int value;
    Pair entries[4];
    Pair pads[4];
};
extern "C" void fn_8003D404(Record* record, int first, int other, int value, int mode) {
    int out;
    gfPadStatus status;
    memset(record, 0, 0x4c);
    record->first = first;
    memcpy(record->name, lbl_8059C770, 4);
    record->other = other;
    record->value = value;
    record->mode = (mode != 0) + 1;
    Record* entry = record;
    for (int i = 0; i < 4; ++i, entry = (Record*)((char*)entry + 8)) {
        entry->entries[0].a = fn_8021A024(i, &out);
        entry->entries[0].b = out;
    }
    for (int i = 0; i < 4; ++i, record = (Record*)((char*)record + 8)) {
        g_gfPadSystem->getSysPadStatus(i, &status);
        record->pads[0].a = status.m_error;
        record->pads[0].b = 0;
    }
}