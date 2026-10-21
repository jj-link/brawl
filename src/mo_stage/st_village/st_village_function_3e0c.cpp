#pragma force_active on

struct VillageData {
    void* buffer;
    unsigned char owned;
    unsigned char pad[3];
    void* obj8;
    void* objC;
    void* obj10;
    void* obj14;
    void* obj18;
    void* obj1C;
};

struct Ground {
    unsigned char pad[0x1C8];
    VillageData* data;
};

extern "C" {
void unloadData__6GroundFv(Ground*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void free__13gfHeapManagerFPv(void*);
void __dl__FPv(void*);
}

extern "C" void fn_70_3E0C(Ground* self) {
    unloadData__6GroundFv(self);
    VillageData* data = self->data;
    if (data) {
        if (data) {
            if (data->objC) Destroy__Q34nw4r3g3d6G3dObjFv(data->objC);
            if (data->obj8) Destroy__Q34nw4r3g3d6G3dObjFv(data->obj8);
            if (data->obj10) Destroy__Q34nw4r3g3d6G3dObjFv(data->obj10);
            if (data->obj14) Destroy__Q34nw4r3g3d6G3dObjFv(data->obj14);
            if (data->obj18) Destroy__Q34nw4r3g3d6G3dObjFv(data->obj18);
            if (data->obj1C) Destroy__Q34nw4r3g3d6G3dObjFv(data->obj1C);

            if (data->buffer && data->owned) {
                free__13gfHeapManagerFPv(data->buffer);
                data->buffer = 0;
            }

            data->objC = 0;
            data->obj8 = 0;
            data->obj10 = 0;
            data->obj14 = 0;
            data->obj18 = 0;
            data->obj1C = 0;
            __dl__FPv(data);
        }
        self->data = 0;
    }
}
