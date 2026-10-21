#pragma force_active on
struct ToonlinkTraversalIndex {
    short value;
};
struct ToonlinkElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_121_E690(void*, void*);
void fn_121_E948(ToonlinkTraversalIndex*, const ToonlinkTraversalIndex*);
void fn_121_E770(void*, const ToonlinkTraversalIndex*, void*);
}

extern "C" void fn_121_E6E0(void* object, const ToonlinkTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 4) {
        bool enabled = reinterpret_cast<ToonlinkElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_121_E690(element, argument);
        }
    }
    ToonlinkTraversalIndex next;
    fn_121_E948(&next, operation);
    fn_121_E770(composite + 4, &next, argument);
}
