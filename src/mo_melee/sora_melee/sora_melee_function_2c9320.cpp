#include <gf/gf_heap_manager.h>
#include <types.h>
#pragma force_active on

struct Entry { float x, y; int* ptr; };
struct Container { char pad[0x708]; int kind; };
struct Out { int id; float x, y; };
struct Base { char pad[0x6f8]; Out entries[1][40]; };
struct Buffer { int a; int offset; };
struct Item { char pad[4]; short current, previous; };
struct Manager { char pad[0x14]; unsigned short counts[1000]; int indices[1]; };
struct Object {
    char pad[0x6a0]; Manager* manager;
    char pad2[0x34]; Item items[1];
};
extern "C" {
int fn_8004EFA0();
void* fn_80024A18(int, unsigned int);
void fn_8004F168(void*, void*);
void fn_8004EFA8(void*, void*);
Entry* fn_27_2D7808(Container*, int);
void fn_800ADD1C(Manager*, int, int);
void fn_800AEC70(Manager*);
extern void* g_GameGlobal;
extern unsigned char lbl_27_rodata_6078[];
extern const float lbl_27_rodata_61E8;

void fn_27_2C9320(Object* self) {
        Base* base;
            int kind;
    Buffer* buffer;
    buffer = (Buffer*)fn_80024A18(12, fn_8004EFA0());
    if (buffer) {
        fn_8004F168(g_GameGlobal, buffer);
        base = (Base*)((char*)buffer + buffer->offset);
        int i = 0;
        Container* container = (Container*)((char*)self + 0x4494);
        for (; i < *(int*)((char*)self + 0x4490); ++i, ++container) {
            kind = container->kind - 1;
            unsigned char index;
            if (kind < 0 || kind > 43) index = 35;
            else index = lbl_27_rodata_6078[kind];
            Out* out = base->entries[index];
            int j = 0;
            for (; j < 40; ++j) {
                Entry* entry = fn_27_2D7808(container, j);
                if (!entry) break;
                out->id = *entry->ptr;
                out->x = entry->x;
                out->y = entry->y;
                ++out;
            }
            for (; j < 40; ++j, ++out) {
                out->id = 0;
                out->y = lbl_27_rodata_61E8;
                out->x = lbl_27_rodata_61E8;
            }
        }
        fn_8004EFA8(g_GameGlobal, buffer);
        if (buffer) gfHeapManager::free(buffer);
    }
    Item* item = self->items;
    fn_800ADD1C(self->manager, 0, 1);
    int i = 0;
    int n;
    int offset = 0;
    for (; i < *(int*)((char*)self + 0x2ed8); ++i, offset += 4, ++item) {
        if (item->current != item->previous) {
            if (item->current > item->previous) {
                for (n = item->current - item->previous; n > 0; --n)
                    ++self->manager->counts[*(int*)(offset + (int)self->manager + 0x7e4)];
            } else {
                for (n = item->previous - item->current; n > 0; --n) {
                    if (self->manager->counts[*(int*)(offset + (int)self->manager + 0x7e4)] != 0)
                        --self->manager->counts[*(int*)(offset + (int)self->manager + 0x7e4)];
                }
            }
        }
    }
    fn_800AEC70(self->manager);
}
}
