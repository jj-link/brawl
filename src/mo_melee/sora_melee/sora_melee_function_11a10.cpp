#pragma force_active on

extern "C" const float lbl_27_rodata_320;

struct Vec3 {
    float x, y, z;
};

struct Entry {
    char pad[0x1c8];
    Vec3 v1;
    char pad2[4];
    Vec3 v2;
};

struct Cont {
    Entry** arr;
    int count;
    char pad[0x5c];
    unsigned char flag;

    void setFlag(int a) {
        Vec3 tmp[2];
        flag = (unsigned char)a;
        if (a) {
            for (int i = 0; i < count; ++i) {
                Entry* e = arr[i];
                tmp[0].x = lbl_27_rodata_320;
                tmp[0].y = lbl_27_rodata_320;
                tmp[0].z = lbl_27_rodata_320;
                e->v2 = tmp[0];
            }
            for (int i = 0; i < count; ++i) {
                Entry* e = arr[i];
                tmp[1].x = lbl_27_rodata_320;
                tmp[1].y = lbl_27_rodata_320;
                tmp[1].z = lbl_27_rodata_320;
                e->v1 = tmp[1];
            }
        }
    }
};

struct Fallback {
    Entry** arr;
    int count;
    char pad[0x5c];
    unsigned char flag;

    void setFlag(int a) {
        Vec3 tmp[2];
        flag = (unsigned char)a;
        if (a) {
            for (int i = 0; i < count; ++i) {
                Entry* e = arr[i];
                tmp[1].x = lbl_27_rodata_320;
                tmp[1].y = lbl_27_rodata_320;
                tmp[1].z = lbl_27_rodata_320;
                e->v2 = tmp[1];
            }
            for (int i = 0; i < count; ++i) {
                Entry* e = arr[i];
                tmp[0].x = lbl_27_rodata_320;
                tmp[0].y = lbl_27_rodata_320;
                tmp[0].z = lbl_27_rodata_320;
                e->v1 = tmp[0];
            }
        }
    }
};

struct Self {
    char pad[0x28];
    Cont* c1;
    Fallback** c2;
};

extern "C" void fn_27_11A10(Self* self, int arg1) {
    if (self->c1)
        self->c1->setFlag(arg1);
    else if (self->c2)
        (*self->c2)->setFlag(arg1);
}
