#include <gf/gf_file_io_handle.h>
#include <gf/gf_task.h>
#include <ut/ut_list.h>
#pragma force_active on

extern "C" {
void fn_8000E590(void*, int, unsigned);
void fn_800B8EDC(void*, void*);
void fn_800B8A0C(void*, int);
void __destroy_arr(void*, void (*)(void*, int), int, int);
void Destroy__Q34nw4r3g3d6G3dObjFv(void*);
void exit__6gfTaskFv(void*);
void fn_800FABEC(void*, void*);
void release__14gfFileIOHandleFv(void*);
void __dt__14gfFileIOHandleFv(void*, int);
void removeExist__6utListFP10utListNode(void*, void*);
void fn_800FAEB8(void*, int);
void __dl__FPv(void*);
void fn_40_438BC(void*, int);
void fn_40_436B8(void*, int);
extern char lbl_40_data_181C0[];
extern char lbl_40_data_182F8[];
extern char lbl_8045C4BC[];
extern char lbl_8049E550[];
extern char* g_gfSceneRoot;
}

class Obj5C { char pad[0x5C]; public: virtual void f(int); };

extern "C" void* fn_40_43A04(void* self, int arg) {
    char* s = (char*)self;
    unsigned int i;
    char* p;
    if (self) {
        *(void**)(s + 0x3C) = lbl_40_data_181C0;
        fn_8000E590(g_gfSceneRoot, 8, 0);
        p = s;
        i = 0;
        do {
            fn_800B8EDC(*(void**)(s + 0x1888), *(void**)(p + 0x1580));
            i++;
            p += 0xC0;
        } while (i < 4U);
        if ((void*)(s + 0x1890)) {
            void* t = *(void**)(s + 0x1890);
            if (t) exit__6gfTaskFv(t);
            *(void**)(s + 0x1890) = 0;
        }
        if ((void*)(s + 0x188C)) {
            void* t = *(void**)(s + 0x188C);
            if (t) exit__6gfTaskFv(t);
            *(void**)(s + 0x188C) = 0;
        }
        if ((void*)(s + 0x1888)) {
            fn_800B8A0C(*(void**)(s + 0x1888), 1);
        }
        __destroy_arr(s + 0x1580, fn_40_438BC, 0xC0, 4);
        if ((void*)(s + 0x157C)) {
            void* o = *(void**)(s + 0x157C);
            if (o) Destroy__Q34nw4r3g3d6G3dObjFv(o);
            *(void**)(s + 0x157C) = 0;
        }
        if ((void*)(s + 0x1578)) {
            void* o = *(void**)(s + 0x1578);
            if (o) Destroy__Q34nw4r3g3d6G3dObjFv(o);
            *(void**)(s + 0x1578) = 0;
        }
        if ((void*)(s + 0x1574)) {
            void* o = *(void**)(s + 0x1574);
            if (o) ((Obj5C*)o)->f(1);
        }
        if ((void*)(s + 0x1570)) {
            void* o = *(void**)(s + 0x1570);
            if (o) ((Obj5C*)o)->f(1);
        }
        if ((void*)(s + 0x156C)) {
            void* o = *(void**)(s + 0x156C);
            if (o) ((Obj5C*)o)->f(1);
        }
        if ((void*)(s + 0x1568)) {
            void* o = *(void**)(s + 0x1568);
            if (o) ((Obj5C*)o)->f(1);
        }
        if ((void*)(s + 0x1564)) {
            void* o = *(void**)(s + 0x1564);
            if (o) ((Obj5C*)o)->f(1);
        }
        if ((void*)(s + 0x1560)) {
            void* o = *(void**)(s + 0x1560);
            if (o) Destroy__Q34nw4r3g3d6G3dObjFv(o);
            *(void**)(s + 0x1560) = 0;
        }
        if ((void*)(s + 0x1548)) {
            *(void**)(s + 0x1554) = lbl_40_data_182F8;
            fn_800FABEC(s + 0x1548, lbl_40_data_182F8);
            release__14gfFileIOHandleFv(s + 0x1558);
            __dt__14gfFileIOHandleFv(s + 0x1558, -1);
            if ((void*)(s + 0x1548)) {
                if ((void*)(s + 0x1548)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x1548);
                    *(void**)(s + 0x1550) = 0;
                    if ((void*)(s + 0x1548)) {
                        if (*(void**)(s + 0x1550)) {
                            removeExist__6utListFP10utListNode(0, s + 0x1548);
                            *(void**)(s + 0x1550) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x1530)) {
            *(void**)(s + 0x153C) = lbl_40_data_182F8;
            fn_800FABEC(s + 0x1530, lbl_40_data_182F8);
            release__14gfFileIOHandleFv(s + 0x1540);
            __dt__14gfFileIOHandleFv(s + 0x1540, -1);
            if ((void*)(s + 0x1530)) {
                if ((void*)(s + 0x1530)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x1530);
                    *(void**)(s + 0x1538) = 0;
                    if ((void*)(s + 0x1530)) {
                        if (*(void**)(s + 0x1538)) {
                            removeExist__6utListFP10utListNode(0, s + 0x1530);
                            *(void**)(s + 0x1538) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x1518)) {
            *(void**)(s + 0x1524) = lbl_40_data_182F8;
            fn_800FABEC(s + 0x1518, lbl_40_data_182F8);
            release__14gfFileIOHandleFv(s + 0x1528);
            __dt__14gfFileIOHandleFv(s + 0x1528, -1);
            if ((void*)(s + 0x1518)) {
                if ((void*)(s + 0x1518)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x1518);
                    *(void**)(s + 0x1520) = 0;
                    if ((void*)(s + 0x1518)) {
                        if (*(void**)(s + 0x1520)) {
                            removeExist__6utListFP10utListNode(0, s + 0x1518);
                            *(void**)(s + 0x1520) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x14E4)) {
            *(void**)(s + 0x1514) = lbl_8045C4BC;
            *(void**)(s + 0x14F4) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x14F8, lbl_8045C4BC);
            *(void**)(s + 0x14E4) = 0;
            *(char*)(s + 0x1510) = 0;
            if ((void*)(s + 0x14F8)) {
                *(void**)(s + 0x1504) = lbl_40_data_182F8;
                fn_800FABEC(s + 0x14F8, lbl_40_data_182F8);
                release__14gfFileIOHandleFv(s + 0x1508);
                __dt__14gfFileIOHandleFv(s + 0x1508, -1);
                if ((void*)(s + 0x14F8)) {
                    if ((void*)(s + 0x14F8)) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x14F8);
                        *(void**)(s + 0x1500) = 0;
                        if ((void*)(s + 0x14F8)) {
                            if (*(void**)(s + 0x1500)) {
                                removeExist__6utListFP10utListNode(0, s + 0x14F8);
                                *(void**)(s + 0x1500) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x14E8)) {
                if ((void*)(s + 0x14E8)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x14E8);
                    *(void**)(s + 0x14F0) = 0;
                    if ((void*)(s + 0x14E8)) {
                        if (*(void**)(s + 0x14F0)) {
                            removeExist__6utListFP10utListNode(0, s + 0x14E8);
                            *(void**)(s + 0x14F0) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x14B0)) {
            *(void**)(s + 0x14E0) = lbl_8045C4BC;
            *(void**)(s + 0x14C0) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x14C4, lbl_8045C4BC);
            *(void**)(s + 0x14B0) = 0;
            *(char*)(s + 0x14DC) = 0;
            if ((void*)(s + 0x14C4)) {
                *(void**)(s + 0x14D0) = lbl_40_data_182F8;
                fn_800FABEC(s + 0x14C4, lbl_40_data_182F8);
                release__14gfFileIOHandleFv(s + 0x14D4);
                __dt__14gfFileIOHandleFv(s + 0x14D4, -1);
                if ((void*)(s + 0x14C4)) {
                    if ((void*)(s + 0x14C4)) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x14C4);
                        *(void**)(s + 0x14CC) = 0;
                        if ((void*)(s + 0x14C4)) {
                            if (*(void**)(s + 0x14CC)) {
                                removeExist__6utListFP10utListNode(0, s + 0x14C4);
                                *(void**)(s + 0x14CC) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x14B4)) {
                if ((void*)(s + 0x14B4)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x14B4);
                    *(void**)(s + 0x14BC) = 0;
                    if ((void*)(s + 0x14B4)) {
                        if (*(void**)(s + 0x14BC)) {
                            removeExist__6utListFP10utListNode(0, s + 0x14B4);
                            *(void**)(s + 0x14BC) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x147C)) {
            *(void**)(s + 0x14AC) = lbl_8045C4BC;
            *(void**)(s + 0x148C) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x1490, lbl_8045C4BC);
            *(void**)(s + 0x147C) = 0;
            *(char*)(s + 0x14A8) = 0;
            if ((void*)(s + 0x1490)) {
                *(void**)(s + 0x149C) = lbl_40_data_182F8;
                fn_800FABEC(s + 0x1490, lbl_40_data_182F8);
                release__14gfFileIOHandleFv(s + 0x14A0);
                __dt__14gfFileIOHandleFv(s + 0x14A0, -1);
                if ((void*)(s + 0x1490)) {
                    if ((void*)(s + 0x1490)) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x1490);
                        *(void**)(s + 0x1498) = 0;
                        if ((void*)(s + 0x1490)) {
                            if (*(void**)(s + 0x1498)) {
                                removeExist__6utListFP10utListNode(0, s + 0x1490);
                                *(void**)(s + 0x1498) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x1480)) {
                if ((void*)(s + 0x1480)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x1480);
                    *(void**)(s + 0x1488) = 0;
                    if ((void*)(s + 0x1480)) {
                        if (*(void**)(s + 0x1488)) {
                            removeExist__6utListFP10utListNode(0, s + 0x1480);
                            *(void**)(s + 0x1488) = 0;
                        }
                    }
                }
            }
        }
        if ((void*)(s + 0x1448)) {
            *(void**)(s + 0x1478) = lbl_8045C4BC;
            *(void**)(s + 0x1458) = lbl_8045C4BC + 8;
            fn_800FABEC(s + 0x145C, lbl_8045C4BC);
            *(void**)(s + 0x1448) = 0;
            *(char*)(s + 0x1474) = 0;
            if ((void*)(s + 0x145C)) {
                *(void**)(s + 0x1468) = lbl_40_data_182F8;
                fn_800FABEC(s + 0x145C, lbl_40_data_182F8);
                release__14gfFileIOHandleFv(s + 0x146C);
                __dt__14gfFileIOHandleFv(s + 0x146C, -1);
                if ((void*)(s + 0x145C)) {
                    if ((void*)(s + 0x145C)) {
                        removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x145C);
                        *(void**)(s + 0x1464) = 0;
                        if ((void*)(s + 0x145C)) {
                            if (*(void**)(s + 0x1464)) {
                                removeExist__6utListFP10utListNode(0, s + 0x145C);
                                *(void**)(s + 0x1464) = 0;
                            }
                        }
                    }
                }
            }
            if ((void*)(s + 0x144C)) {
                if ((void*)(s + 0x144C)) {
                    removeExist__6utListFP10utListNode(lbl_8049E550, s + 0x144C);
                    *(void**)(s + 0x1454) = 0;
                    if ((void*)(s + 0x144C)) {
                        if (*(void**)(s + 0x1454)) {
                            removeExist__6utListFP10utListNode(0, s + 0x144C);
                            *(void**)(s + 0x1454) = 0;
                        }
                    }
                }
            }
        }
        __destroy_arr(s + 0x1348, fn_40_436B8, 4, 0x33);
        if ((void*)(s + 0x1B4)) {
            void* t = *(void**)(s + 0x1B4);
            if (t) exit__6gfTaskFv(t);
            *(void**)(s + 0x1B4) = 0;
        }
        if (self) fn_800FAEB8(self, 0);
        if (arg > 0) {
            void* p2 = self;
            __dl__FPv(p2);
        }
    }
    return self;
}
