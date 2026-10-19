#pragma force_active on
struct V { float x, y, z; };
struct O { char pad[0x174]; V v; };
extern "C" void fn_67_478C(O* o, V* out) {
    out->x = o->v.x;
    out->y = o->v.y;
    out->z = o->v.z;
}
