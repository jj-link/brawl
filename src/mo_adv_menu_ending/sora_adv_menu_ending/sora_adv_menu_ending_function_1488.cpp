#pragma force_active on
#pragma opt_propagation off

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

class utRelocate {
    u8 data[0x34];

public:
    utRelocate(u8*, u32);
    ~utRelocate();
    void* getPublicAddress(const char*) const;
};

struct EndingHeader {
    u16 count;
    u8 field2;
    u8 field3;
};

struct EndingTask {
    u8 pad0[0x48];
    void* handle;
    u8 pad4C[0x3C];
    EndingHeader* header;
    void* field8C;
    void* field90;
    void* field94;
    void* field98;
    void* field9C;
    void* fieldA0;
    void* fieldA4;
    u32 count;
    u32 fieldAC;
    u32 fieldB0;
};

extern "C" {
extern char lbl_37_data_0[];
void* getBuffer__14gfFileIOHandleCFv(const void*);
u32 getSize__14gfFileIOHandleCFv(const void*);

void fn_37_1488(EndingTask* self) {
    const char* names = lbl_37_data_0;
    u8* buffer = (u8*)getBuffer__14gfFileIOHandleCFv(&self->handle);
    u32 size = getSize__14gfFileIOHandleCFv(&self->handle);
    utRelocate reloc(buffer, size);

    self->header = (EndingHeader*)reloc.getPublicAddress(names + 0x18C);
    self->field8C = reloc.getPublicAddress(names + 0x19C);
    self->field90 = reloc.getPublicAddress(names + 0x1AC);
    self->field94 = reloc.getPublicAddress(names + 0x1C4);
    self->field98 = reloc.getPublicAddress(names + 0x1D8);
    self->field9C = reloc.getPublicAddress(names + 0x1F0);
    self->fieldA0 = reloc.getPublicAddress(names + 0x208);
    self->fieldA4 = reloc.getPublicAddress(names + 0x220);

    EndingHeader* header = self->header;
    self->count = header->count;
    self->fieldAC = header->field2;
    self->fieldB0 = header->field3;
}
}
