#pragma force_active on

struct Object {
    void* vtable;
    unsigned char pad[0xD8];
    float x, y, z;
    unsigned int flags;
    int value;
    void* data;
};

extern "C" {
void* fn_80204E5C(void*, unsigned int);
void fn_801AAB2C(Object*, void*);
extern char lbl_80466580[];
extern const float lbl_805A33F8;

Object* fn_801B5AD0(void* owner, unsigned int* output, int value,
                    int flag1, int flag2, unsigned int extra) {
    unsigned int aligned = (extra + 3) & ~3U;
    unsigned int size = (aligned + 0xF7) & ~3U;
    Object* result = 0;

    if (output) {
        *output = size;
    }

    if (owner) {
        Object* object = (Object*)fn_80204E5C(owner, size);
        if (object) {
            void* data;
            if (aligned) {
                data = (char*)object + 0xF4;
            } else {
                data = 0;
            }

            result = object;
            if (object) {
                fn_801AAB2C(object, owner);
                object->x = lbl_805A33F8;
                object->y = lbl_805A33F8;
                object->z = lbl_805A33F8;
                object->vtable = lbl_80466580;
                object->flags = 0;
                object->value = value;
                object->data = data;

                if (flag1) {
                    object->flags |= 1;
                }
                if (flag2) {
                    object->flags |= 2;
                }

                result = object;
            }
        }
    }

    return result;
}
}
