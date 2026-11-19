#include <gf/gf_file_io_handle.h>
#include <gf/gf_heap_manager.h>
#include <gm/gm_global.h>
#include <ut/ut_relocate.h>
#pragma force_active on

extern const char lbl_29_data_104[];
extern const float lbl_29_rodata_20;

struct Entry {
    signed char id;
    char pad[3];
    float a, b, c, d;
};

struct Table {
    unsigned char value;
    char pad[3];
    Entry* entries;
};

struct Object {
    char pad[0x26c];
    Entry entries[10];
    int count;
    char pad2[0x28];
    gfFileIOHandle handle;
};

extern "C" unsigned char fn_29_998(Object* self, int index) {
    Object* dst;
    unsigned char* buffer;
    Table* table;
    Entry* src;
    int count;
    unsigned int size;
    size = self->handle.getSize();

    if (self->handle.getReturnStatus() == 0x15) {
        buffer = 0;
    } else {
        buffer = (unsigned char*)self->handle.getBuffer();
        self->handle.release();
    }

    utRelocate reloc(buffer, size);
    table = (Table*)reloc.getPublicAddress(lbl_29_data_104) + index;
    float scale = lbl_29_rodata_20;
    src = table->entries;
    dst = self;
    count = 0;

    while (*(signed char*)src >= 0) {
        dst->entries[0].id = src->id;
        dst->entries[0].a = src->a;
        dst->entries[0].b = src->b;
        dst->entries[0].c = src->c;
        dst->entries[0].d = src->d;

        if (!((((unsigned char*)g_GameGlobal->getGlobalRecordMenuDatap())[0x28] >> 7) & 1)) {
            dst->entries[0].a *= scale;
            dst->entries[0].b *= scale;
            dst->entries[0].c *= scale;
            dst->entries[0].d *= scale;
        }

        dst = (Object*)((char*)dst + 0x14);
        ++count;
        src = (Entry*)((char*)src + 0x14);
    }

    self->count = count;
    gfHeapManager::free(buffer);
    return table->value;
}