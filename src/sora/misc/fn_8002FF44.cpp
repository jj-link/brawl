#include <gf/gf_copyefb.h>
#pragma force_active on

extern "C" void fn_801F1564(unsigned short, unsigned short, unsigned short, unsigned short);
extern "C" void fn_801F15C8(unsigned short, unsigned short, int, unsigned char);
extern "C" void fn_801F1E60(void*, unsigned char);

void gfCopyEFBMgr::getEFB(int index) {
    gfCopyEFB* p = &m_copyEFBs[index];
    if (p->m_texBuffer) {
        fn_801F1564(0, 0, *(unsigned short*)&p->_12[0], *(unsigned short*)&p->_12[2]);
        fn_801F15C8(*(unsigned short*)&p->_12[0], *(unsigned short*)&p->_12[2], *(int*)&p->_0[0], 0);
        fn_801F1E60(p->m_texBuffer, 0);
        p->m_isValid = true;
    }
}