#pragma force_active on
#pragma once

namespace nw4r {
    namespace g3d {
        class ScnMdlSimple {
        public:
            char _pad0[0x120];
            unsigned char m_unk120;

            void EnableScnMdlCallbackTiming(unsigned long flags);
        };

        void ScnMdlSimple::EnableScnMdlCallbackTiming(unsigned long flags) {
            if (flags & 1) {
                m_unk120 |= 1;
            }
            if (flags & 2) {
                m_unk120 |= 2;
            }
            if (flags & 4) {
                m_unk120 |= 4;
            }
        }
    }
}
