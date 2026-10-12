class soCollisionLog;
class soModuleAccesser;

extern "C" void fn_27_1DB0E8(void*, float, soCollisionLog*, soModuleAccesser*);

extern "C" void fn_99_10C84(void* object, float power,
                           soCollisionLog* collisionLog, soModuleAccesser* accesser) {
    fn_27_1DB0E8(static_cast<unsigned char*>(object) - 0x7C,
                 power, collisionLog, accesser);
}
