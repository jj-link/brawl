#pragma force_active on

struct Node {
    char pad[0x38];
    float x;
    float y;
    float z;
};

struct Model {
    char pad[0xe8];
    void* resource;
};

struct Self {
    char pad0[4];
    unsigned char m_flag;
    int m_index;
    Node* m_node;
    int m_unk10;
    float m_floats[8];
    char m_name[32];
};

extern "C" {
    extern char lbl_40_data_1418[];
    extern char lbl_40_data_1468[];
    extern const float lbl_40_rodata_278;
    extern void* lbl_27_bss_5668;
    void* __dynamic_cast(void*, long, const void*, const void*, short);
    Node* GetResNode__Q34nw4r3g3d6ResMdlCFPCc(const void*, const char*);

    int fn_40_19E3C(Self* self, Model* model) {
        self->m_flag = 0;
        self->m_floats[6] = lbl_40_rodata_278;
        self->m_floats[7] = lbl_40_rodata_278;
        self->m_floats[0] = lbl_40_rodata_278;
        self->m_floats[1] = lbl_40_rodata_278;
        self->m_floats[2] = lbl_40_rodata_278;
        self->m_floats[3] = lbl_40_rodata_278;
        self->m_floats[4] = lbl_40_rodata_278;
        self->m_floats[5] = lbl_40_rodata_278;

        void* resource = model->resource;
        if (resource == 0) {
            return 0;
        }
        Node* node = GetResNode__Q34nw4r3g3d6ResMdlCFPCc(&resource, self->m_name);
        if (node == 0) {
            return 0;
        }
        self->m_flag = 1;
        self->m_node = node;
        self->m_floats[0] = node->x;
        self->m_floats[1] = node->y;
        self->m_floats[2] = node->z;

        void* obj = __dynamic_cast(lbl_27_bss_5668, 0x3c, lbl_40_data_1418, lbl_40_data_1468, 0);
        char* table = *(char**)((char*)obj + 0x554);
        if (table != 0) {
            self->m_floats[6] = *(float*)(table + self->m_index * 4);
            char* p = table + self->m_index * 4;
            self->m_floats[7] = *(float*)(p + 0x10);
            self->m_floats[3] = *(float*)(p + 0x20);
            self->m_floats[4] = *(float*)(p + 0x30);
            self->m_floats[5] = *(float*)(p + 0x40);
        }
        return 1;
    }
}
