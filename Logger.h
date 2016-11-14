#ifndef _LOGGER_H_
#define _LOGGER_H_

#if defined(_WIN32) || defined(WIN32)
#ifdef Logger_EXPORTS
#define LOGGER_API __declspec(dllexport)
#else
#ifndef Logger_STATIC
#define LOGGER_API __declspec(dllimport)
#else
#define LOGGER_API
#endif
#endif
#else
#define LOGGER_API
#endif

#include <string>
#include <stdarg.h>

namespace dune {
	class ILogger;
	class Logger;
	class LoggerManager;
	class LoggerRegistrator;
}

#include "LoggerManager.h"

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
		#define LOGV(...) dune::LoggerManager::v(__VA_ARGS__)
		#define LOGD(...) dune::LoggerManager::d(__VA_ARGS__)
	#else
		#define LOGV(...)
		#define LOGD(...)
	#endif
	#define  LOGI(...) dune::LoggerManager::i(__VA_ARGS__)
	#define  LOGW(...) dune::LoggerManager::w(__VA_ARGS__)
	#define  LOGE(...) dune::LoggerManager::e(__VA_ARGS__)
	#define  LOGF(...) dune::LoggerManager::f(__VA_ARGS__)
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
		#define LOGV_TAG(tag, ...) dune::LoggerManager::tv(tag, __VA_ARGS__)
		#define LOGD_TAG(tag, ...) dune::LoggerManager::td(tag, __VA_ARGS__)
	#else
		#define LOGV_TAG(tag, ...)
		#define LOGD_TAG(tag, ...)
	#endif
	#define  LOGI_TAG(tag, ...) dune::LoggerManager::ti(tag, __VA_ARGS__)
	#define  LOGW_TAG(tag, ...) dune::LoggerManager::tw(tag, __VA_ARGS__)
	#define  LOGE_TAG(tag, ...) dune::LoggerManager::te(tag, __VA_ARGS__)
	#define  LOGF_TAG(tag, ...) dune::LoggerManager::tf(tag, __VA_ARGS__)
#endif

#endif // _LOGGER_H_

