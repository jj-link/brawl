struct LuigiCollisionObserverFlags;

extern "C" bool fn_99_106C8(const LuigiCollisionObserverFlags* object);

// Recover the complete observer from its secondary-interface receiver.
extern "C" bool fn_99_10CC4(const void* object) {
    return fn_99_106C8(reinterpret_cast<const LuigiCollisionObserverFlags*>(
        static_cast<const unsigned char*>(object) - 0x88));
}
