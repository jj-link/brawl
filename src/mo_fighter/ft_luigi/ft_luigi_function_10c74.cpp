class soCollisionLog;
class soModuleAccesser;

extern "C" void fn_27_1DA968(void*, float, soCollisionLog*, soModuleAccesser*);

// Recover the complete object from the collision observer interface.
extern "C" void fn_99_10C74(void* object, float power, soCollisionLog* log,
                            soModuleAccesser* accesser) {
    fn_27_1DA968(static_cast<unsigned char*>(object) - 0x70, power, log, accesser);
}
