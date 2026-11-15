#include <types.h>
#include <gf/gf_archive.h>
#include <gf/gf_task.h>
#include <cm/cm_camera_controller.h>
#include <mu/menu.h>
#include <nw4r/g3d/g3d_resfile.h>

#pragma force_active on

extern "C" {
void* fn_800AFBFC(const void*, u32, void*, u32);
void* fn_80015DB4(void*, int, int, int, u16);
void* fn_800B08A8(int);
void fn_1_10BA0(void*);
void fn_1_12C78(void*);
void* fn_2_35B90(void*, void*, void*);
void fn_18_11C4(void*, void*, void*);
void fn_16_3B4(void*, const void*);
void* fn_2_18C30(void*, void*, void*);
void* fn_2_1A3F8(void*, void*, void*, void*, void*);
void* fn_2_1F014(void*, void*, void*, void*, void*, void*);
void* fn_2_25DBC(void*, void*, void*, void*);
void* fn_2_2BCF8(void*, void*, void*, void*);
void* fn_2_2CEC0(void*, void*, void*, void*);
void* fn_2_2ED68(void*, void*, void*, void*, void*, void*);
void* fn_2_17E48(void*, void*, void*, void*);
void fn_80078DAC(void*, s32, s32, s32);
void* __nw__FUlQ25Heaps8HeapType(u32, int);
int fn_1_3BAC();

extern char lbl_1_data_4E94[];
extern char lbl_2_data_1A60[];
extern char lbl_2_data_1BB8[];
extern char lbl_2_data_1C30[];
extern char lbl_2_data_1D60[];
extern char lbl_2_data_1E10[];
extern char lbl_2_data_1EB8[];
extern char lbl_2_data_1F30[];
extern char lbl_2_data_1FF0[];
extern char lbl_2_data_2080[];
extern char lbl_2_data_2148[];
extern char lbl_2_data_2410[];
extern char lbl_2_data_26B0[];
extern char lbl_2_data_2788[];
extern char lbl_2_data_2838[];
extern char lbl_2_data_2BC8[];
extern char lbl_2_data_2C60[];
extern char lbl_2_data_2E00[];
extern char lbl_2_data_3738[];
extern char lbl_2_data_37D0[];
extern char lbl_2_data_3A48[];
extern char lbl_2_data_3AC8[];
extern void* lbl_805A01D8;
}

struct MenuBase {
    char pad[0x668];
};

struct MenuObject : MenuBase {
    virtual void method0();
    virtual void method1(void*, int);
    virtual void method2(void*);
};

struct Renderer {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void add(void*, void*);
};

#define I(p, o) (*(int*)((char*)(p) + (o)))
#define U(p, o) (*(unsigned int*)((char*)(p) + (o)))
#define B(p, o) (*(unsigned char*)((char*)(p) + (o)))
#define H(p, o) (*(unsigned short*)((char*)(p) + (o)))
#define P(p, o) (*(void**)((char*)(p) + (o)))

static inline void* makeFirstMenuObject(char* self) {
    void* first = __nw__FUlQ25Heaps8HeapType(0x674, 0x2A);
    if (first != NULL) {
        fn_18_11C4(first, self + 0x3E0, self + 0x738);
        P(first, 0x668) = lbl_2_data_1E10;
        H(first, 0x640) = 6;
    }
    return first;
}

static inline void* makeSecondMenuObject(char* self) {
    void* second = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (second != NULL) {
        fn_18_11C4(second, self + 0x3E0, self + 0x738);
        P(second, 0x668) = lbl_2_data_1A60;
        H(second, 0x640) = 6;
    }
    return second;
}

static inline void* makeThirdMenuObject(char* self) {
    void* third = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (third != NULL) {
        fn_18_11C4(third, self + 0x3E0, self + 0x738);
        P(third, 0x668) = lbl_2_data_1EB8;
        H(third, 0x640) = 6;
    }
    return third;
}

static inline void* makeFourthMenuObject(char* self) {
    void* fourth = __nw__FUlQ25Heaps8HeapType(0x674, 0x2A);
    if (fourth != NULL) {
        fn_18_11C4(fourth, self + 0x3E0, self + 0x738);
        P(fourth, 0x668) = lbl_2_data_1F30;
        H(fourth, 0x640) = 3;
    }
    return fourth;
}

