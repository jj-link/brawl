#pragma force_active on
struct Scene {
    unsigned char padding[0x2E0];
    unsigned int field_2E0;
};

extern "C" void fn_1_E760(Scene* scene) {
    scene->field_2E0 = 0;
}
