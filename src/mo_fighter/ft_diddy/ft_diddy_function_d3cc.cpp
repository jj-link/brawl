#pragma force_active on

namespace {
struct DiddyTraversalIndex {
    short value;
};
struct DiddyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_115_D37C(void*, void*);
void fn_115_D71C(DiddyTraversalIndex*, const DiddyTraversalIndex*);
void fn_115_D45C(void*, const DiddyTraversalIndex*, void*);
}

extern "C" void fn_115_D3CC(void* object, const DiddyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<DiddyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_D37C(element, argument);
        }
    }
    DiddyTraversalIndex next;
    fn_115_D71C(&next, operation);
    fn_115_D45C(composite + 4, &next, argument);
}
