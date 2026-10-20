#pragma force_active on
struct GameWatchTraversalIndex {
    short value;
};

struct GameWatchElementFlags {
    unsigned char enabled : 1;
};

extern "C" {
void fn_107_F9C4(void* element, void* argument);
void fn_107_FD64(GameWatchTraversalIndex* destination, const GameWatchTraversalIndex* source);
void fn_107_FAA4(void* object, const GameWatchTraversalIndex* operation, void* argument);

void fn_107_FA14(void* object, const GameWatchTraversalIndex* operation, void* argument) {
    unsigned char* composite = static_cast<unsigned char*>(object);
    unsigned char* element = composite + 0xC;
    if (operation->value & 2) {
        bool enabled = reinterpret_cast<GameWatchElementFlags*>(element + 5)->enabled;
        if (enabled == true && element[6] == 0) {
            fn_107_F9C4(element, argument);
        }
    }
    GameWatchTraversalIndex next;
    fn_107_FD64(&next, operation);
    fn_107_FAA4(composite + 4, &next, argument);
}
}
