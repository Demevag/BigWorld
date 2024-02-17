#ifndef CONFIG_HPP
#define CONFIG_HPP

#define BUILT_BY_BIGWORLD 1

#if defined(MF_SERVER) && defined(CONSUMER_CLIENT)
#error "The CONSUMER_CLIENT macro should not be used when building the server."
#endif

/**
 * This define is used to control the conditional compilation of features
 * that will be removed from the client builds provided to the public.
 * Examples of these would be the in-game Python console and the Watcher
 * Nub interface.
 *
 * If CONSUMER_CLIENT_BUILD is equal to zero then the array of development
 * features should be compiled in. If CONSUMER_CLIENT_BUILD is equal to one then
 * development and maintenance only features should be excluded.
 */
#ifdef CONSUMER_CLIENT
#define CONSUMER_CLIENT_BUILD 1
#else
#define CONSUMER_CLIENT_BUILD 0
#endif

/**
 * These settings enable have to be manually turned on or off (no matter whether
 * we're compiling the consumer client build or not).
 */
#define ENABLE_RESOURCE_COUNTERS 0
#define ENABLE_CULLING_HUD 0

/**
 * ENABLE_MEMTRACKER turns on all memory allocation debugging features.
 */

#ifdef ENABLE_PROTECTED_ALLOCATOR
#define PROTECTED_ALLOCATOR
#elif defined(ENABLE_MEMTRACKER)
#define FORCE_ENABLE_SLOT_TRACKER 1
#define FORCE_ENABLE_MEMORY_DEBUG 1
#define FORCE_ENABLE_ALLOCATOR_STATISTICS 1
#endif

/**
 * By setting one of the following FORCE_ENABLE_ defines to one then support for
 * the corresponding feature will be compiled in even on a consumer client
 * build.
 */
#ifdef CONSUMER_CLIENT_STATIC
#define FORCE_ENABLE_MSG_LOGGING 1
#define FORCE_ENABLE_DPRINTF 1
#else // CONSUMER_CLIENT_STATIC
#define FORCE_ENABLE_MSG_LOGGING 0
#define FORCE_ENABLE_DPRINTF 0
#endif // CONSUMER_CLIENT_STATIC

#define FORCE_ENABLE_CONSOLES 0
#define FORCE_ENABLE_PYTHON_TELNET_SERVICE 0
#define FORCE_ENABLE_WATCHERS 0
#define FORCE_ENABLE_DOG_WATCHERS 0
#define FORCE_ENABLE_PROFILER 0
#define FORCE_ENABLE_HITCH_DETECTION 0
#define FORCE_ENABLE_GPU_PROFILER 0
#define FORCE_ENABLE_ACTION_QUEUE_DEBUGGER 0
#define FORCE_ENABLE_DRAW_PORTALS 0
#define FORCE_ENABLE_DRAW_SKELETON 0
#define FORCE_ENABLE_CULLING_HUD 0
#define FORCE_ENABLE_DOC_STRINGS 0
#define FORCE_ENABLE_DDS_GENERATION 0
#define FORCE_ENABLED_ASSET_PIPE 0
#define FORCE_ENABLE_FILE_CASE_CHECKING 0
#define FORCE_ENABLE_ENVIRONMENT_SYNC 0
#define FORCE_ENABLE_ENTER_DEBUGGER_MESSAGE 0
#define FORCE_ENABLE_MINI_DUMP 0
#define FORCE_ENABLE_NVIDIA_PERFHUD 0
#define FORCE_ENABLE_STACK_TRACKER 0
#define FORCE_ENABLE_RELOAD_MODEL 0
#define FORCE_ENABLE_UNENCRYPTED_LOGINS 0
#define FORCE_ENABLE_SMARTPOINTER_TRACKING 0
#define FORCE_ENABLE_TRANSFORM_VALIDATION 0
#define FORCE_ENABLE_DEBUG_MESSAGE_FILE_LOG 0
#define FORCE_ENABLE_REFERENCE_COUNT_THREADING_DEBUG 0

///
#define ENABLE_CONSOLES (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_CONSOLES)
#define ENABLE_MSG_LOGGING                                                     \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_MSG_LOGGING || BW_EMBEDDED)
#define ENABLE_DPRINTF                                                         \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DPRINTF || BW_EMBEDDED)
#define ENABLE_PYTHON_TELNET_SERVICE                                           \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_PYTHON_TELNET_SERVICE)
#define ENABLE_WATCHERS (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_WATCHERS)
#define ENABLE_DOG_WATCHERS                                                    \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DOG_WATCHERS)
#define ENABLE_PROFILER                                                        \
    (!defined(__APPLE__) && !defined(__ANDROID__) &&                           \
     (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_PROFILER))
#define ENABLE_HITCH_DETECTION                                                 \
    (!defined(MF_SERVER) && ENABLE_PROFILER && (FORCE_ENABLE_HITCH_DETECTION))
#define ENABLE_GPU_PROFILER                                                    \
    (ENABLE_PROFILER && (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_GPU_PROFILER))
#define ENABLE_PER_CORE_PROFILER (0)
#define ENABLE_NVIDIA_PERFKIT                                                  \
    (ENABLE_GPU_PROFILER && 0) /* Set to 1 if you have PerfKit available */
