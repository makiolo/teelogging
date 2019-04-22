#include "teelogging.h"
#include "teelogging_manager.h"



#if defined(__clang__)
#define STATIC_MULTITHREAD static
#elif defined(__GNUC__) || defined(__GNUG__)
#define STATIC_MULTITHREAD static __thread
#elif defined(_MSC_VER)
#define STATIC_MULTITHREAD __declspec(thread) static
#endif

tl::teelogging_impl* tl::teelogging_registrator::get()
{
	STATIC_MULTITHREAD tl::teelogging_impl log;
	return &log;
}



namespace regLogger
{
	tl::teelogging_registrator reg;
}

namespace tl {

teelogging_impl::teelogging_impl()
{
	spdlog::set_pattern("[%l] [%H:%M:%S] [thread %t] %v");

	_impl_console = spdlog::stdout_logger_mt("console");
	_impl_console->set_level(spdlog::level::debug);

	_impl_file = spdlog::rotating_logger_mt("file", "teelogging", 5 * 1024 * 1024, 10);
	_impl_file->set_level(spdlog::level::debug);
}

teelogging_impl::~teelogging_impl()
{

}

void teelogging_impl::v(const std::string& message)
{
	_impl_console->trace(message);
	_impl_file->trace(message);
}

void teelogging_impl::d(const std::string& message)
{
	_impl_console->debug(message);
	_impl_file->debug(message);
}

void teelogging_impl::i(const std::string& message)
{
	_impl_console->info(message);
	_impl_file->info(message);
}

void teelogging_impl::w(const std::string& message)
{
	_impl_console->warn(message);
	_impl_file->warn(message);
}

void teelogging_impl::e(const std::string& message)
{
	_impl_console->error(message);
	_impl_file->error(message);
}

void teelogging_impl::f(const std::string& message)
{
	_impl_console->critical(message);
	_impl_file->critical(message);
}

void teelogging_impl::tv(const std::string& tag, const std::string& message)
{
	_impl_console->trace("<{}> {}", tag, message);
	_impl_file->trace("<{}> {}", tag, message);
}

void teelogging_impl::td(const std::string& tag, const std::string& message)
{
	_impl_console->debug("<{}> {}", tag, message);
	_impl_file->debug("<{}> {}", tag, message);
}

void teelogging_impl::ti(const std::string& tag, const std::string& message)
{
	_impl_console->info("<{}> {}", tag, message);
	_impl_file->info("<{}> {}", tag, message);
}

void teelogging_impl::tw(const std::string& tag, const std::string& message)
{
	_impl_console->warn("<{}> {}", tag, message);
	_impl_file->warn("<{}> {}", tag, message);
}

void teelogging_impl::te(const std::string& tag, const std::string& message)
{
	_impl_console->error("<{}> {}", tag, message);
	_impl_file->error("<{}> {}", tag, message);
}

void teelogging_impl::tf(const std::string& tag, const std::string& message)
{
	_impl_console->critical("<{}> {}", tag, message);
	_impl_file->critical("<{}> {}", tag, message);
}

}

