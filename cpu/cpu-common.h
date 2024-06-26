#ifndef _CD_COMMON_H_
#define _CD_COMMON_H_

#include <rpc/rpc.h>
#include <pthread.h>
#include "list.h"

#define CD_SOCKET_PATH "/tmp/cricketd_sock"
#ifndef LOG_LEVEL
    #define LOG_LEVEL LOG_DEBUG
#endif //LOG_LEVEL

typedef struct kernel_info {
    char *name;
    size_t param_size;
    size_t param_num;
    uint16_t *param_offsets;
    uint16_t *param_sizes;
    void *host_fun;
} kernel_info_t;

enum socktype_t {UNIX, TCP, UDP} socktype;
#define INIT_SOCKTYPE enum socktype_t socktype = TCP;

int connection_is_local;
int shm_enabled;
//#define INIT_SOCKTYPE enum socktype_t socktype = UNIX;
#define WITH_API_CNT
//#define WITH_IB


CLIENT *clnt;
list kernel_infos;

// semaphore
pthread_rwlock_t access_sem;

#define FUNC_BEGIN \
    pthread_rwlock_rdlock(&access_sem);

#define FUNC_END \
    pthread_rwlock_unlock(&access_sem);

#endif //_CD_COMMON_H_

