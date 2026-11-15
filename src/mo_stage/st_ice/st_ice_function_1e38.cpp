#pragma force_active on

extern "C" {
void fn_27_233C70(void*, void*);
unsigned char* getInstance__16CameraControllerFv();
float fn_8016232C(float);
float fn_801622C4(float);
void fn_8009CEA8(void*, void*);
int setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(void*, float*, float*, int, int, int);
extern void* g_aiMgr;
extern const float lbl_62_rodata_0[];
}

struct Rect2 {
    int a;
    int b;
    int c;
    float d;
};

struct Vec3 {
    float x, y, z;
};

struct Zone {
    float v1[2];
    float v2[2];
};

extern "C" void fn_62_1E38(unsigned char* self) {
    const float* rodata = lbl_62_rodata_0;

    if (*(int*)(self + 0x4D4) && *(void**)(self + 0x4D8) &&
        *(int*)(self + 0x9C)) {
        Vec3 pos;
        float z, y, x, z2, y2, x2, z3, y3, x3;
        x = *(float*)(self + 0x2AC);
        z = *(float*)(self + 0x2CC);
        y = *(float*)(self + 0x2BC);
        float prev = *(float*)(self + 0x4DC);
        z2 = *(float*)(self + 0x38C);
        y2 = *(float*)(self + 0x37C);
        x2 = *(float*)(self + 0x36C);
        z3 = *(float*)(self + 0x3EC);
        y3 = *(float*)(self + 0x3DC);
        x3 = *(float*)(self + 0x3CC);
        pos.x = x; pos.y = y; pos.z = z;
        Vec3 pos2 = {x2, y2, z2};
        Vec3 pos3 = {x3, y3, z3};

        *(float*)(*(unsigned char**)(self + 0x4D8) + 0x28) = pos.y;
        *(float*)(*(unsigned char**)(self + 0x4D8) + 0x30) =
            rodata[7] * (pos.x - prev);

        float t4 = *(float*)(self + 0x42C) - *(float*)(self + 0x420);
        unsigned char* data = *(unsigned char**)(self + 0x4D8);
        *(float*)(data + 0x20) =
            rodata[4] + t4;

        float t3 = pos.y - *(float*)(self + 0x430);
        float t2 = rodata[17] + t3;
        *(float*)(data + 0x24) = t2;
        *(float*)(data + 0x18) = rodata[0];
        *(float*)(data + 0x1C) =
            pos.y - rodata[16] * t2;

        fn_27_233C70(*(void**)(self + 0x4D4), *(void**)(self + 0x4D8));

        *(float*)(self + 0x4DC) = pos.x;

        Zone zone;
        zone.v1[0] = *(float*)(self + 0x420);
        zone.v1[1] = pos.y;
        zone.v2[0] = *(float*)(self + 0x42C);

        float lim = *(float*)(self + 0x430);
        zone.v2[1] = lim;
        if (pos.y < lim) {
            zone.v1[1] = lim;
        }

        int r = setDangerZone__5aiMgrFP5Vec2fP5Vec2fibb(
            g_aiMgr, zone.v1, zone.v2, *(int*)(self + 0x4F4), 0, 0);
        *(int*)(self + 0x4F4) = r;

        float var = rodata[0];
        unsigned char* cam = getInstance__16CameraControllerFv();
        Rect2 rc = *(Rect2*)(cam + 0x148);

        if (rc.d < pos.y) {
            rc.d = pos.y;
            unsigned char* p = getInstance__16CameraControllerFv() + 0x84;
            if (p) {
                float s = fn_8016232C(rodata[6]);
                float c = fn_801622C4(rodata[6]);
                rc.d -= rodata[16] * (*(float*)(p + 0x10) * (c / s));
            }
            var = pos.y - rc.d;
        }

        fn_8009CEA8(getInstance__16CameraControllerFv(), &rc);
        *(float*)(getInstance__16CameraControllerFv() + 0x18C) = var;
    }
}
