#pragma force_active on
extern "C" {
void* getJoint__11grCollisionFUs(void*, unsigned int);
}

extern "C" void fn_53_3EC4(char* self, unsigned int param) {
    char* p = *(char**)(self + 0x1e4);
    if (p) {
        char* col = *(char**)(p + 0x4c);
        if (col) {
            unsigned int i = 0;
            unsigned short count = *(unsigned short*)(col + 0x6);
            for (; i != count; i++) {
                char* joint = (char*)getJoint__11grCollisionFUs(col, i);
                if (joint) {
                    if (param == 1) {
                        *(short*)(joint + 0x52) = 0;
                    } else {
                        *(short*)(joint + 0x52) = 0x6000;
                    }
                }
            }
        }
    }
}
