#ifndef _TEELOGGING_MANAGER_H_
#define _TEELOGGING_MANAGER_H_

#ifndef ROOT_NAME
#define ROOT_NAME "teelogging"
#endif

namespace spdlog
{
	class logger;
}

namespace tl {

class TEELOGGING_API teelogging_interface
{
public:
	teelogging_interface() {}
	virtual ~teelogging_interface() {}

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

class TEELOGGING_API teelogging_impl : public teelogging_interface
{
public:
	teelogging_impl();
	virtual ~teelogging_impl();

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

class TEELOGGING_API teelogging_manager
{
private:
	static teelogging_interface* _logger;
public:

	static void lock(teelogging_interface& logger)
	{
		_logger = &logger;
	}

	static void unlock(teelogging_interface& logger)
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

class teelogging_registrator
{
public:
	teelogging_registrator()
	{
		teelogging_manager::lock(get());
	}
	~teelogging_registrator()
	{
		teelogging_manager::unlock(get());
	}

	tl::teelogging_impl& get();
};

}

#endif // _TEELOGGING_MANAGER_H_

