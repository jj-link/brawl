#pragma force_active on
namespace {
struct FtDiddyTraversalIndex {
    short value;
};
struct FtDiddyElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" {
void fn_115_1828C(void*, void*);
void fn_115_186D4(FtDiddyTraversalIndex*, const FtDiddyTraversalIndex*);
int fn_115_1836C(void*, const FtDiddyTraversalIndex*, void*);
}

extern "C" void fn_115_18474(void* object, const FtDiddyTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<FtDiddyElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_115_1828C(element, argument);
        }
    }
    FtDiddyTraversalIndex next;
    fn_115_186D4(&next, operation);
    fn_115_1836C(composite + 4, &next, argument);
}
