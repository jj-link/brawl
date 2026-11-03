#pragma force_active on

#include <gf/gf_file_io_handle.h>
#include <gf/gf_task.h>
#include <ut/ut_list.h>

extern "C" {

void fn_800B8A0C(void*, int);
void fn_800B8EDC(void*, void*);
void fn_800FABEC(void*, void*);
void fn_800F8548(void*);
void fn_800F8680(void*);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void __destroy_arr(void*, void*, int, int);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void __dt__6gfTaskFv(void*, int);
void __dl__FPv(void*);
void removeExist__6utListFP10utListNode(void*, void*);

extern char lbl_8045BFC8[];
extern char lbl_8045B4B8[];
extern char lbl_8049E550[];

}

class gfPad5CProbe {
public:
    char pad[0x5C];
};

class gfVCallProbe : public gfPad5CProbe {
public:
    virtual void f(int);
};

extern "C" {

void* fn_800F86DC(void* self, int arg1) {
    char* s = (char*)self;

    if (self != 0) {
        unsigned int j;
        unsigned int i;
        char* p;
        char* q;

        *(void**)(s + 0x3C) = lbl_8045BFC8;
        p = s;
        i = 0;
        do {
            q = s;
            j = 0;
            do {
                fn_800B8EDC(*(void**)(p + 0x334), *(void**)(q + 0x274));
                j++;
                q += 0x18;
            } while (j < 8);
            i++;
            p += 4;
        } while (i < 3);

        if ((void*)(s + 0x378) != 0) {
            *(void**)(s + 0x384) = lbl_8045B4B8;
            fn_800FABEC(s + 0x378, lbl_8045B4B8);
            release__14gfFileIOHandleFv(s + 0x388);
            __dt__14gfFileIOHandleFv(s + 0x388, -1);
            if ((void*)(s + 0x378) != 0) {
                if ((void*)(s + 0x378) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x378);
                    *(void**)(s + 0x380) = 0;
                    if ((void*)(s + 0x378) != 0) {
                        if (*(void**)(s + 0x380) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x378);
                            *(void**)(s + 0x380) = 0;
                        }
                    }
                }
            }
        }

        if ((void*)(s + 0x360) != 0) {
            *(void**)(s + 0x36C) = lbl_8045B4B8;
            fn_800FABEC(s + 0x360, lbl_8045B4B8);
            release__14gfFileIOHandleFv(s + 0x370);
            __dt__14gfFileIOHandleFv(s + 0x370, -1);
            if ((void*)(s + 0x360) != 0) {
                if ((void*)(s + 0x360) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x360);
                    *(void**)(s + 0x368) = 0;
                    if ((void*)(s + 0x360) != 0) {
                        if (*(void**)(s + 0x368) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x360);
                            *(void**)(s + 0x368) = 0;
                        }
                    }
                }
            }
        }

        if ((void*)(s + 0x348) != 0) {
            *(void**)(s + 0x354) = lbl_8045B4B8;
            fn_800FABEC(s + 0x348, lbl_8045B4B8);
            release__14gfFileIOHandleFv(s + 0x358);
            __dt__14gfFileIOHandleFv(s + 0x358, -1);
            if ((void*)(s + 0x348) != 0) {
                if ((void*)(s + 0x348) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x348);
                    *(void**)(s + 0x350) = 0;
                    if ((void*)(s + 0x348) != 0) {
                        if (*(void**)(s + 0x350) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x348);
                            *(void**)(s + 0x350) = 0;
                        }
                    }
                }
            }
        }

        if ((void*)(s + 0x340) != 0) {
            fn_800B8A0C(*(void**)(s + 0x340), 1);
        }

        __destroy_arr(s + 0x334, fn_800F8680, 4, 3);
        __destroy_arr(s + 0x274, fn_800F8548, 0x18, 8);

        if ((void*)(s + 0x270) != 0) {
            void* o = *(void**)(s + 0x270);
            if (o != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(o);
            }
            *(void**)(s + 0x270) = 0;
        }

        if ((void*)(s + 0x26C) != 0) {
            void* o = *(void**)(s + 0x26C);
            if (o != 0) {
                ((gfVCallProbe*)o)->f(1);
            }
        }

        if ((void*)(s + 0x268) != 0) {
            void* o = *(void**)(s + 0x268);
            if (o != 0) {
                ((gfVCallProbe*)o)->f(1);
            }
        }

        if ((void*)(s + 0x264) != 0) {
            void* o = *(void**)(s + 0x264);
            if (o != 0) {
                Destroy__Q34nw4r3g3d6G3dObjFv(o);
            }
            *(void**)(s + 0x264) = 0;
        }

        if ((void*)(s + 0x24C) != 0) {
            *(void**)(s + 0x258) = lbl_8045B4B8;
            fn_800FABEC(s + 0x24C, lbl_8045B4B8);
            release__14gfFileIOHandleFv(s + 0x25C);
            __dt__14gfFileIOHandleFv(s + 0x25C, -1);
            if ((void*)(s + 0x24C) != 0) {
                if ((void*)(s + 0x24C) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x24C);
                    *(void**)(s + 0x254) = 0;
                    if ((void*)(s + 0x24C) != 0) {
                        if (*(void**)(s + 0x254) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x24C);
                            *(void**)(s + 0x254) = 0;
                        }
                    }
                }
            }
        }

        __dt__6gfTaskFv(s, 0);
        if (arg1 > 0) {
            __dl__FPv(s);
        }
    }

    return self;
}

}
