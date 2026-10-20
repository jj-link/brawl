#pragma force_active on
struct Vec3 {
    float x;
    float y;
    float z;
};

extern "C" void fn_27_263954(void* obj, Vec3* pos);
extern "C" void fn_27_26396C(void* obj, float scale);

class grGimmick {
public:
    void processUpdate();
    Vec3 getPos();
    Vec3 getScale();
};

class grYakumono : public grGimmick {
public:
    void processUpdate();
};

void grYakumono::processUpdate() {
    grGimmick::processUpdate();
    if (*(void**)((char*)this + 0x14c) != 0) {
        Vec3 copy;
        copy = getPos();
        fn_27_263954(*(void**)((char*)this + 0x14c), &copy);
        float s = getScale().x;
        fn_27_26396C(*(void**)((char*)this + 0x14c), s);
    }
}
