#pragma force_active on
struct gfCameraController_base { char pad[4]; };
class gfCameraController : public gfCameraController_base {
public:
    virtual void slot0();
};
struct Entry { int unk; gfCameraController* obj; };
struct Outer { Entry* entries; int count; };
extern "C" void fn_80099FCC(Outer* self) {
    for (int i = 0; i < self->count; i++) {
        self->entries[i].obj->slot0();
    }
}