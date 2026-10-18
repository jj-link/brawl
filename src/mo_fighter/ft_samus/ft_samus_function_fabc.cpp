#pragma force_active on
struct Fn94Vec2 {
    float m_x;
    float m_y;
};

struct Fn94Object {
    char pad[0x18];
    float m_x;
    float m_y;
};

extern "C" void fn_94_FABC(Fn94Object* object, const Fn94Vec2* value) {
    object->m_x = value->m_x;
    object->m_y = value->m_y;
}
