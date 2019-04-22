#ifndef _TEELOGGING_H_
#define _TEELOGGING_H_

#if defined(_WIN32) || defined(WIN32)
#ifdef teelogging_EXPORTS
#define TEELOGGING_API __declspec(dllexport)
#else
#ifndef teelogging_STATIC
#define TEELOGGING_API __declspec(dllimport)
#else
#define TEELOGGING_API
#endif
#endif
#else
#define TEELOGGING_API
#endif

#include <string>
#include <stdarg.h>
#include <memory>
#include <spdlog/spdlog.h>

namespace tl {
	class teelogging_interface;
	class teelogging_impl;
	class teelogging_manager;
	class teelogging_registrator;
}

#include "teelogging_manager.h"

#ifdef ANDROID
	#ifdef _DEBUG
		#define LOGV(...)  ((void)__android_log_print(ANDROID_LOG_VERBOSE, ROOT_NAME, __VA_ARGS__))
		#define LOGD(...)  ((void)__android_log_print(ANDROID_LOG_DEBUG, ROOT_NAME, __VA_ARGS__))
	#else
		#define LOGV(...)
		#define LOGD(...)
	#endif
	#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, ROOT_NAME, __VA_ARGS__))
	#define LOGW(...) ((void)__android_log_print(ANDROID_LOG_WARN, ROOT_NAME, __VA_ARGS__))
	#define LOGE(...) ((void)__android_log_print(ANDROID_LOG_ERROR, ROOT_NAME, __VA_ARGS__))
	#define LOGF(...)  ((void)__android_log_print(ANDROID_LOG_FATAL, ROOT_NAME, __VA_ARGS__))
#else
	#ifdef _DEBUG
		#define LOGV(...) tl::teelogging_manager::v(__VA_ARGS__)
		#define LOGD(...) tl::teelogging_manager::d(__VA_ARGS__)
	#else
		#define LOGV(...)
		#define LOGD(...)
	#endif
	#define  LOGI(...) tl::teelogging_manager::i(__VA_ARGS__)
	#define  LOGW(...) tl::teelogging_manager::w(__VA_ARGS__)
	#define  LOGE(...) tl::teelogging_manager::e(__VA_ARGS__)
	#define  LOGF(...) tl::teelogging_manager::f(__VA_ARGS__)
#endif

#ifdef ANDROID
	#ifdef _DEBUG
		#define LOGV_TAG(tag, ...)  ((void)__android_log_print(ANDROID_LOG_VERBOSE, tag, __VA_ARGS__))
		#define LOGD_TAG(tag, ...)  ((void)__android_log_print(ANDROID_LOG_DEBUG, tag, __VA_ARGS__))
	#else
		#define LOGV_TAG(tag, ...)
		#define LOGD_TAG(tag, ...)
	#endif
	#define LOGI_TAG(tag, ...) ((void)__android_log_print(ANDROID_LOG_INFO, tag, __VA_ARGS__))
	#define LOGW_TAG(tag, ...) ((void)__android_log_print(ANDROID_LOG_WARN, tag, __VA_ARGS__))
	#define LOGE_TAG(tag, ...) ((void)__android_log_print(ANDROID_LOG_ERROR, tag, __VA_ARGS__))
	#define LOGF_TAG(tag, ...)  ((void)__android_log_print(ANDROID_LOG_FATAL, tag, __VA_ARGS__))
#else
	#ifdef _DEBUG
		#define LOGV_TAG(tag, ...) tl::teelogging_manager::tv(tag, __VA_ARGS__)
		#define LOGD_TAG(tag, ...) tl::teelogging_manager::td(tag, __VA_ARGS__)
	#else
		#define LOGV_TAG(tag, ...)
		#define LOGD_TAG(tag, ...)
	#endif
	#define  LOGI_TAG(tag, ...) tl::teelogging_manager::ti(tag, __VA_ARGS__)
	#define  LOGW_TAG(tag, ...) tl::teelogging_manager::tw(tag, __VA_ARGS__)
	#define  LOGE_TAG(tag, ...) tl::teelogging_manager::te(tag, __VA_ARGS__)
	#define  LOGF_TAG(tag, ...) tl::teelogging_manager::tf(tag, __VA_ARGS__)
#endif

#endif // _TEELOGGING_H_

