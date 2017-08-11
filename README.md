# teelogging [![npm version](https://badge.fury.io/js/teelogging.svg)](https://badge.fury.io/js/teelogging)
logging to file and screen using basic macros LOGI, LOGD, LOGV, LOGW, LOG and LOGF

Coverage: [![codecov](https://codecov.io/gh/makiolo/teelogging/branch/master/graph/badge.svg)](https://codecov.io/gh/makiolo/teelogging)

gcc 4.9 / clang 3.6: [![Build Status](https://travis-ci.org/makiolo/teelogging.svg?branch=master)](https://travis-ci.org/makiolo/teelogging)

MSVC 2015: [![Build status](https://ci.appveyor.com/api/projects/status/kujt3sg2a1rr1o23?svg=true)](https://ci.appveyor.com/project/makiolo/teelogging)

# basic use

```CPP
#include <teelogging/teelogging.h>

...
{
  LOGI("info level");
  int n = 10;
  LOGE("error %d with printf style", n);
}
´´´
