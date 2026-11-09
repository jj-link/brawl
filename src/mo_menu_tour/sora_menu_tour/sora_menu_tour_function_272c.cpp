#include <types.h>
#include <gf/gf_task.h>
#include <gf/gf_file_io_handle.h>
#include <gf/gf_archive.h>
#include <gf/gf_pad_system.h>
#include <gf/gf_pad_status.h>
#include <gm/gm_global.h>
#include <mu/menu.h>
#include <mu/mu_msg.h>
#include <string.h>

#pragma force_active on

struct TourPaths {
    const char* values[8];
};

extern "C" {
void* __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
    void*, const char*, int, int, int, bool);
void __dt__14gfFileIOHandleFv(void*, int);
void __construct_array(void*, void (*)(void*), void (*)(void*),
                       unsigned long, int);
void fn_3_2DC8(void*);
void fn_800B96E8(void*, int);
void* fn_800AFB94(const char*, int, const char*);
unsigned int exchangeMuCharKindToGmCharacterKind__6muMenuFiii(int);
unsigned int fn_8004F4A0(unsigned int);
void* fn_800B08A8(int);
void fn_800151FC(void*, const char*, int, int, int, int);
MuMsg* create__5MuMsgFUlQ25Heaps8HeapTypeUl(
    unsigned long, HeapType, unsigned long);

extern char lbl_3_data_110[];
extern char lbl_3_data_AA0[];
extern const float lbl_3_rodata_81EC;
extern const int lbl_3_rodata_8160[];
extern TourPaths lbl_3_data_658;
}

struct TourEntry {
    int value;
    char padding[0x20];
    unsigned char timer;
    char padding2[3];
};

struct TourResource {
    char padding[0x40];
    int* values;
    int count;
};

struct TourTask {
    char base[0x2c];
    unsigned char flags;
    char pad2d[0xf];
    void* vtable;
    void* heap;
    int field44;
    int field48;
    int field4c;
    char menuState[0xa8];
    MuMsg* messages[3];
    TourEntry entries[32];
    unsigned char field604;
    unsigned char field605;
    char pad606[2];
    int field608;
    int field60c;
    int resourceValues[0xc3];
    int extraValues[40];
    TourResource* resource;
    int field9c0;
    unsigned char field9c4;
    char pad9c5[3];
    int fields9c8[6];
    unsigned int playerCount;
    int fields9e4[3];
    unsigned char field9f0;
    char pad9f1[3];
    int field9f4;
    int field9f8;
    int field9fc;
    unsigned int characterCount;
    int fielda04;
    int fielda08;
    int fielda0c;
    unsigned char fielda10[4];
    int fieldsa14[5];
    float fielda28;
    unsigned char fielda2c;
    char pada2d[3];
    int fielda30;
    int fielda34;
    float fielda38;
    unsigned char fielda3c;
    char pada3d[3];
    int fielda40;
    int fielda44;
    int fielda48;
    int characters[36];
    int fieldadc;
    int fieldae0;
    gfArchive* archive1;
    gfArchive* archive2;
    unsigned char flagsaec[11];
    char padaf7;
    gfFileIOHandle handles[8];
    void* argument;
    unsigned char fieldb1c;
};

static inline void readTourFile(
    TourTask* const& self, int index, const char* path)
{
    self->handles[index].readRequest(path, (HeapType)0x2b, 0, 0);
}

