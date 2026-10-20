#pragma force_active on
typedef unsigned char u8;

struct Anim {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void set(float);
};

struct AnimGroup { u8 pad[0x14]; Anim* first; Anim* second; };
struct Resource { u8 pad[0x10]; void* model; AnimGroup* group; };
struct Data {
    void* archive;
    u8 pad[0xc];
    Resource* resources[35];
    void* models[8];
};
struct Self { u8 pad[0x40]; Data* data; void setup(void*); };

extern "C" {
extern const u8 lbl_2_rodata_FC8[];
void fn_2_3157C(void*, const void*, int, void*);
void fn_1_7E90(void*, void*, int);
void* getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(int);
void* Construct__Q34nw4r3g3d6ScnMdlFPviiPv(void*, int, int, void*);
}

inline void Self::setup(void* arg) {
    void* heap;
    const u8* base = lbl_2_rodata_FC8;
    Self* self = this;
    fn_2_3157C(self, base + 0x378, 0x17, arg);
    fn_1_7E90(self->data->archive, self->data->resources, 0x23);
    heap = getMEMAllocator__13gfHeapManagerFQ25Heaps8HeapType(0x2a);
    self->data->models[0] = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, 1, self->data->resources[0]->model);
    int i;
    const u8* entry = base + 0x318;
    for (i = 0; i < 4; ++i, entry += 0x10) {
        void* mdl = Construct__Q34nw4r3g3d6ScnMdlFPviiPv(heap, 0, entry[4] + entry[5] + 1, self->data->resources[entry[6]]->model);
        self->data->models[entry[7]] = mdl;
    }
    self->data->resources[0]->group->first->set(*(const float*)(base + 0x430));
    self->data->resources[1]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[6]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[7]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[8]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[22]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[23]->group->second->set(*(const float*)(base + 0x430));
    self->data->resources[25]->group->second->set(*(const float*)(base + 0x430));
}

extern "C" void fn_2_31374(Self* self, void* arg) { self->setup(arg); }
