#pragma force_active on
namespace {
struct TraversalIndex {
    short value;
};

struct ElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_107_FC7C(void*, void*);
void fn_107_FD64(TraversalIndex*, const TraversalIndex*);
void fn_107_FD5C(void*, const TraversalIndex*, void*);
}

extern "C" void fn_107_FCCC(void* object, const TraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<ElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_107_FC7C(element, argument);
        }
    }

    TraversalIndex next;
    fn_107_FD64(&next, operation);
    fn_107_FD5C(composite + 4, &next, argument);
}
