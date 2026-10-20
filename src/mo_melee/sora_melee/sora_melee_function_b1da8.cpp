#pragma force_active on
struct Pair {
    unsigned int first;
    unsigned int second;
};

struct Object {
    unsigned int unused;
    unsigned int camera;
};

extern "C" void* getInstance__16CameraControllerFv();
extern "C" void fn_8009CD94(void*, unsigned int, unsigned short, const Pair*, float);

extern "C" void fn_27_B1DA8(Object* self, unsigned int kind, const Pair* value, float amount) {
    Pair copy = *value;
    fn_8009CD94(getInstance__16CameraControllerFv(), self->camera,
                (unsigned short)kind, &copy, amount);
}
