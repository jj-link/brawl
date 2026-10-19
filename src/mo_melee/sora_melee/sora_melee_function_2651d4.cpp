#pragma force_active on
typedef unsigned long u32;

extern "C" void* fn_27_2637E8(void* obj, u32 a, u32 b, u32 c);

class grYakumono {
public:
    bool enableHit(u32 a, u32 b);
};

bool grYakumono::enableHit(u32 a, u32 b) {
    void* obj = *(void**)((char*)this + 0x14c);
    if (obj == 0) {
        return false;
    }
    fn_27_2637E8(obj, a, 0, b);
    return true;
}
