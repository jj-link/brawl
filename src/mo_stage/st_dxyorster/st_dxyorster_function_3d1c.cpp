#pragma force_active on
struct Elem { char pad[0xa0]; };
struct Arr { char hdr[0xc]; Elem e[1]; };
extern "C" void* fn_76_3D1C(Arr* a, int i) {
    return &a->e[i];
}