extern "C" TourTask* fn_3_272C(TourTask* input, void* argument)
{
    const char* data = lbl_3_data_110;
    TourTask* self = input;

    __ct__6gfTaskFPCcQ26gfTask8Categoryiib(
        self, data + 0x3c8, 0x12, 0xe, 6, true);

    self->vtable = lbl_3_data_AA0;
    self->field44 = 0;
    self->field48 = 0;
    self->field4c = 0;
    fn_800B96E8(self->menuState, 0xff);

    self->field604 = 0;
    self->field605 = 0;
    self->field608 = 0;
    self->field60c = 0;
    self->field9c0 = 0;
    self->field9c4 = 0;
    self->fields9c8[0] = 0;
    self->fields9c8[1] = 0;
    self->fields9c8[2] = 0;
    self->fields9c8[3] = 0;
    self->fields9c8[4] = 0;
    self->fields9c8[5] = 0;
    self->playerCount = 0;
    self->fields9e4[0] = 0;
    self->fields9e4[1] = 0;
    self->fields9e4[2] = 0;
    self->field9f0 = 0;
    self->field9f4 = 0;
    self->field9f8 = 0;
    self->field9fc = 0;
    self->fielda04 = 0;
    self->fielda08 = 0;
    self->fielda0c = 9;
    self->fielda10[0] = 0;
    self->fielda10[1] = 0;
    self->fielda10[2] = 0;
    self->fielda10[3] = 0;
    self->fieldsa14[0] = 0;
    self->fieldsa14[1] = 0;
    self->fieldsa14[2] = 0;
    self->fieldsa14[3] = 0;
    self->fieldsa14[4] = 0;
    self->fielda28 = lbl_3_rodata_81EC;
    self->fielda2c = 0;
    self->fielda30 = 0;
    self->fielda34 = 0;
    self->fielda38 = lbl_3_rodata_81EC;
    self->fielda3c = 0;
    self->fielda40 = 0;
    self->fielda44 = 0x29;
    self->fieldadc = 0;
    self->fieldae0 = 0;
    self->archive1 = 0;
    self->archive2 = 0;

    __construct_array(self->handles, fn_3_2DC8,
                      (void (*)(void*))__dt__14gfFileIOHandleFv, 4, 8);

    self->argument = argument;
    self->fieldb1c = 0;
    self->flags &= ~2;
    self->heap = fn_800AFB94(data + 0x3d8, 0x12c, data + 0x3e8);

    self->field604 =
        *((unsigned char*)g_GameGlobal->m_tournamentData + 0x509);
    self->field9f4 =
        *(int*)((char*)g_GameGlobal->m_tournamentData + 0x50c);

    int pad;
    unsigned int count;
    count = 0;
    pad = 0;

    while (pad < 8 && count < 4) {
        gfPadStatus status;
        g_gfPadSystem->getSysPadStatus(pad, &status);
        if (status.m_error >= 0)
            ++count;
        ++pad;
    }

    self->playerCount = count;
    if (count < 2)
        self->playerCount = 2;

    self->characterCount = 0;
    const int* kinds = lbl_3_rodata_8160;
    for (unsigned int i = 0; i < 0x23; ++i, ++kinds) {
        int kind = *kinds;
        if (fn_8004F4A0(
                exchangeMuCharKindToGmCharacterKind__6muMenuFiii(kind)) == 1) {
            self->characters[self->characterCount] = kind;
            ++self->characterCount;
        }
    }

    self->characters[self->characterCount] = 0x23;
    ++self->characterCount;

    TourResource* resource = (TourResource*)fn_800B08A8(0x2a);
    self->resource = resource;
    resource->values = self->resourceValues;
    resource->count = 0xc3;

    for (int i = 0; i < 0xc3; ++i)
        self->resourceValues[i] = 0;
    for (int i = 0; i < 40; ++i)
        self->extraValues[i] = 0;

    self->field608 = 0;
    self->field60c = 0;
    for (int i = 0; i < 11; ++i)
        self->flagsaec[i] = 0;

    self->archive1 = new ((HeapType)0x2b) gfArchive;
    self->archive2 = new ((HeapType)0x2b) gfArchive;

    TourPaths paths = lbl_3_data_658;
    unsigned int i;
    const char** path = paths.values;
    for (i = 0; i < 8; ++i) {
        readTourFile(self, i, *path);
        ++path;
    }

    fn_800151FC(self->archive1, data + 0x414, 0x2b, 0, 0, 0xff);
    fn_800151FC(self->archive2, data + 0x438, 0x2b, 0, 0, 0xff);
    muMenu::loadMenuSound();

    self->messages[0] =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)0x2a, 0x2b);
    self->messages[0]->allocMsgBuf(0x100, 0x13);
    self->messages[1] =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(2, (HeapType)0x2a, 0x2b);
    self->messages[1]->allocMsgBuf(0x40, 0x25);
    self->messages[2] =
        create__5MuMsgFUlQ25Heaps8HeapTypeUl(1, (HeapType)0x2a, 0x2b);
    self->messages[2]->allocMsgBuf(0x100, 1);

    fn_800B96E8(self->menuState, 0xf0);
    memset(self->entries, 0, 0x500);

    for (int i = 0; i < 32; ++i) {
        self->entries[i].value = 0;
        self->entries[i].timer = 0x78;
    }

    unsigned char* rule = (unsigned char*)g_GameGlobal->m_setRule;
    if (rule[2] != 1 && rule[3] == 0)
        rule[3] = 1;

    return self;
}
