#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class grGimmick {
public:
    void setRot(Vec3f* rot);
};

void grGimmick::setRot(Vec3f* rot) {
    char* obj = *(char**)((char*)this + 0xd4);
    if (obj == 0) {
        return;
    }
    float x = rot->x;
    float y = rot->y;
    *(float*)(obj + 0x14) = x;
    float z = rot->z;
    *(float*)(obj + 0x18) = y;
    *(float*)(obj + 0x1c) = z;
}
