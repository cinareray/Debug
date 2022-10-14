int debug_init(void);
int debug_process(void);
void debug_uninit(void);

#if !defined(STDIN_FILENO)
#define STDIN_FILENO            0
#endif
#if !defined(STDOUT_FILENO)
#define STDOUT_FILENO           1
#endif
#if !defined(STDERR_FILENO)
#define STDERR_FILENO           2
#endif

enum{
	DEBUG_LEVEL_ASSERT 	= 0,
	DEBUG_LEVEL_ERROR	= 1,
	DEBUG_LEVEL_WARNING	= 2,
	DEBUG_LEVEL_INFO	= 3,
	DEBUG_LEVEL_DEBUG	= 4,
	DEBUG_LEVEL_TRACE	= 5,
#define DEBUG_LEVEL_ASSERT  DEBUG_LEVEL_ASSERT
#define DEBUG_LEVEL_ERROR   DEBUG_LEVEL_ERROR
#define DEBUG_LEVEL_WARNING DEBUG_LEVEL_WARNING
#define DEBUG_LEVEL_INFO    DEBUG_LEVEL_INFO
#define DEBUG_LEVEL_DEBUG   DEBUG_LEVEL_DEBUG
#define DEBUG_LEVEL_TRACE   DEBUG_LEVEL_TRACE
};

enum{
	DEBUG_MODULE_DEBUG	= 0,
	DEBUG_MODULE_MAIN	= 1,
	DEBUG_MODULE_GNSS = 2,
	DEBUG_MODULE_VTC	= 3,
	DEBUG_MODULE_GSM	= 4,
	DEBUG_MODULE_SHEHRAZAT = 5,
#define DEBUG_MODULE_DEBUG  DEBUG_MODULE_DEBUG
#define DEBUG_MODULE_MAIN   DEBUG_MODULE_MAIN
#define DEBUG_MODULE_GNSS   DEBUG_MODULE_GNSS
#define DEBUG_MODULE_VTC 		DEBUG_MODULE_VTC
#define DEBUG_MODULE_GSM		DEBUG_MODULE_GSM
#define DEBUG_MODULE_SHEHRAZAT		DEBUG_MODULE_SHEHRAZAT
};

#define debug_assert(...) 	debug_printf(DEBUG_LEVEL_ASSERT,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)
#define debug_error(...) 	debug_printf(DEBUG_LEVEL_ERROR,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)
#define debug_warning(...) 	debug_printf(DEBUG_LEVEL_WARNING,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)
#define debug_info(...) 	debug_printf(DEBUG_LEVEL_INFO,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)
#define debug_debug(...) 	debug_printf(DEBUG_LEVEL_DEBUG,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)
#define debug_trace(...) 	debug_printf(DEBUG_LEVEL_TRACE,DEBUG_MODULE,__FUNCTION__,__FILE__,__LINE__,__VA_ARGS__)

int debug_printf(const int debug_level, const int debug_module, const char* function, const char* file, const int line, const char *format,...);
void debug_level_set(const int level);
