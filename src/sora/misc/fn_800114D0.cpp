#pragma force_active on
typedef unsigned char u8;

struct Vec3Local {
    float x;
    float y;
    float z;
};

extern "C" {
void getAABBox__10clCircle2DCFR10clAABBox2D(void* self, void* box);
}

extern "C" void fn_800114D0(u8* obj) {
    Vec3Local c;
    float t1;
    float t2 = *(float*)(obj + 0x48);
    c.x = t2;
    t1 = *(float*)(obj + 0x4C);
    c.y = t1;
    c.z = *(float*)(obj + 0x50);
    c.x = t2 + *(float*)(obj + 0x20);
    c.y = t1 + *(float*)(obj + 0x24);
    getAABBox__10clCircle2DCFR10clAABBox2D(&c, obj + 0x2C);
}
