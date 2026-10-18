#pragma force_active on
extern "C" {
extern char lbl_27_data_547E0[];
extern void* g_gfSceneRoot;

int strncmp(const char*, const char*, unsigned long);
void add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(void*, int, void*);
void fn_801AAFF0(void*, int);
void fn_801AB014(void*, int);
}

struct Owner {
    char pad[0x6D];
    unsigned char flags;
};

struct Resource {
    char pad[0x3C];
    int name;
};

struct Model {
    char pad[0xE8];
    Resource* resource;
};

extern "C" void fn_27_25F8B8(Owner* self, Model* model, int layer) {
    Resource* res = model->resource;
    char* base = lbl_27_data_547E0;

    if (res) {
        if (layer == 0) {
            int offset = res->name;

            if (strncmp(offset ? (char*)res + offset : 0, base + 0x40, 4) == 0) {
                add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                    g_gfSceneRoot, 3, model);
                self->flags |= 4;
            } else if (strncmp(offset ? (char*)res + offset : 0, base + 0x48, 4) == 0) {
                add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                    g_gfSceneRoot, 6, model);
                fn_801AAFF0(model, 255);
                fn_801AB014(model, 255);
            } else if (strncmp(offset ? (char*)res + offset : 0, base + 0x50, 5) == 0) {
                add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                    g_gfSceneRoot, 4, model);
                fn_801AAFF0(model, 255);
                fn_801AB014(model, 255);
            } else {
                add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                    g_gfSceneRoot, 0, model);
            }
        } else {
            add__11gfSceneRootFQ211gfSceneRoot9LayerTypePQ34nw4r3g3d6ScnMdl(
                g_gfSceneRoot, layer, model);
        }
    }
}
