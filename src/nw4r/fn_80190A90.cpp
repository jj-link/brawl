#pragma force_active on

namespace nw4r {
namespace g3d {
class ResMat {
public:
    void DCStore(bool flag);
};
} // namespace g3d
} // namespace nw4r

extern "C" void fn_801D7718(void*, void*);
extern "C" void fn_801D7774(void*, void*);

void nw4r::g3d::ResMat::DCStore(bool flag) {
    void* p = *(void**)this;
    void* q = *(void**)p;
    if (flag) {
        fn_801D7718(p, q);
    } else {
        fn_801D7774(p, q);
    }
}
