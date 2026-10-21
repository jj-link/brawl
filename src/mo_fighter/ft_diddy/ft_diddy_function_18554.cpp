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
void fn_115_18504(void*, void*);
void fn_115_186D4(DiddyTraversalIndex*, const DiddyTraversalIndex*);
void fn_115_185E4(void*, const DiddyTraversalIndex*, void*);
}

extern "C" void fn_115_18554(void* object, const DiddyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 8) {
        bool enabled = reinterpret_cast<DiddyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_18504(element, argument);
        }
    }
    DiddyTraversalIndex next;
    fn_115_186D4(&next, operation);
    fn_115_185E4(composite + 4, &next, argument);
}
