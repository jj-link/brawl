#pragma force_active on
extern "C" void EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(void*, unsigned long);
extern "C" void fn_8009EF8C(void*, const void*);
extern const float lbl_54_rodata_E8[];

struct Vec {
    float x, y, z;
    void set(const Vec& v) { x = v.x; y = v.y; z = v.z; }
};

struct Data {
    unsigned int id;
    unsigned int pad;
    Vec pos;
};

inline void setPosition(char* cb, const Vec& v) {
    (*(Data**)(cb + 4))->pos.set(v);
}

inline void setRotation(char* cb, float angle) {
    char* data = *(char**)(cb + 4);
    *(float*)(data + 0x20) = lbl_54_rodata_E8[0];
    *(float*)(data + 0x24) = angle;
    *(float*)(data + 0x28) = lbl_54_rodata_E8[0];
}

extern "C" void fn_54_BDAC(void* self)
{
    char* p = (char*)self;
    char* cb = p + 0xd0;
    if (cb != 0) {
        char* model = (char*)(*(void***)(p + 0x44))[0];
        if (model != 0) {
            if (*(int*)(model + 0x11c) == 0) {
                *(int*)(cb + 0xc) = 0;
                *(void**)(model + 0x11c) = cb;
                EnableScnMdlCallbackTiming__Q34nw4r3g3d12ScnMdlSimpleFUl(model, 1);
                *(unsigned short*)(model + 0x122) = **(unsigned int**)(cb + 4);
            }
            Vec* positions = *(Vec**)(p + 0x15c);
            if (positions != 0) {
                setPosition(cb, positions[**(unsigned char**)(p + 0x164)]);
            }
            setRotation(cb, *(float*)(p + 0x180));
            fn_8009EF8C(p + 0x194, *(Vec**)(p + 0x15c) + **(unsigned char**)(p + 0x164));
            *(unsigned int*)(p + 0x19c) &= ~0x1c000000U;
        }
    }
}
