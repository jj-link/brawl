#pragma force_active on
typedef unsigned char u8;

extern "C" {
extern u8 lbl_27_data_7B234[];

void exit__6gfTaskFv(void*);
void fn_8006C5DC();
void fn_27_2C35B0(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);

void* fn_27_2C3264(u8* object, int deleting) {
    if (object) {
        *reinterpret_cast<void**>(object + 0x3C) = lbl_27_data_7B234;

        void* task = *reinterpret_cast<void**>(object + 0x18C);
        if (task) {
            exit__6gfTaskFv(task);
            *reinterpret_cast<void**>(object + 0x18C) = 0;
        }

        fn_8006C5DC();
        fn_27_2C35B0(object);

        void* g3dObj = *reinterpret_cast<void**>(object + 0x50);
        if (g3dObj) {
            Destroy__Q34nw4r3g3d6G3dObjFv(g3dObj);
        }

        __dt__6gfTaskFv(object, 0);

        if (deleting > 0) {
            __dl__FPv(object);
        }
    }

    return object;
}
}
