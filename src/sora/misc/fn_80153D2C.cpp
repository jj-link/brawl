#pragma force_active on
struct Obj {
    unsigned int m_0;
    unsigned int m_4;
    unsigned int m_8;
    unsigned int m_c;
};
extern "C" unsigned long long fn_80153D2C(int arg0) {
    int p = *(int*)arg0;
    if (p == 0) {
        return 0;
    }
    Obj *o = (Obj*)p;
    return ((unsigned long long)o->m_8 << 32) | o->m_c;
}