#define ENABLE_ACTION_QUEUE_DEBUGGER                                           \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_ACTION_QUEUE_DEBUGGER)
#define ENABLE_DRAW_PORTALS                                                    \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DRAW_PORTALS)
#define ENABLE_DRAW_SKELETON                                                   \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DRAW_SKELETON)
// #define ENABLE_CULLING_HUD				(!CONSUMER_CLIENT_BUILD ||
// FORCE_ENABLE_CULLING_HUD)
#define ENABLE_DOC_STRINGS (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DOC_STRINGS)
#define ENABLE_DDS_GENERATION                                                  \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_DDS_GENERATION)
#define ENABLE_ASSET_PIPE                                                      \
    (defined(EDITOR_ENABLED) || defined(_NAVGEN) ||                            \
     (defined(BW_CLIENT) &&                                                    \
      (!CONSUMER_CLIENT_BUILD || FORCE_ENABLED_ASSET_PIPE)))
#define ENABLE_FILE_CASE_CHECKING                                              \
    (!BW_EXPORTER &&                                                           \
     (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_FILE_CASE_CHECKING))
#define ENABLE_ENVIRONMENT_SYNC                                                \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_ENVIRONMENT_SYNC)
#define ENABLE_ENTER_DEBUGGER_MESSAGE                                          \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_ENTER_DEBUGGER_MESSAGE)
#define ENABLE_MINI_DUMP                                                       \
    (defined(_WIN32) && (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_MINI_DUMP))
#define ENABLE_NVIDIA_PERFHUD                                                  \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_NVIDIA_PERFHUD)
#define ENABLE_MEMORY_DEBUG                                                    \
    (!BWCLIENT_AS_PYTHON_MODULE && !BW_EXPORTER &&                             \
     ((!defined(MF_SERVER) && !CONSUMER_CLIENT_BUILD) ||                       \
      FORCE_ENABLE_MEMORY_DEBUG))
#define ENABLE_SMARTPOINTER_TRACKING                                           \
    (ENABLE_MEMORY_DEBUG && FORCE_ENABLE_SMARTPOINTER_TRACKING)
#define ENABLE_STACK_TRACKER                                                   \
    (!BW_EXPORTER &&                                                           \
     (!CONSUMER_CLIENT_BUILD || ENABLE_MEMORY_DEBUG ||                         \
      FORCE_ENABLE_STACK_TRACKER) &&                                           \
     !(defined(_WIN32) && defined(__clang__)))
#define ENABLE_ALLOCATOR_STATISTICS                                            \
    (!BWCLIENT_AS_PYTHON_MODULE && !BW_EXPORTER &&                             \
     ((!defined(MF_SERVER) && !CONSUMER_CLIENT_BUILD) ||                       \
      FORCE_ENABLE_ALLOCATOR_STATISTICS))
#define ENABLE_SLOT_TRACKER (ENABLE_MEMORY_DEBUG || ENABLE_ALLOCATOR_STATISTICS)
#define ENABLE_RELOAD_MODEL                                                    \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_RELOAD_MODEL) && !defined(MF_SERVER)
#define ENABLE_FIXED_SIZED_POOL_ALLOCATOR                                      \
    (defined(_WIN32) || (defined(MF_SERVER) && ENABLE_MEMORY_DEBUG))
#define ENABLE_FIXED_SIZED_POOL_STATISTICS                                     \
    (!CONSUMER_CLIENT_BUILD && ENABLE_FIXED_SIZED_POOL_ALLOCATOR &&            \
     !defined(MF_SERVER))
#define ENABLE_UNENCRYPTED_LOGINS                                              \
    (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_UNENCRYPTED_LOGINS)
#define ENABLE_REFERENCE_COUNT_THREADING_DEBUG                                 \
    (defined(_DEBUG) || FORCE_ENABLE_REFERENCE_COUNT_THREADING_DEBUG)

// Disabled in tools because they have random events which can switch models
// in between update and draw
#define ENABLE_TRANSFORM_VALIDATION                                            \
    defined(BW_CLIENT) &&                                                      \
      (!CONSUMER_CLIENT_BUILD || FORCE_ENABLE_TRANSFORM_VALIDATION)

/**
 *	Target specific restrictions.
 */
#if defined(PLAYSTATION3)
#undef ENABLE_WATCHERS
#define ENABLE_WATCHERS 0
#undef ENABLE_STACK_TRACKER
#define ENABLE_STACK_TRACKER 0
#endif

#if defined(_XBOX360)
#undef ENABLE_STACK_TRACKER
#define ENABLE_STACK_TRACKER 0
#endif

#if defined(__APPLE__) || defined(__ANDROID__)
#undef ENABLE_STACK_TRACKER
#define ENABLE_STACK_TRACKER 0
#undef ENABLE_ALLOCATOR_STATISTICS
#define ENABLE_ALLOCATOR_STATISTICS 0
#undef ENABLE_SLOT_TRACKER
#define ENABLE_SLOT_TRACKER 0
#endif

#if defined(EMSCRIPTEN)
#undef ENABLE_WATCHERS
#define ENABLE_WATCHERS 0
#undef ENABLE_PROFILER
#define ENABLE_PROFILER 0
#undef ENABLE_STACK_TRACKER
#define ENABLE_STACK_TRACKER 0
#endif

#if defined(BWCLIENT_AS_PYTHON_MODULE)
#undef ENABLE_STACK_TRACKER
#define ENABLE_STACK_TRACKER 0
#endif

// Undef anything that was relying on stack tracker
#if !ENABLE_STACK_TRACKER
#undef ENABLE_MEMORY_DEBUG
#define ENABLE_MEMORY_DEBUG 0
#endif

#endif // CONFIG_HPP
