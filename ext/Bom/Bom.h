#ifndef __BOM_H__
#define __BOM_H__

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct _BOMBom* BOMBom;
typedef struct _BOMFSObject* BOMFSObject;
typedef struct _BOMCopier* BOMCopier;
typedef struct _BOMSystem* BOMSystem;
typedef int BOMObjectType;
typedef unsigned int BOMFSFlags;
typedef int BOMCopierCopyOperation;
typedef int BOMFSObjType;
typedef BOMCopierCopyOperation (*BOMCopyFileStartedHandler)(BOMCopier copier, const char* path, BOMFSObjType type, off_t size);

enum _BOMObjectType
{
  BOMFileType = 1,
  BOMDirectoryType,
};

enum _BOMFSFlags
{
  B_PATHONLY = 0x0000,
};

enum _BOMCopierCopyOperation
{
  BOMCopierContinue,
  BOMCopierSkipFile,
};

BOMBom BOMBomNew(const char* path);
void BOMBomFree(BOMBom bom);
void* BOMBomInsertFSObject(BOMBom bom, BOMFSObject object, bool something);

BOMFSObject BOMFSObjectNew(BOMObjectType type);
void BOMFSObjectFree(BOMFSObject object);
void BOMFSObjectSetFlags(BOMFSObject object, BOMFSFlags flags);
void BOMFSObjectSetPathName(BOMFSObject object, const char* path, bool something);
void BOMFSObjectSetShortName(BOMFSObject object, const char* path, bool something);

BOMCopier BOMCopierNewWithSys(BOMSystem sys);
void BOMCopierFree(BOMCopier copier);

void* BOMCopierUserData(BOMCopier copier);
void BOMCopierSetUserData(BOMCopier copier, void* userData);
void BOMCopierSetCopyFileStartedHandler(BOMCopier copier, BOMCopyFileStartedHandler handler);

void BOMCopierCopy(BOMCopier copier, const char* srcRoot, const char* dstRoot);

BOMSystem BomSys_default();

#ifdef __cplusplus
}
#endif

#endif
