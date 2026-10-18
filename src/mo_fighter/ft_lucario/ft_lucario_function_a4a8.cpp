#pragma force_active on
struct Holder { int pad[5]; float* array; };

extern "C" float fn_118_A4A8(Holder* object, int index) {
    return object->array[index];
}
