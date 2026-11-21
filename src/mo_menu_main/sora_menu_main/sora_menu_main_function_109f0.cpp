#include <mu/mu_msg.h>
#include <mu/menu.h>
#include <nw4r/g3d/g3d_scnmdl.h>
#include <nw4r/g3d/g3d_scngroup.h>
#include <stdio.h>
#include <string.h>

#pragma force_active on
#pragma opt_loop_invariants off

extern "C" {
void fn_2_10EC0(void*, char*, int, int);
void fn_2_112A8(void*);
unsigned int fn_800AEE30(void*, int);
int fn_800AEF54(void*, int, unsigned int);
int exchangeGmCharacterKindToMuCharKind__6muMenuFiii(int);
int isCharUsable__6muMenuFiii(int);
void* getMsgData__5MuMsgFUlPPv(MuMsg*, unsigned long, void**);
void fn_800B92D8(MuMsg*, unsigned long, char*, unsigned long);
void fn_800B7224(MuObject*, unsigned int, char*, void*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}

extern char lbl_2_data_1398[];
extern char* lbl_2_data_878[];
extern const float lbl_2_rodata_41C;
extern const float lbl_2_rodata_414;

struct Entry {
    int id;
    char pad04[8];
    unsigned long title;
    char pad10[0x18];
    unsigned char flag;
    char pad29[3];
    unsigned long description;
    float value;
    float format;
};

struct Self {
    char pad0[0x4c];
    char* manager;
    int f50;
    int selected;
    char pad58[0xb0];
    int page;
    Entry* entries[3130];
    int offsets[2011];
    int number;
    char pad5164[0x14];
    MuObject* badge;
    MuObject* objects[48];
    MuObject* visible[32];
    nw4r::g3d::ScnGroup* group;
    char pad52c0[8];
    MuMsg* message;
    int f52cc;
    MuMsg* numbers;
};

#define FIELD(type, p, off) (*(type*)((char*)(p) + (off)))
#define INDEX(type, p, off, i) FIELD(type, (char*)(p) + (i) * 4, off)

extern "C" void fn_2_109F0(Self* self) {
    char buffer[256];
    char texture[64];
    char number[32];
    char bone[8];
    void* length;
    char* data = lbl_2_data_1398;
    unsigned int count;
    char* cursor2;
    char* cursor3;
    MuObject* object;
    unsigned int tag;
    unsigned int j;
    int character;

    fn_2_10EC0(self, buffer,
              self->selected + self->offsets[self->page] + 1, 4);
    fn_2_10EC0(self, number, self->number, -1);
    sprintf(buffer, data + 0x3c8, buffer, lbl_2_data_878[10], number);
    self->numbers->printf(0, buffer);

    self->message->printIndex(
        6, self->entries[self->selected]->title,
        FIELD(void*, self->numbers, 4));

    if (lbl_2_rodata_41C == self->entries[self->selected]->format) {
        self->message->printIndex(
            7, self->entries[self->selected]->description, 0);
    } else {
        memset(buffer, 0, 256);
        void* msg = getMsgData__5MuMsgFUlPPv(
            self->message, self->entries[self->selected]->description,
            &length);
        memcpy(buffer, msg, (unsigned long)length);
        int n = sprintf(buffer, data + 0x3d0, buffer,
                        (int)self->entries[self->selected]->value);
        fn_800B92D8(self->message, 7, buffer, n);
    }

    sprintf(
        buffer, data + 0x3d8,
        FIELD(unsigned short,
              self->manager + INDEX(int, self->manager, 0x7e4,
                                    self->selected + self->offsets[self->page]) * 2,
              0x14));
    self->message->printf(8, buffer);

    count = fn_800AEE30(
        self->manager, self->entries[self->selected]->id);

    if (count <= 5) {
        char* cursor = (char*)self;
        unsigned int i = 0;
        unsigned int used = 0;

        for (; i < count; ++i) {
            character = fn_800AEF54(
                self->manager, self->entries[self->selected]->id, i);

            if (isCharUsable__6muMenuFiii(
                    exchangeGmCharacterKindToMuCharKind__6muMenuFiii(
                        character))) {
                sprintf(bone, data + 0x3e0, used + 2);
                Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(
                    self->group,
                    FIELD(MuObject*, cursor, 0x517c)->m_scnMdl, bone);

                object = FIELD(MuObject*, cursor, 0x517c);
                tag = i + 0x13;
                fn_801AAFF0(object->m_scnMdl, tag);
                fn_801AB014(object->m_scnMdl, tag);

                unsigned int frame;
                if (character == 0x1d) {
                    frame = 0x10f;
                } else {
                    frame = (unsigned int)(float)(
                        muMenu::exchangeGmCharacterKind2Something(
                            muMenu::exchangeGmCharacterKind2MuStockchkind(
                                character)) * 10 + 1);
                }

                sprintf(texture, data + 0x3e8, frame);
                object = FIELD(MuObject*, cursor, 0x517c);
                nw4r::g3d::ResMat mat =
                    object->m_resMdl.GetResMat(data + 0x3f8);
                fn_800B7224(object, mat->m_id, texture,
                            (char*)self + 0x5358);
                cursor += 4;
                ++used;
            }
        }

        cursor2 = (char*)self + used * 4;
        for (; used < 5; cursor2 += 4, ++used) {
            self->group->Remove(
                FIELD(MuObject*, cursor2, 0x517c)->m_scnMdl);
        }
        self->message->printIndex(9, 0x62, 0);
    } else {
        cursor3 = (char*)self;
        j = 0;
        do {
            self->group->Remove(
                FIELD(MuObject*, cursor3, 0x517c)->m_scnMdl);
            ++j;
            cursor3 += 4;
        } while (j < 5);
        self->message->printf(9, data + 0x408);
    }

    fn_2_10EC0(self, buffer, self->page + 1, -1);
    self->numbers->printf(1, buffer);
    fn_2_10EC0(self, buffer, self->page + 2, -1);
    self->numbers->printf(2, buffer);
    fn_2_112A8(self);

    FIELD(unsigned char,
          INDEX(int, self->manager, 0x7e4,
                self->selected + self->offsets[self->page]) + self->manager,
          0x2724) = 0;

    self->visible[self->selected]->setFrameVisible(lbl_2_rodata_41C);
    if (self->entries[self->selected]->flag == 1) {
        self->badge->setFrameVisible(lbl_2_rodata_414);
    } else {
        self->badge->setFrameVisible(lbl_2_rodata_41C);
    }
}
