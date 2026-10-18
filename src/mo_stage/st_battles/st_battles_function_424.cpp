#pragma force_active on
struct Camera {
    unsigned char kind;
    void *controller;
    float unk18c;
};

extern "C" {
void fn_42_424(void *obj, unsigned char kind, void *controller, float value)
{
    Camera *camera = (Camera *)((char *)obj + 0x184);
    camera->kind = kind;
    camera->controller = controller;
    camera->unk18c = value;
}
}