static inline void* makeFifthMenuObject(char* self) {
    void* fifth = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (fifth != NULL) {
        fn_18_11C4(fifth, self + 0x3E0, self + 0x738);
        P(fifth, 0x668) = lbl_2_data_1BB8;
        H(fifth, 0x640) = 7;
    }
    return fifth;
}

static inline void* makeSixthMenuObject(char* self) {
    void* sixth = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (sixth != NULL) {
        fn_18_11C4(sixth, self + 0x3E0, self + 0x738);
        P(sixth, 0x668) = lbl_2_data_1D60;
        H(sixth, 0x640) = 7;
    }
    return sixth;
}

static inline void* makeSeventhMenuObject(char* self) {
    void* seventh = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (seventh != NULL) {
        fn_18_11C4(seventh, self + 0x3E0, self + 0x738);
        P(seventh, 0x668) = lbl_2_data_1C30;
        H(seventh, 0x640) = 3;
    }
    return seventh;
}

static inline void* makeEighthMenuObject(char* self) {
    void* eighth = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (eighth != NULL) {
        fn_18_11C4(eighth, self + 0x3E0, self + 0x738);
        P(eighth, 0x668) = lbl_2_data_1FF0;
    }
    return eighth;
}

static inline void* makeNinthMenuObject(char* self) {
    void* ninth = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
    if (ninth != NULL) {
        fn_18_11C4(ninth, self + 0x3E0, self + 0x738);
        P(ninth, 0x668) = lbl_2_data_2080;
    }
    return ninth;
}

static inline void* makeSpecialMenuObject(char* self) {
    void* object = __nw__FUlQ25Heaps8HeapType(0x848, 0x2A);
    if (object != NULL) {
        void* r30 = fn_80015DB4(P(self, 0xAC0), 0, 1, 7, 0xFFFE);
        void* r6 = fn_80015DB4(P(self, 0xAC0), 0, 1, 6, 0xFFFE);
        object = fn_2_1F014(object, self + 0x3E0, self + 0x738,
                           r6, r30, P(self, 0xAA4));
    }
    return object;
}

static inline void* makeLastMenuObject(char* self) {
    void* resource;
    void* object = __nw__FUlQ25Heaps8HeapType(0x758, 0x2A);
    if (object != NULL) {
        resource = fn_80015DB4(P(self, 0xAC0), 0, 1, 9, 0xFFFE);
        void* data = ((gfArchive*)P(self, 0xAA4))->getData(
            Data_Type_Misc, 3, 0xFFFE);
        object = fn_2_2ED68(object, self + 0x3E0, self + 0x738,
                           data, resource, self + 0xA9C);
    }
    return object;
}

static inline void attachRendering(char* self) {
    char* entries;
    Renderer* renderer = (Renderer*)P(P(self, 0x7B4), 0x48);
    entries = (char*)P(self, 0x7BC) + 0x64;
    for (int k = 0; k < 3; k++) {
        renderer->add(P(renderer, 0xE4), P(P(entries, 0), 0x10));
        entries += 4;
    }
}

