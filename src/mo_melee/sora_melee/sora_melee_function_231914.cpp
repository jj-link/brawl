#pragma force_active on

struct Vec3 {
    float x, y, z;

    void set(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }

    void setYX(float b, float a, float c) {
        x = a;
        y = b;
        z = c;
    }
};

struct Stage {
    unsigned char pad0[0x1DC];
    int index;
    unsigned char pad1[4];
    unsigned char ready, flagA, flagB, flags;
    void* ground;
    void* object;
    void* buffer0;
    void* buffer1;
    void* buffer2;
    void* buffer3;
    void* buffer4;
    void* buffer5;
    unsigned char pad2[0x64];
    Vec3 points[4];
    unsigned char pad3[0x18];
    int width, height;
};

struct EditData {
    int active;
    unsigned char pad0[0x12];
    unsigned char kind;
    unsigned char pad1[0x29];
    float coords[8];
    unsigned char pad2[0x20];
    unsigned char data[1];
};

struct GameGlobal {
    unsigned char pad[0x40];
    EditData* edit;
};

extern "C" {
extern GameGlobal* g_GameGlobal;
extern unsigned char lbl_27_data_4B190[4][2];
extern const float lbl_27_rodata_3804;

void* memset(void*, int, unsigned long);
void free__13gfHeapManagerFPv(void*);
void fn_27_22F5C8(Stage*, unsigned char, void*, int);
void fn_27_22E9C0(Stage*);
int fn_27_2249E0(Stage*);
void fn_27_23171C(Stage*);
void* getGround__5StageFi(Stage*, int);
void startEntityAutoLoop__8grMadeinFv(void*);
void fn_8011097C(void*);
}

extern "C" void fn_27_231914(Stage* self) {
    EditData* data = g_GameGlobal->edit;

    if (data->active != 0) {
        memset(&self->points[0], 0, 0x1A28);

        if (self->buffer0) {
            free__13gfHeapManagerFPv(self->buffer0);
            self->buffer0 = 0;
            self->flagA = 0;
        }

        if (self->buffer1) {
            free__13gfHeapManagerFPv(self->buffer1);
            self->buffer1 = 0;
            self->flagB = 0;
        }

        if (self->buffer2) {
            free__13gfHeapManagerFPv(self->buffer2);
            self->buffer2 = 0;
        }

        if (self->buffer3) {
            free__13gfHeapManagerFPv(self->buffer3);
            self->buffer3 = 0;
        }

        if (self->buffer4) {
            free__13gfHeapManagerFPv(self->buffer4);
            self->buffer4 = 0;
        }

        if (self->buffer5) {
            free__13gfHeapManagerFPv(self->buffer5);
            self->buffer5 = 0;
        }

        self->width = lbl_27_data_4B190[self->index][0];
        self->height = lbl_27_data_4B190[self->index][1];

        fn_27_22F5C8(self, data->kind, data->data, self->index * 2);
        fn_27_22E9C0(self);

        self->points[0].set(
            data->coords[0], data->coords[1], lbl_27_rodata_3804);

        {
            float y = data->coords[3];
            float x = data->coords[2];
            self->points[1].setYX(y, x, lbl_27_rodata_3804);
        }

        {
            float y = data->coords[5];
            float x = data->coords[4];
            self->points[2].setYX(y, x, lbl_27_rodata_3804);
        }

        {
            float y = data->coords[7];
            float x = data->coords[6];
            self->points[3].setYX(y, x, lbl_27_rodata_3804);
        }

        int result = fn_27_2249E0(self);

        if (!(self->flags & 1)) {
            startEntityAutoLoop__8grMadeinFv(
                getGround__5StageFi(self, 0));
            self->flags |= 1;
        }

        if (result && self->ground && !(self->flags & 2)) {
            startEntityAutoLoop__8grMadeinFv(self->ground);

            if (self->object) {
                fn_8011097C(self->object);
            }

            self->flags |= 2;
        }

        fn_27_23171C(self);
        self->ready = 1;
    }
}
