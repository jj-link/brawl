#pragma force_active on
extern "C" {
extern unsigned char lbl_121_data_85F8[];
}

namespace {
struct ToonLink {
    void* vtable;
};
}

extern "C" void* fn_121_10F78(ToonLink* object) {
    object->vtable = lbl_121_data_85F8;
    return object;
}
