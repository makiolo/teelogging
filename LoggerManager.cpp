#include "Logger.h"
//
#include "LoggerManager.h"
//
#include <spdlog/spdlog.h>

namespace regLogger
{
	dune::LoggerRegistrator reg;
}

dune::Logger& dune::LoggerRegistrator::get()
{
	static Logger log;
	return log;
}

namespace dune {

ILogger* LoggerManager::_logger = nullptr;

Logger::Logger()
{
	spdlog::set_pattern("[%l] [%H:%M:%S] [thread %t] %v");

	_impl_console = spdlog::stdout_logger_mt("console");
	_impl_console->set_level(spdlog::level::debug);

	_impl_file = spdlog::rotating_logger_mt("file", "dune", 5 * 1024 * 1024, 10);
	_impl_file->set_level(spdlog::level::debug);
}

Logger::~Logger()
{

}

void Logger::v(const std::string& message)
{
	_impl_console->trace(message);
	_impl_file->trace(message);
}

void Logger::d(const std::string& message)
{
	_impl_console->debug(message);
	_impl_file->debug(message);
}

void Logger::i(const std::string& message)
{
	_impl_console->info(message);
	_impl_file->info(message);
}

void Logger::w(const std::string& message)
{
	_impl_console->warn(message);
	_impl_file->warn(message);
}

void Logger::e(const std::string& message)
{
	_impl_console->error(message);
	_impl_file->error(message);
}

void Logger::f(const std::string& message)
{
	_impl_console->critical(message);
	_impl_file->critical(message);
}

void Logger::tv(const std::string& tag, const std::string& message)
{
	_impl_console->trace("<{}> {}", tag, message);
	_impl_file->trace("<{}> {}", tag, message);
}

void Logger::td(const std::string& tag, const std::string& message)
{
	_impl_console->debug("<{}> {}", tag, message);
	_impl_file->debug("<{}> {}", tag, message);
}

void Logger::ti(const std::string& tag, const std::string& message)
{
	_impl_console->info("<{}> {}", tag, message);
	_impl_file->info("<{}> {}", tag, message);
}

void Logger::tw(const std::string& tag, const std::string& message)
{
	_impl_console->warn("<{}> {}", tag, message);
	_impl_file->warn("<{}> {}", tag, message);
}

void Logger::te(const std::string& tag, const std::string& message)
{
	_impl_console->error("<{}> {}", tag, message);
	_impl_file->error("<{}> {}", tag, message);
}

void Logger::tf(const std::string& tag, const std::string& message)
{
	_impl_console->critical("<{}> {}", tag, message);
	_impl_file->critical("<{}> {}", tag, message);
}

}

