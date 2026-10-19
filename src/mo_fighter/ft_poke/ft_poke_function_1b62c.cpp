#pragma force_active on
extern "C" unsigned char lbl_116_data_993C[];

namespace {
struct MemberStorage {
    void* vtable;
};
}

extern "C" void* fn_116_1B62C(MemberStorage* object) {
    object->vtable = lbl_116_data_993C;
    return object;
}
