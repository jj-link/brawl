#pragma force_active on
class AnimObj {
public:
    virtual void v0(int arg);
    unsigned short m_flag;
    short m_count;
};

extern "C" void fn_80302B80(void** arg0, void** arg1) {
    for (int i = 0; i < 2; i++) {
        if (arg1[i] != 0) {
            AnimObj* obj = *(AnimObj**)(*(void**)arg0[i]);
            if (obj->m_flag != 0) {
                obj->m_count--;
                if (obj->m_count == 0 && obj != 0) {
                    obj->v0(1);
                }
            }
            *(void**)arg0[i] = arg1[i];
        }
    }
}
