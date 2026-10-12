struct LuigiCollisionObserverFlags;

extern "C" void fn_99_106DC(LuigiCollisionObserverFlags* object, bool enabled);

// Recover the complete observer from its secondary-interface receiver.
extern "C" void fn_99_10CBC(void* object, bool enabled) {
    fn_99_106DC(reinterpret_cast<LuigiCollisionObserverFlags*>(
                    static_cast<unsigned char*>(object) - 0x88),
                enabled);
}
