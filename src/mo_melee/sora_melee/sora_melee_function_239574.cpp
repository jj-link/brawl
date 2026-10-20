#pragma force_active on
class stMelee {
public:
    void zoomOutCamera(float, float);
};

struct ZoomData {
    char pad[0x10];
    float a;
    float b;
};

void stMelee::zoomOutCamera(float f1, float f2) {
    ZoomData* p = *(ZoomData**)((char*)this + 0x78);
    if (p == 0) {
        return;
    }
    *(float*)((char*)this + 0x1d0) = p->a;
    *(float*)((char*)this + 0x1d4) = p->b;
    p->a = f1;
    p->b = f2;
}
