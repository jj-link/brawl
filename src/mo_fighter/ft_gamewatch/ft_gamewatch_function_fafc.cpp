#pragma force_active on
extern "C" {
void fn_107_FAAC(void*, void*);
void fn_107_FD64(short*, const short*);
void fn_107_FB8C(void*, const short*, void*);
}

namespace {
struct GameWatchTraversalIndex {
    short value;
};

struct GameWatchElementFlags {
    unsigned char enabled : 1;
    unsigned char remaining : 7;
};
}

extern "C" void fn_107_FAFC(void* object, const GameWatchTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;

    if (operation->value & 4) {
        bool enabled = reinterpret_cast<GameWatchElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_107_FAAC(element, argument);
        }
    }

    GameWatchTraversalIndex next;
    fn_107_FD64(&next.value, &operation->value);
    fn_107_FB8C(composite + 4, &next.value, argument);
}
