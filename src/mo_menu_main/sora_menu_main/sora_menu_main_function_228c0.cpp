#include <nw4r/g3d/g3d_scnmdl.h>
#include <snd/snd_system.h>
#include <internal/printf.h>
#pragma force_active on
struct Class_728_base { char pad[0x3c]; };
class Class_728 : public Class_728_base {
public:
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23(int, int, void*);
};
struct ModelHolder { char pad[0x2c]; nw4r::g3d::ScnMdl* model; };
struct NodeHolder { char pad[0x10]; void* node; };
struct Objects { char pad[0x214]; NodeHolder* holder; };
struct Context { char pad[4]; void* value; };
struct Menu {
    char pad[0x64c];
    Objects* objects;
    ModelHolder* model;
    char pad654[4];
    Class_728* task;
    char pad65c[0x18];
    int* entries;
    unsigned char count;
    unsigned char page;
    unsigned char column;
    unsigned char row;
    Context* context;
};
extern "C" {
extern const unsigned char lbl_2_rodata_970[6][2];
extern const unsigned short lbl_2_rodata_97C[][2];
extern char lbl_2_data_2B98[];
void fn_2_2262C(Menu*, unsigned char);
void Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(void*, void*, char*);
}
inline int pageCount(Menu* self) {
    int count = self->count - self->page * 6;
    if (count > 6) count = 6;
    return count;
}
inline int rowCount(Menu* self) {
    const unsigned char* data = lbl_2_rodata_970[pageCount(self) - 1];
    int count = 0;
    if (data[0]) count++;
    if (data[1]) count++;
    return count;
}
inline unsigned char columnCount(Menu* self, int row) {
    return lbl_2_rodata_970[pageCount(self) - 1][row];
}
inline unsigned char position(Menu* self, unsigned char column, unsigned char row) {
    int index = 0;
    for (int i = 0; i < row; i++) {
        index += lbl_2_rodata_970[pageCount(self) - 1][i];
    }
    index += column;
    return index;
}
inline unsigned char positionFirst(Menu* self, unsigned char column, unsigned char row) {
    int i;
    int index = 0;
    for (i = 0; i < row; i++) {
        index += lbl_2_rodata_970[pageCount(self) - 1][i];
    }
    index += column;
    return index;
}
inline void updateCursorImpl(Menu* self, unsigned char column, unsigned char row) {
    void* node = self->objects->holder->node;
    self->model->model->RemoveAnmObj((nw4r::g3d::ScnMdlSimple::AnmObjType)(unsigned long)node);
    char buffer[8];
    sprintf(buffer, lbl_2_data_2B98, positionFirst(self, column, row));
    Pushback__Q34nw4r3g3d6ScnMdlFPvPvPc(self->model->model, node, buffer);
    unsigned char pos = position(self, column, row);
    int entry = self->entries[self->page * 6 + pos];
    unsigned short id;
    switch (entry) {
    default: id = lbl_2_rodata_97C[entry][1]; break;
    case 0x79: id = 11; break;
    }
    self->task->slot23(id, 1, self->context->value);
}
inline void updateCursor(Menu* self, unsigned char column, unsigned char row) {
    updateCursorImpl(self, column, row);
}
extern "C" int fn_2_228C0(Menu* self, int flags) {
    int changed = 0;
    if (flags & 1) {
        if (self->row != 0) {
            self->row--;
            int count = columnCount(self, self->row);
            if (self->column >= count) self->column = count - 1;
            changed = 1;
        }
    }
    if (flags & 2) {
        if (self->row < rowCount(self) - 1) {
            self->row++;
            int count = columnCount(self, self->row);
            if (self->column >= count) self->column = count - 1;
            changed = 1;
        }
    }
    if (flags & 4) {
        if (self->column != 0) {
            self->column--;
            changed = 1;
        } else if (self->page != 0) {
            self->page--;
            fn_2_2262C(self, self->page);
            int count = rowCount(self);
            if (self->row >= count) self->row = count - 1;
            self->column = columnCount(self, self->row) - 1;
            changed = 1;
        }
    }
    if (flags & 8) {
        if (self->column < columnCount(self, self->row) - 1) {
            self->column++;
            changed = 1;
        } else if (self->page < (self->count + 5) / 6 - 1) {
            self->page++;
            fn_2_2262C(self, self->page);
            int count = rowCount(self);
            if (self->row >= count) self->row = count - 1;
            self->column = 0;
            changed = 1;
        }
    }
    if (changed) {
        updateCursor(self, self->column, self->row);
        g_sndSystem->playSE((SndID)0, -1, 0, 0, -1);
    }
    return changed;
}
