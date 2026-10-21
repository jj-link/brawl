#pragma force_active on
struct SnakeElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};

extern "C" {
void fn_122_1386C(void*, void*);
void fn_122_13B24(short*, const short*);
void fn_122_1394C(void*, const short*, void*);
}

extern "C" void fn_122_138BC(void* object, const short* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation[0] & 4) {
        bool enabled = reinterpret_cast<SnakeElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_122_1386C(element, argument);
        }
    }
    short next;
    fn_122_13B24(&next, operation);
    fn_122_1394C(composite + 4, &next, argument);
}
