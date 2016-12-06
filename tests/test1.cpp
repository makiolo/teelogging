#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../teelogging.h"

using namespace tl;
using testing::AtLeast;
using testing::_;

class MockLogger : public teelogging_interface
{
public:
	MockLogger() { ; }
	virtual ~MockLogger() { Die(); }
	MOCK_METHOD0(Die, void());

	MOCK_METHOD1(v, void(const std::string&));
	MOCK_METHOD1(d, void(const std::string&));
	MOCK_METHOD1(i, void(const std::string&));
	MOCK_METHOD1(w, void(const std::string&));
	MOCK_METHOD1(e, void(const std::string&));
	MOCK_METHOD1(f, void(const std::string&));
	MOCK_METHOD2(tv, void(const std::string&, const std::string&));
	MOCK_METHOD2(td, void(const std::string&, const std::string&));
	MOCK_METHOD2(ti, void(const std::string&, const std::string&));
	MOCK_METHOD2(tw, void(const std::string&, const std::string&));
	MOCK_METHOD2(te, void(const std::string&, const std::string&));
	MOCK_METHOD2(tf, void(const std::string&, const std::string&));
};

#ifdef _DEBUG
#define TIMES_DEPEND_COMPILE 1
#else
#define TIMES_DEPEND_COMPILE 0
#endif

class LoggerTest : testing::Test { };

TEST(LoggerTest, Test1)
{
	MockLogger logger;
	teelogging_manager::lock(logger);

	EXPECT_CALL(logger, i(_)).Times(1);
	LOGI("Hello world");

	EXPECT_CALL(logger, w("Hello world")).Times(1);
	LOGW("Hello world");

	EXPECT_CALL(logger, v("Hello 5 world")).Times(TIMES_DEPEND_COMPILE);
	LOGV("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, d("Hello 5 world")).Times(TIMES_DEPEND_COMPILE);
	LOGD("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, i("Hello 5 world")).Times(1);
	LOGI("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, w("Hello 5 world")).Times(1);
	LOGW("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, e("Hello 5 world")).Times(1);
	LOGE("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, f("Hello 5 world")).Times(1);
	LOGF("Hello %d %s", 5, "world");

	EXPECT_CALL(logger, tv(_, "Hello 5 world")).Times(TIMES_DEPEND_COMPILE);
	LOGV_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, td(_, "Hello 5 world")).Times(TIMES_DEPEND_COMPILE);
	LOGD_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, ti(_, "Hello 5 world")).Times(1);
	LOGI_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, tw(_, "Hello 5 world")).Times(1);
	LOGW_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, te(_, "Hello 5 world")).Times(1);
	LOGE_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, tf(_, "Hello 5 world")).Times(1);
	LOGF_TAG("tag", "Hello %d %s", 5, "world");

	EXPECT_CALL(logger, Die());

	teelogging_manager::unlock(logger);
}

