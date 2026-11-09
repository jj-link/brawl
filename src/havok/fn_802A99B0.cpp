#pragma force_active on
extern "C" void fn_802FCB14(...);
extern "C" char lbl_80486CA8[];
extern "C" char lbl_80486924[];
struct Vtable_Class_802A99B0 { void* vtable; Vtable_Class_802A99B0() : vtable(lbl_80486CA8) {} };
class Class_802A0DC4 : public Vtable_Class_802A99B0 { public: Class_802A0DC4() {} ~Class_802A0DC4() {} char padding[0x2c]; };
class Class_802A9A5C { public: Class_802A9A5C() {} ~Class_802A9A5C() {} };
class Class_802A99B0 : public Class_802A0DC4 {
public: Class_802A99B0(int, int, int, int); Class_802A9A5C m_30;
};
class Class_802A1FD4 { public: static void operator delete(void* p); };
extern "C" const float lbl_805A3F00;
Class_802A99B0::Class_802A99B0(int a0, int a1, int a2, int a3)
    : Class_802A0DC4(), m_30() {
    char* p = (char*)this;
    *(short*)(p + 6) = 1;
    *(int*)(p + 8) = a3;
    char* sub = p + 0x30;
    *(void**)(sub - 0x30) = lbl_80486924;
    *(char**)(p + 0x30) = sub + 12;
    *(int*)(p + 0x34) = 0;
    *(unsigned int*)(p + 0x38) = 0x80000001;
    *(int*)(p + 0x0C) = *(int*)a2;
    float z = lbl_805A3F00;
    *(float*)(p + 0x1C) = z;
    *(float*)(p + 0x18) = z;
    *(float*)(p + 0x14) = z;
    *(float*)(p + 0x10) = z;
    *(float*)(p + 0x2C) = z;
    *(float*)(p + 0x28) = z;
    *(float*)(p + 0x24) = z;
    *(float*)(p + 0x20) = z;
    ((void (*)(void*))fn_802FCB14)(sub);
}