extern "C" void fn_1_11FBC(char* self) {
    if (B(self, 0xAC8) == 0) {
        if (fn_1_3BAC() != 0 && muMenu::isLoadFinishMenuSound()) {
            P(self, 0x7B4) = fn_800AFBFC(lbl_1_data_4E94, 0xD6, P(self, 0xAC0), 0x64);

            int sp8 = 0;
            void* d = ((gfArchive*)P(self, 0xAC0))->getData(
                Data_Type_Misc, 0xD, &sp8, 0xFFFE);
            if (d != NULL) {
                ((gfArchive*)P(self, 0xAA4))->setFileImage(d, sp8, (Heaps::HeapType)0x2A);
            }

            d = ((gfArchive*)P(self, 0xAC0))->getData(
                Data_Type_Misc, 0xE, &sp8, 0xFFFE);
            if (d != NULL) {
                ((gfArchive*)P(self, 0xAA8))->setFileImage(d, sp8, (Heaps::HeapType)0x2A);
            }

            ((CameraController*)P(self, 0x7B0))->changeInput(CameraController::MenuPad);

            {
                unsigned int* base = (unsigned int*)self;
                void** cur = (void**)(self + 0x7C4);
                unsigned int n = 0;
                for (;;) {
                    void* r = ((gfArchive*)P(self, 0xAA4))->getData(
                        Data_Type_Tex, n, 0xFFFE);
                    U(base, 0x7C4) = (u32)r;
                    if (r != NULL) {
                        nw4r::g3d::ResFile::Init(cur);
                    }
                    ++n;
                    ++base;
                    bool more = n < 0x12;
                    ++cur;
                    if (!more) {
                        break;
                    }
                }
            }

            {
                unsigned int n = 0;
                char* base = self;
                char* cur = self + 0x80C;
                while (n < 0xA1) {
                    void* r = ((gfArchive*)P(self, 0xAA4))->getData(
                        Data_Type_Model, n, 0xFFFE);
                    U(base, 0x80C) = (u32)r;
                    if (r != NULL) {
                        nw4r::g3d::ResFile::Init(cur);
                    }
                    n += 1;
                    base += 4;
                    cur += 4;
                }
            }

            void* o;
            P(self, 0xA90) = fn_80015DB4(P(self, 0xAC0), 0, 1, 0, 0xFFFE);
            nw4r::g3d::ResFile::Init(self + 0xA90);
            P(self, 0xA94) = fn_80015DB4(P(self, 0xAC0), 0, 1, 1, 0xFFFE);
            nw4r::g3d::ResFile::Init(self + 0xA94);
            P(self, 0xA98) = fn_80015DB4(P(self, 0xAC0), 0, 1, 2, 0xFFFE);
            nw4r::g3d::ResFile::Init(self + 0xA98);
            void* r27 = fn_80015DB4(P(self, 0xAC0), 0, 1, 3, 0xFFFE);
            P(self, 0xA9C) = fn_80015DB4(P(self, 0xAC0), 0, 1, 4, 0xFFFE);
            nw4r::g3d::ResFile::Init(self + 0xA9C);
            fn_1_10BA0(self);
            fn_1_12C78(self);

            void* obj;
            void* r29 = fn_80015DB4(P(self, 0xAC0), 0, 1, 5, 0xFFFE);
            obj = __nw__FUlQ25Heaps8HeapType(0x84, 0x2A);
            if (obj != NULL) {
                obj = fn_2_35B90(obj, r27, r29);
            }
            ((gfTask*)obj)->init();
            P(self, 0x7BC) = obj;

            void* t = fn_800B08A8(0x2A);
            P(self, 0x7B8) = t;
            P(t, 0x40) = self + 0x3E0;
            I(t, 0x44) = 0xD6;

            P(self, 0x35C) = makeFirstMenuObject(self);
            P(self, 0x364) = makeSecondMenuObject(self);
            P(self, 0x360) = makeThirdMenuObject(self);
            P(self, 0x368) = makeFourthMenuObject(self);
            P(self, 0x36C) = makeFifthMenuObject(self);
            P(self, 0x370) = makeSixthMenuObject(self);
            P(self, 0x374) = makeSeventhMenuObject(self);
            P(self, 0x378) = makeEighthMenuObject(self);
            P(self, 0x37C) = makeNinthMenuObject(self);

            o = __nw__FUlQ25Heaps8HeapType(0x698, 0x2A);
            if (o != NULL) {
                o = fn_2_18C30(o, self + 0x3E0, self + 0x738);
            }
            P(self, 0x380) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x738, 0x2A);
            if (o != NULL) {
                void* r30 = fn_80015DB4(P(self, 0xAC0), 0, 1, 5, 0xFFFE);
                void* r29b = fn_80015DB4(P(self, 0xAC0), 0, 1, 8, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2410;
                P(o, 0x678) = r30;
                fn_16_3B4((char*)o + 0x67C, lbl_2_data_2410);
                P(o, 0x728) = self + 0xA8C;
                P(o, 0x72C) = self + 0xA9C;
                P(o, 0x730) = r29b;
            }
            P(self, 0x384) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x6D8, 0x2A);
            if (o != NULL) {
                void* r7 = fn_80015DB4(P(self, 0xAC0), 0, 1, 7, 0xFFFE);
                o = fn_2_1A3F8(o, self + 0x3E0, self + 0x738, self + 0xA90, r7);
            }
            P(self, 0x38C) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x670, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2148;
            }
            P(self, 0x388) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x678, 0x2A);
            if (o != NULL) {
                void* r6 = ((gfArchive*)P(self, 0xAA4))->getData(
                    Data_Type_Misc, 0, 0xFFFE);
                o = fn_2_17E48(o, self + 0x3E0, self + 0x738, r6);
            }
            P(self, 0x390) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x688, 0x2A);
            if (o != NULL) {
                void* r29c = fn_80015DB4(P(self, 0xAC0), 0, 1, 0xC, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2BC8;
                B(o, 0x679) = 0;
                B(o, 0x67A) = 0;
                B(o, 0x67B) = 0;
                P(o, 0x684) = r29c;
            }
            P(self, 0x394) = o;

            P(self, 0x398) = makeSpecialMenuObject(self);

            o = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_26B0;
                H(o, 0x640) = 3;
            }
            P(self, 0x39C) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x690, 0x2A);
            if (o != NULL) {
                void* r29d = fn_80015DB4(P(self, 0xAC0), 0, 1, 0xB, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2788;
                H(o, 0x640) = 0;
                P(o, 0x68C) = r29d;
            }
            P(self, 0x3A0) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x6B0, 0x2A);
            if (o != NULL) {
                void* r29e = fn_80015DB4(P(self, 0xAC0), 0, 1, 0xA, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2838;
                H(o, 0x640) = 0;
                P(o, 0x684) = r29e;
            }
            P(self, 0x3A4) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x684, 0x2A);
            if (o != NULL) {
                void* r29f = fn_80015DB4(P(self, 0xAC0), 0, 1, 0xC, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2C60;
                B(o, 0x679) = 0;
                B(o, 0x67A) = 0;
                P(o, 0x680) = r29f;
            }
            P(self, 0x3A8) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x6D0, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_2E00;
                I(o, 0x6B0) = 0;
                I(o, 0x6C4) = 0;
            }
            P(self, 0x3AC) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x698, 0x2A);
            if (o != NULL) {
                void* r6 = fn_80015DB4(P(self, 0xAC0), 0, 1, 5, 0xFFFE);
                o = fn_2_25DBC(o, self + 0x3E0, self + 0x738, r6);
            }
            P(self, 0x3B0) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x734, 0x2A);
            if (o != NULL) {
                void* r29g = fn_80015DB4(P(self, 0xAC0), 0, 1, 5, 0xFFFE);
                void* r30 = fn_80015DB4(P(self, 0xAC0), 0, 1, 8, 0xFFFE);
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_3738;
                P(o, 0x678) = r29g;
                fn_16_3B4((char*)o + 0x67C, lbl_2_data_3738);
                P(o, 0x728) = self + 0xA8C;
                P(o, 0x72C) = self + 0xA9C;
                P(o, 0x730) = r30;
            }
            P(self, 0x3B4) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_37D0;
                H(o, 0x640) = 5;
            }
            P(self, 0x3B8) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x694, 0x2A);
            if (o != NULL) {
                void* r6 = ((gfArchive*)P(self, 0xAA4))->getData(
                    Data_Type_Misc, 1, 0xFFFE);
                o = fn_2_2BCF8(o, self + 0x3E0, self + 0x738, r6);
            }
            P(self, 0x3BC) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x684, 0x2A);
            if (o != NULL) {
                void* r6 = ((gfArchive*)P(self, 0xAA4))->getData(
                    Data_Type_Misc, 2, 0xFFFE);
                o = fn_2_2CEC0(o, self + 0x3E0, self + 0x738, r6);
            }
            P(self, 0x3C0) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_3A48;
                H(o, 0x640) = 4;
            }
            P(self, 0x3C4) = o;

            o = __nw__FUlQ25Heaps8HeapType(0x66C, 0x2A);
            if (o != NULL) {
                fn_18_11C4(o, self + 0x3E0, self + 0x738);
                P(o, 0x668) = lbl_2_data_3AC8;
                H(o, 0x640) = 3;
            }
            P(self, 0x3C8) = o;

            P(self, 0x3CC) = makeLastMenuObject(self);

            {
                int n = 0;
                int base = (int)self;
                while (n < 0x1D) {
                    MenuObject* obj3 = (MenuObject*)P((char*)base, 0x35C);
                    obj3->method2(P(self, 0x7BC));
                    n += 1;
                    base += 4;
                }
            }

            attachRendering(self);

            s32 idx = I(self, 0x3D0);
            MenuObject* o2 = (MenuObject*)P(self + idx * 4, 0x35C);
            void* a4 = P(P(self, 0x7B4), 0x48);
            o2->method1(a4, 0x22);

            B(self, 0xAC8) = 1;
            B(self, 0xAAC) = 2;
            fn_80078DAC(lbl_805A01D8, 0x2A, I(self, 0x3DC), 0);
        }
    }
}
