#include <gf/gf_3d_scene.h>

#pragma force_active on

extern "C" {
extern void* fn_20_2FBC(void*);
extern void fn_20_4F6C(void*);
extern void fn_20_502C(void*);
extern void fn_20_8914(void*, void*);
extern void fn_8027CE3C(void*, int);
extern void fn_802ECBC0(void*, void*);
extern void fn_802F0668(void*);
extern void remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
    void*, nw4r::g3d::ScnMdl*);
extern void* __nw__FUlQ25Heaps8HeapType(unsigned long, int);
extern int lbl_20_data_438[];
}

struct Resource {
    char pad[8];
    void* data;
};

struct Item {
    char pad0[0x24];
    Resource* resource;
    char pad1[4];
    nw4r::g3d::ScnMdl* model;
    char pad2[0x20];
    int type;
    int variant;
};

class ItemCallback {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void callback(Item*);
};

struct Self {
    char pad0[0x244];
    ItemCallback* callbacks[5][7];
    char padCallbacks[0x4DC - 0x244 - 5 * 7 * 4];
    Item** items;
    int itemCount;
    int itemCapacity;
    char pad1[0x0C];
    Item** spareItems;
    int spareCount;
    int spareCapacity;
};

extern "C" void fn_20_8734(Self* self)
{
    int count = self->itemCount;
    int index;
    void* sceneRoot = g_gfSceneRoot;
    index = count - 1;
    int offset = index * 4;

    while (index >= 0) {
        Item* item = *(Item**)((char*)self->items + offset);
        if (item->model != 0) {
            remove__11gfSceneRootFPQ34nw4r3g3d6ScnMdl(
                sceneRoot, item->model);
        }

        if (index != 0) {
            fn_802ECBC0(
                self->items[0]->resource->data,
                (*(Item**)((char*)self->items + offset))->resource);
            fn_802F0668(
                (*(Item**)((char*)self->items + offset))->resource);

            Item* moved = *(Item**)((char*)self->items + offset);
            if (self->spareCount ==
                (self->spareCapacity & 0x3FFFFFFF)) {
                fn_8027CE3C(&self->spareItems, 4);
            }

            self->spareItems[self->spareCount++] = moved;
            self->itemCount--;
        }

        offset -= 4;
        index--;
    }

    fn_20_8914(self, self->items[0]);
    fn_20_4F6C(self->items[0]);

    Item* first = self->items[0];
    ItemCallback* callback = self->callbacks[first->type][first->variant];
    callback->callback(first);

    void* memory;
    void* item;
    int targetCount = lbl_20_data_438[self->items[0]->type];
    int i = 1;
    while (i < targetCount) {
        if (self->itemCount < 6) {
            memory = __nw__FUlQ25Heaps8HeapType(0x8C, 0x2A);
            item = memory;
            if (memory != 0) {
                item = fn_20_2FBC(memory);
            }

            fn_20_502C(item);

            if (self->itemCount ==
                (self->itemCapacity & 0x3FFFFFFF)) {
                fn_8027CE3C(&self->items, 4);
            }

            self->items[self->itemCount++] = (Item*)item;
        }
        i++;
    }
}
