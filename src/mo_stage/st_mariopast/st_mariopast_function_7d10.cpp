#pragma force_active on
struct Vec3fLocal {
    float x;
    float y;
    float z;
};

extern "C" void setPos__9grGimmickFP5Vec3f(void*, void*);
extern "C" void fn_8003F03C(void*, float, float, float);
extern "C" void processAnim__6GroundFv(void*);

extern "C" {
void fn_48_7D10(void* self) {
    char* s = (char*)self;
    void* p = *(void**)(s + 0x168);
    if (p != 0) {
        setPos__9grGimmickFP5Vec3f(self, p);
        Vec3fLocal* v = (Vec3fLocal*)*(void**)(s + 0x168);
        fn_8003F03C(s + 0x170, v->x, v->y, v->z);
    }
    processAnim__6GroundFv(self);
}
}
