#pragma force_active on
typedef unsigned char u8;

extern "C" void __dl__FPv(void*);
extern "C" void exit__6gfTaskFv(void*);
extern "C" void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
extern "C" void fn_800B8A0C(void*, int);
extern "C" void fn_800B8EDC(void*, void*);
extern "C" void fn_800FABEC(void*, void*);
extern "C" void fn_800FAEB8(void*, int);
extern "C" void release__14gfFileIOHandleFv(void*);
extern "C" void __dt__14gfFileIOHandleFv(void*, int);
extern "C" void removeExist__6utListFP10utListNode(void*, void*);
extern "C" void __destroy_arr(void*, void*, int, int);
extern "C" u8 lbl_2_data_4FB0[];
extern "C" u8 lbl_2_data_50C8[];
extern "C" u8 lbl_8045C4BC[];
extern "C" u8 lbl_8049E550[];
extern "C" u8* fn_2_3A314(u8*, int);

struct Obj5C {
    char pad[0x5C];
public:
    virtual void slot0(int);
};

extern "C" u8* fn_2_3A384(u8* s, int flag) {
    if (s) {
        *(void**)(s + 0x3C) = lbl_2_data_4FB0;
        fn_800B8EDC(*(void**)(s + 0x2E8), *(void**)(s + 0x2B8));

        if ((void*)(s + 0x2F4) != 0) {
            void* t = *(void**)(s + 0x2F4);
            if (t) exit__6gfTaskFv(t);
            *(void**)(s + 0x2F4) = 0;
        }
        if ((void*)(s + 0x2F0) != 0) {
            void* t = *(void**)(s + 0x2F0);
            if (t) exit__6gfTaskFv(t);
            *(void**)(s + 0x2F0) = 0;
        }
        if ((void*)(s + 0x2EC) != 0) {
            void* t = *(void**)(s + 0x2EC);
            if (t) Destroy__Q34nw4r3g3d6G3dObjFv(t);
            *(void**)(s + 0x2EC) = 0;
        }
        if ((void*)(s + 0x2E8) != 0) {
            fn_800B8A0C(*(void**)(s + 0x2E8), 1);
        }
        if ((void*)(s + 0x2E4) != 0) {
            Obj5C* t = *(Obj5C**)(s + 0x2E4);
            if (t) t->slot0(1);
        }
        if ((void*)(s + 0x2E0) != 0) {
            Obj5C* t = *(Obj5C**)(s + 0x2E0);
            if (t) t->slot0(1);
        }

        __destroy_arr(s + 0x2D4, fn_2_3A314, 4, 3);
        __destroy_arr(s + 0x2BC, fn_2_3A314, 4, 6);

        if ((void*)(s + 0x2B8) != 0) {
            Obj5C* t = *(Obj5C**)(s + 0x2B8);
            if (t) t->slot0(1);
        }
        if ((void*)(s + 0x2B4) != 0) {
            Obj5C* t = *(Obj5C**)(s + 0x2B4);
            if (t) t->slot0(1);
        }

        /* fileobj at 0x29C */
        if ((void*)(s + 0x29C) != 0) {
            *(void**)(s + 0x2A8) = lbl_2_data_50C8;
            fn_800FABEC(s + 0x29C, lbl_2_data_50C8);
            release__14gfFileIOHandleFv(s + 0x2AC);
            __dt__14gfFileIOHandleFv(s + 0x2AC, -1);
            if ((void*)(s + 0x29C) != 0) {
                if ((void*)(s + 0x29C) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x29C);
                    *(void**)(s + 0x2A4) = 0;
                    if ((void*)(s + 0x29C) != 0) {
                        if (*(void**)(s + 0x2A4) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x29C);
                            *(void**)(s + 0x2A4) = 0;
                        }
                    }
                }
            }
        }

        /* cplx at 0x268 */
        if ((void*)(s + 0x268) != 0) {
            *(void**)(s + 0x298) = lbl_8045C4BC;
            *(void**)(s + 0x278) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x27C, lbl_8045C4BC);
            *(void**)(s + 0x268) = 0;
            *(u8*)(s + 0x294) = 0;
            if ((void*)(s + 0x27C) != 0) {
                *(void**)(s + 0x288) = lbl_2_data_50C8;
                fn_800FABEC(s + 0x27C, lbl_2_data_50C8);
                release__14gfFileIOHandleFv(s + 0x28C);
                __dt__14gfFileIOHandleFv(s + 0x28C, -1);
                if ((void*)(s + 0x27C) != 0) {
                    if ((void*)(s + 0x27C) != 0) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x27C);
                        *(void**)(s + 0x284) = 0;
                        if ((void*)(s + 0x27C) != 0) {
                            if (*(void**)(s + 0x284) != 0) {
                                removeExist__6utListFP10utListNode(0, s + 0x27C);
                                *(void**)(s + 0x284) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x26C) != 0) {
                if ((void*)(s + 0x26C) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x26C);
                    *(void**)(s + 0x274) = 0;
                    if ((void*)(s + 0x26C) != 0) {
                        if (*(void**)(s + 0x274) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x26C);
                            *(void**)(s + 0x274) = 0;
                        }
                    }
                }
            }
        }

        /* cplx at 0x234 */
        if ((void*)(s + 0x234) != 0) {
            *(void**)(s + 0x264) = lbl_8045C4BC;
            *(void**)(s + 0x244) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x248, lbl_8045C4BC);
            *(void**)(s + 0x234) = 0;
            *(u8*)(s + 0x260) = 0;
            if ((void*)(s + 0x248) != 0) {
                *(void**)(s + 0x254) = lbl_2_data_50C8;
                fn_800FABEC(s + 0x248, lbl_2_data_50C8);
                release__14gfFileIOHandleFv(s + 0x258);
                __dt__14gfFileIOHandleFv(s + 0x258, -1);
                if ((void*)(s + 0x248) != 0) {
                    if ((void*)(s + 0x248) != 0) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x248);
                        *(void**)(s + 0x250) = 0;
                        if ((void*)(s + 0x248) != 0) {
                            if (*(void**)(s + 0x250) != 0) {
                                removeExist__6utListFP10utListNode(0, s + 0x248);
                                *(void**)(s + 0x250) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x238) != 0) {
                if ((void*)(s + 0x238) != 0) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x238);
                    *(void**)(s + 0x240) = 0;
                    if ((void*)(s + 0x238) != 0) {
                        if (*(void**)(s + 0x240) != 0) {
                            removeExist__6utListFP10utListNode(0, s + 0x238);
                            *(void**)(s + 0x240) = 0;
                        }
                    }
                }
            }
        }

        if (s) fn_800FAEB8(s, 0);
        if (flag > 0) __dl__FPv(s);
    }
    return s;
}