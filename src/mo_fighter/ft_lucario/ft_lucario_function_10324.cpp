#pragma force_active on
extern "C" unsigned char lbl_118_data_65D8[];

namespace {
struct Component {
    void* vtable;
};
}

extern "C" Component* fn_118_10324(Component* object) {
    object->vtable = lbl_118_data_65D8;
    return object;
}