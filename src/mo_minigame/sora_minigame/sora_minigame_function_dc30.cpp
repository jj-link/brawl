#pragma force_active on
namespace nw4r {
namespace g3d {
class G3dObj {
public:
    void Destroy();
};
} // namespace g3d
} // namespace nw4r

struct Holder {
    nw4r::g3d::G3dObj* obj;
};

struct Self {
    char pad[0x38];
    Holder* holder;
};

extern "C" void fn_20_DC30(Self* self) {
    Holder* h = self->holder;
    if (h->obj) {
        h->obj->Destroy();
    }
    if (self->holder) {
        delete self->holder;
        self->holder = 0;
    }
}
