#pragma force_active on
typedef unsigned char u8;

struct Vec2f {
    float m_x;
    float m_y;
};

extern "C" const float lbl_126_rodata_8;
extern "C" const float lbl_126_rodata_C;
extern "C" Vec2f& fn_126_8828(Vec2f& dst, const Vec2f& src);

struct ZakoVectorState {
    unsigned int header[2];
    Vec2f first;
    Vec2f second;
    Vec2f third;
    Vec2f fourth;
    Vec2f fifth;
    u8 flag30;
    u8 flag31;
    u8 flag32;
};

extern "C" void fn_126_883C(ZakoVectorState* object) {
    Vec2f zero = {lbl_126_rodata_8, lbl_126_rodata_8};
    Vec2f& fourth = fn_126_8828(object->fourth, zero);
    Vec2f& second = fn_126_8828(object->second, fourth);
    fn_126_8828(object->first, second);

    Vec2f initial = {lbl_126_rodata_C, lbl_126_rodata_C};
    Vec2f& fifth = fn_126_8828(object->fifth, initial);
    fn_126_8828(object->third, fifth);

    object->flag31 = 0;
    object->flag30 = 0;
    object->flag32 = 1;
}
