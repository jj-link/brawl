#pragma force_active on
class Class_3FE0 {
public:
    virtual void fn_27_4742C();
    virtual int fn_27_4746C(int);
};
struct Object {
    int id;
    short start;
    short count;
    char pad[0x88];
    float x, y, z;
    char pad2[0x14];
    unsigned char flag;
};
extern "C" int fn_27_36028(void*, int, int);
extern "C" unsigned int fn_27_467C8(int, int, int, float);
extern "C" void fn_27_362E4(void*, int);
extern "C" void fn_27_37880(void*, int, float, float);
extern "C" void fn_27_379D4(void*, int, float);
extern "C" int fn_27_46E78(Object* self, void* arg1, Class_3FE0* arg2, int arg3, float x, float y, float z) {
    int entry;
    self->x = x;
    self->y = y;
    self->z = z;
    if (self->id != -1) {
        int result = 0;
        for (int i = 0; i < self->count; ++i) {
            entry = arg2->fn_27_4746C(self->start + i);
            if (fn_27_467C8(entry, arg3, fn_27_36028(arg1, i, self->id), self->y) == 1U) {
                result = 1;
            }
        }
        fn_27_362E4(arg1, self->id);
        fn_27_37880(arg1, self->id, self->x, z);
        if (self->flag == 1) {
            fn_27_379D4(arg1, self->id, z);
        }
        return result;
    }
    return 0;
}