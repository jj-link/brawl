#pragma force_active on
extern "C" {
void* fn_801CC2E4();
int fn_801C3ABC(void*, int);
void fn_801CC818(void*, void*);
void* fn_801BE7BC();
void fn_801BE8D0(void*, void*);
void fn_801C4DEC(void*);
void OSLockMutex(void*);
void OSUnlockMutex(void*);
extern const double lbl_805A3588;
extern const float lbl_805A3584;
extern const float lbl_805A3590;
extern const float lbl_805A3580;
}
struct Callback { virtual void slot0(); virtual void slot1(); virtual void call(void*); };
struct Obj {
    unsigned char pad0[0x8c]; unsigned char state8c; unsigned char state8d;
    unsigned char pad8e[6]; float duration; float remainder;
    unsigned char padA0[0x0e]; unsigned char count; unsigned char padAB;
    unsigned short rate; unsigned char padAE[6]; Callback* callback;
    void* slots[16]; unsigned char padF8[0x20]; int tick;
};
extern "C" void fn_801C3D3C(void* p, int arg1) {
    Obj* obj=(Obj*)p; int n=obj->count*obj->rate;
    float f1=(obj->duration*(float)n)/lbl_805A3590;
    if(lbl_805A3584!=f1) {
        float f2=obj->remainder/f1; float f27=(float)arg1;
        while(f2<f27) {
            f27-=f2;
            if(fn_801C3ABC(obj,1)) {
                OSLockMutex((char*)fn_801CC2E4()+0x354);
                int i;
                if(obj->state8d) {
                    i=(int)obj; if(obj!=0) i=(int)obj+0x80;
                    fn_801CC818(fn_801CC2E4(),(void*)i); obj->state8d=0;
                }
                if(obj->state8c) {
                    i=(int)obj; if(obj!=0) i=(int)obj+0x74;
                    fn_801BE8D0(fn_801BE7BC(),(void*)i); obj->state8c=0;
                }
                i = 0;
                char* slot=(char*)obj;
                do {
                    OSLockMutex((char*)fn_801CC2E4()+0x354);
                    void* v;
                    if (i > 15) v = 0;
                    else v = *(void**)(slot+0xB8);
                    if(v==0) {
                        OSUnlockMutex((char*)fn_801CC2E4()+0x354);
                    } else {
                        fn_801C4DEC(v);
                        obj->callback->call(*(void**)(slot+0xB8));
                        *(void**)(slot+0xB8)=0;
                        OSUnlockMutex((char*)fn_801CC2E4()+0x354);
                    }
                    i += 1;
                    slot += 4;
                } while(i < 16);
                OSUnlockMutex((char*)fn_801CC2E4()+0x354); return;
            }
            obj->tick+=1; n=obj->count*obj->rate;
            f1=(obj->duration*(float)n)/lbl_805A3590;
            if(lbl_805A3584==f1) return;
            f2=lbl_805A3580/f1;
        }
        f2 -= f27;
        obj->remainder=f2*f1;
    }
}