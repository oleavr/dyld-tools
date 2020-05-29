#ifndef __ROOTLESS_H__
#define __ROOTLESS_H__

#ifdef __cplusplus
extern "C" {
#endif

int rootless_check_trusted(const char* path);
int rootless_check_trusted_fd(int fd);
int rootless_check_trusted_class(const char* path, const char* klass);

#ifdef __cplusplus
}
#endif

#endif
