#pragma force_active on
struct Elem { char data[0x78]; };
struct Arr { char header[0xc]; Elem elems[1]; };

extern "C" Elem* fn_78_56C8(Arr* a, int i) {
    return &a->elems[i];
}
