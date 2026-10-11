// The layout also appears in the linked support constructed by fn_101_156C4.
struct NessLinkedSupport {
    void* vtable;
    unsigned char nullable;
    unsigned char padding[3];
    void* linkedObject;
    int index;
};

// These two soTeamImpl hooks have genuinely empty original implementations.
extern "C" void fn_101_1607C(NessLinkedSupport*) {}

extern "C" void fn_101_16080(NessLinkedSupport* object, int index) {
    object->index = index;
}

extern "C" int fn_101_16088(const NessLinkedSupport* object) {
    return object->index;
}

extern "C" void fn_101_16090(NessLinkedSupport*) {}

extern "C" void* fn_101_16094(const NessLinkedSupport* object) {
    return object->linkedObject;
}

extern "C" void fn_101_1609C(NessLinkedSupport* object, void* linkedObject) {
    object->linkedObject = linkedObject;
}

extern "C" void* fn_101_160A4(const NessLinkedSupport* object) {
    return object->linkedObject;
}
