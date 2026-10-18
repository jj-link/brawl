#pragma force_active on
struct Vec3f {
    float x;
    float y;
    float z;
};

class grGimmick {
public:
    Vec3f getRot();
    void updateCallback(unsigned long);
};

extern "C" void fn_40_32FD0(grGimmick* self) {
    grGimmick* obj = *(grGimmick**)((char*)self + 0xcc);
    if (obj != 0) {
        unsigned char flags = *(unsigned char*)((char*)self + 0xe0);
        if (flags & 1) {
            if (flags & 2) {
                char* target = *(char**)((char*)self + 0xd4);
                const Vec3f& rot = obj->getRot();
                *(float*)(target + 0x94) = rot.x;
                *(float*)(target + 0x98) = rot.y;
                *(float*)(target + 0x9c) = rot.z;
            }
        }
    }
    self->updateCallback(0);
}
