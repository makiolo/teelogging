#ifndef _LOGGERMANAGER_H_
#define _LOGGERMANAGER_H_

#ifndef ROOT_NAME
#define ROOT_NAME "dune"
#endif

#include <format.h>
#include <memory>

namespace spdlog
{
	class logger;
}

namespace dune {

class LOGGER_API ILogger
{
public:
	ILogger() {}
	virtual ~ILogger() {}

	// verbose
	virtual void v(const std::string&) = 0;

	// debug
	virtual void d(const std::string&) = 0;

	// information
	virtual void i(const std::string&) = 0;

	// warning
	virtual void w(const std::string&) = 0;

	// error
	virtual void e(const std::string&) = 0;

	// fatal
	virtual void f(const std::string&) = 0;

	// verbose
	virtual void tv(const std::string&, const std::string&) = 0;

	// debug
	virtual void td(const std::string&, const std::string&) = 0;

	// information
	virtual void ti(const std::string&, const std::string&) = 0;

	// warning
	virtual void tw(const std::string&, const std::string&) = 0;

	// error
	virtual void te(const std::string&, const std::string&) = 0;

	// fatal
	virtual void tf(const std::string&, const std::string&) = 0;
};

class LOGGER_API Logger : public ILogger
{
public:
	Logger();
	virtual ~Logger();

	// verbose
	virtual void v(const std::string&) override final;

	// debug
	virtual void d(const std::string&) override final;

	// information
	virtual void i(const std::string&) override final;

	// warning
	virtual void w(const std::string&) override final;

	// error
	virtual void e(const std::string&) override final;

	// fatal
	virtual void f(const std::string&) override final;

	// verbose
	virtual void tv(const std::string&, const std::string&) override final;

	// debug
	virtual void td(const std::string&, const std::string&) override final;

	// information
	virtual void ti(const std::string&, const std::string&) override final;

	// warning
	virtual void tw(const std::string&, const std::string&) override final;

	// error
	virtual void te(const std::string&, const std::string&) override final;

	// fatal
	virtual void tf(const std::string&, const std::string&) override final;

protected:
	std::shared_ptr<spdlog::logger> _impl_console;
	std::shared_ptr<spdlog::logger> _impl_file;

};

class LOGGER_API LoggerManager
{
private:
	static ILogger* _logger;
public:

	static void registerLogger(ILogger& logger)
	{
		_logger = &logger;
	}

	static void unregisterLogger(ILogger& logger)
	{
		if(&logger == _logger)
		{
			_logger = nullptr;
		}
	}

	static void v(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->v(std::string(buffer));
		}
		else
		{
			printf("[VERBOSE] %s\n", buffer);
		}
	}

	// debug
	static void d(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->d(std::string(buffer));
		}
		else
		{
			printf("[DEBUG] %s\n", buffer);
		}
	}

	// information
	static void i(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->i(std::string(buffer));
		}
		else
		{
			printf("[INFO] %s\n", buffer);
		}
	}

	// warning
	static void w(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->w(std::string(buffer));
		}
		else
		{
			printf("[WARNING] %s\n", buffer);
		}
	}

	// error
	static void e(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->e(std::string(buffer));
		}
		else
		{
			printf("[ERROR] %s\n", buffer);
		}
	}

	// fatal
	static void f(const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->f(std::string(buffer));
		}
		else
		{
			printf("[FATAL] %s\n", buffer);
		}
	}


	static void tv(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->tv(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[VERBOSE] [%s] %s\n", tag, buffer);
		}
	}

	// debug
	static void td(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->td(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[DEBUG] [%s] %s\n", tag, buffer);
		}
	}

	// information
	static void ti(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->ti(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[INFO] [%s] %s\n", tag, buffer);
		}
	}

	// warning
	static void tw(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->tw(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[WARNING] [%s] %s\n", tag, buffer);
		}
	}

	// error
	static void te(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->te(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[ERROR] [%s] %s\n", tag, buffer);
		}
	}

	// fatal
	static void tf(const char* tag, const char* format,...)
	{
		char buffer[BUFSIZ];
		va_list args;
		va_start (args, format);
		vsnprintf (buffer, BUFSIZ, format, args);
		va_end (args);

		if (_logger != 0)
		{
			_logger->tf(std::string(tag), std::string(buffer));
		}
		else
		{
			printf("[FATAL] [%s] %s\n", tag, buffer);
		}
	}
};

class LoggerRegistrator
{
public:
	LoggerRegistrator()
	{
		LoggerManager::registerLogger(get());
	}
	~LoggerRegistrator()
	{
		LoggerManager::unregisterLogger(get());
	}

	dune::Logger& get();
};

}

#endif // _LOGGERMANAGER_H_

