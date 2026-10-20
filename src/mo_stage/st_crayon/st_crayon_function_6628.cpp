#pragma force_active on
struct Elem { char data[0x78]; };
struct Obj { char pad[0xc]; Elem elems[1]; };

extern "C" Elem* fn_56_6628(Obj* obj, int idx) {
    return &obj->elems[idx];
}
