#pragma force_active on
struct Elem {
    char data[0x90];
};

struct Arr {
    char header[0xc];
    Elem elems[1];
};

extern "C" Elem* fn_50_6370(Arr* arr, int index) {
    return &arr->elems[index];
}
