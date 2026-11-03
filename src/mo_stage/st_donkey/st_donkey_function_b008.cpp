#pragma force_active on

extern "C" {
extern const float lbl_50_rodata_198[];
extern void* g_ftManager;
void* memset(void*, int, unsigned long);
int fn_27_10B224(void*, void*, void*, void*, int, float, float, float, float);
}

struct Object {
    char pad0[0x150];
    unsigned char state;
    char pad1[0x13];
    float* position;
    unsigned char* status;
};

extern "C" void fn_50_B008(Object* self) {
    const float* rd = lbl_50_rodata_198;
    switch (self->state) {
    case 8:
        {
            char result[0x24];
            float bounds[4];
            memset(result, 0, 0x24);
            float* p = self->position;
            float cy = rd[0] + p[1];
            float x = p[0];
            float width = rd[1];
            float half = rd[2] * width;
            bounds[0] = x - half;
            bounds[1] = x + half;
            bounds[2] = cy + half;
            bounds[3] = cy - half;
            if (fn_27_10B224(g_ftManager, bounds, result, 0, 1,
                             bounds[2], bounds[1], bounds[0], cy) > 0) {
                unsigned char* status = self->status;
                if (*status == 3)
                    *status = 4;
            }
        }
        break;
    }
}
