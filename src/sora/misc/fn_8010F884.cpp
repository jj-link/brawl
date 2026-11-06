#include <types.h>
#include <nw4r/g3d/g3d_obj.h>
#include <gf/gf_3d_scene.h>
#pragma force_active on
struct Class_804873F0_base { char pad[0x10]; };
class Class_804873F0 : public Class_804873F0_base {
public:
    virtual void fn_802CE61C(int);
};
struct Object {
    char pad[4];
    nw4r::g3d::G3dObj* obj;
    char pad2[8];
    Class_804873F0* ptr;
};
inline void destroy(Class_804873F0* p) { if (p) p->fn_802CE61C(1); }
extern "C" void fn_8000D7B8(void*);
extern "C" void fn_8010F884(Object* self) {
    if (self->ptr) {
        destroy(self->ptr);
        self->ptr = 0;
    }
    if (self->obj) {
        self->obj->Destroy();
        self->obj = 0;
    }
    fn_8000D7B8(g_gfSceneRoot);
}