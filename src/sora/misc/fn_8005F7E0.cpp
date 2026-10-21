#pragma force_active on
struct Vec3f { float x,y,z; };
enum EfID { EF_ID_NONE=0 };
class ecMgr { public: int setEffect(EfID, const Vec3f*, const Vec3f*, const Vec3f*); };
extern "C" int fn_8005F814(ecMgr*, EfID, short, const Vec3f*, const Vec3f*, const Vec3f*);
int ecMgr::setEffect(EfID id,const Vec3f* a,const Vec3f* b,const Vec3f* c) {
 return fn_8005F814(this,id,(int)id >> 16,a,b,c);
}