#pragma force_active on
extern "C" {
void __dl__FPv(void*);
void __dt__14snd3DGeneratorFv(void*, int);
void __dt__Q28StSeUtil5SeSeqFv(void*, int);
void fn_77_F54(void*, int);
extern char lbl_77_data_1068[];
}

struct Class77 {
    unsigned char _0[0x3C];
    void* _data;
    unsigned char _4[0x138];
    void* _ptr;
    unsigned char _seSeq[0x94];
    unsigned char _gen[0x40];
};

extern "C" void* fn_77_1B9C(Class77* self, int arg) {
    if (self) {
        void* ptr = self->_ptr;
        self->_data = &lbl_77_data_1068;
        if (ptr) {
            __dl__FPv(ptr);
        }
        self->_ptr = 0;
        __dt__14snd3DGeneratorFv(&self->_gen[0], -1);
        void* pSeq = &self->_seSeq[0];
        if (pSeq) {
            __dt__Q28StSeUtil5SeSeqFv(pSeq, 0);
        }
        fn_77_F54(self, 0);
        if (arg > 0) {
            __dl__FPv(self);
        }
    }
    return self;
}
