#pragma force_active on
extern const float lbl_805A4590;
extern const float lbl_805A4594;

typedef void (*Callback)(void*, void*, void*);

inline void invoke(void* a, unsigned int offset, void** b, void** original,
                   unsigned char index)
{
    void* data = (char*)a + offset;
    Callback f = *(Callback*)((char*)*b + index * 0x34 + 0x16B0);
    if (f)
        f(a, data, original);
}

extern "C" void fn_802FF3FC(void* a, void** b)
{
    unsigned char* p = (unsigned char*)a;

    switch (p[0]) {
    case 2:
    case 6:
        invoke(a, 0x20, b, b, p[1]);
        break;
    case 4:
        *(float*)(p + 0x1C) = lbl_805A4590;
        *(float*)(p + 0x2C) = lbl_805A4594;
        *(float*)(p + 0x28) = lbl_805A4594;
        *(float*)(p + 0x24) = lbl_805A4594;
        *(float*)(p + 0x20) = lbl_805A4594;
        invoke(a, 0x30, b, b, p[1]);
        break;
    case 0:
        break;
    case 1:
        return;
    case 3:
        break;
    case 5:
        break;
    default:
        break;
    }
}
